/**
 * @file code.cpp
 * @author PE06 Hrishikesh Vaze ()
 * @brief Parralization of Quick sort
 * @date 2021-12-20
 *
 */

#include <iostream>
#include <vector>
#include <omp.h>
#include <pthread.h>
#include <iomanip>
#include <string>
#include <cstring>

typedef std::vector<int> int_vec;
using namespace std;

#define MAX_SIZE 15000 // Maximum size of the array
#define _JUMP 500      // Jump size
#define _START 500     // Start size
#define TWIDTH 25      // width of table
#define NUM_THREADS 8

#define debug(var) cout << #var << " = " << var << endl;

double t_start = 0, t_end = 0;
int *arr = (int *)malloc(MAX_SIZE * sizeof(int));
int *arr_d = (int *)malloc(MAX_SIZE * sizeof(int));

/**
 * @brief Get the time difference
 * @return string
 */
string get_time_difference()
{
    return (to_string((t_end - t_start) * 1000) + " ms");
}

/**
 * @brief prints the item vector
 * @param vec vector of type T
 */
template <typename T>
void print(std::vector<T> vec)
{
    std::cout << "[";
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i];
        if (i != vec.size() - 1)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

class QuickSort
{
public:
    static void execute_serial(int vec[], int p, int r)
    {
        t_start = omp_get_wtime();
        serial_sort(vec, p, r);
        t_end = omp_get_wtime();
    }

    static void serial_sort(int vec[], int p, int r)
    {
        if (p < r)
        {
            int q = serial_partition(vec, p, r);
            serial_sort(vec, p, q - 1);
            serial_sort(vec, q + 1, r);
        }
    }

    static int serial_partition(int vec[], int p, int r)
    {
        int pivot = vec[r];
        int i = p - 1;

        for (int j = p; j <= r - 1; j++)
        {
            if (vec[j] < pivot)
            {
                i++;
                swap(vec[i], vec[j]);
            }
        }
        swap(vec[i + 1], vec[r]);
        return i + 1;
    }

    static void execute_parallel(int vec[], int p, int r)
    {
        t_start = omp_get_wtime();
        parallel_sort(vec, p, r);
        t_end = omp_get_wtime();
    }

    static void parallel_sort(int vec[], int p, int r)
    {
        if (p < r)
        {
            int q = parallel_partition(vec, p, r);
#pragma omp parallel sections private(p, q, r)
            {
#pragma omp section
                {
                    parallel_sort(vec, p, q - 1);
                }
#pragma omp section
                {
                    parallel_sort(vec, q + 1, r);
                }
            }
        }
    }

    static int parallel_partition(int vec[], int p, int r)
    {
        int pivot = vec[r];
        int i = p - 1;

        for (int j = p; j <= r - 1; j++)
        {
            if (vec[j] < pivot)
            {
                i++;
                swap(vec[i], vec[j]);
            }
        }
        swap(vec[i + 1], vec[r]);
        return i + 1;
    }
};

// function to generate random elements in int array
void generate_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % size;
        arr_d[i] = arr[i];
    }
}

void execute(int n)
{
    cout << setw(TWIDTH) << n << " |";
    generate_array(arr, n);

    QuickSort::execute_serial(arr, 0, n - 1);
    cout << setw(TWIDTH) << get_time_difference() << " |";

    QuickSort::execute_parallel(arr_d, 0, n - 1);
    cout << setw(TWIDTH) << get_time_difference() << " |" << endl;
}

int main()
{
    omp_set_num_threads(NUM_THREADS);
    // omp_set_nested(1);
    cout << endl
         << setw(TWIDTH) << "elements" << setw(TWIDTH) << "serial" << setw(TWIDTH) << "parallel" << endl;
    for (int i = _START; i <= MAX_SIZE; i = i + _JUMP)
    {
        execute(i);
    }
    return 0;
}