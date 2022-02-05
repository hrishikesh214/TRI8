#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <iostream>
#include <numeric>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

__global__ void max(int* input)
{
	const int tid = threadIdx.x; //similar to omp_get_thread_num()
	//we have spawned only one block see line no 46 <<< block, threads per block>>> //blockIdx.x gives block id starting from 0
	int iteration=1;
	auto int step_size = 1;
	int number_of_threads = blockDim.x;

	while (number_of_threads > 0 )
	{
		printf("\n\titeration %d",iteration++);
		if (tid < number_of_threads) // still alive?
		{
			const auto int fst = tid * step_size * 2;
			const auto int snd = fst + step_size;
			if (input[fst] < input[snd])
				input[fst] = input[snd];
			printf("\nComparing and retain max element at arr[%d]= %d and arr[%d] = %d by thread id %d",fst,input[fst],snd,input[snd],tid);
		}

		step_size *= 2; 
		number_of_threads /= 2; 

	}
}

int main()
{
	const auto int count = 8;
	const int size = count * sizeof(int);
	int h[] = {1, 2, 3, 4, 5, 6, 7, 8};//10000

	int* d;
	
	cudaMalloc(&d, size);
	cudaMemcpy(d, h, size, cudaMemcpyHostToDevice);

	max <<<1, count / 2 >>>(d);

	int result;
	cudaMemcpy(&result, d, sizeof(int), cudaMemcpyDeviceToHost);

	cout << "MAX num is " << result << endl;


	cudaFree(d);

	return 0;
}