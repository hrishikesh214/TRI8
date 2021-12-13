/**
 * @file code.cpp
 * @author PE06 Hrishikesh Vaze
 * @brief HPC - LAB4 - Sum and Product of Large Vectors
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

#define MAX_SIZE 300000 // Maximum size of the array
#define _JUMP_ADD 500   // Jump size for addion execution
#define _JUMP_MUL 10000 // Jump size for multiplication execution
#define NUM_THREADS 4   // maximun threads for parallel
#define TWIDTH 25       // width of table

double t_start = 0, t_end = 0;

/**
 * @brief Get the time difference
 * @return string
 */
string get_time_difference()
{
    return (to_string((t_end - t_start) * 1000) + " ms");
}

class Solution
{
public:
    static void execute_serial_add(int x[], int y[], int z[], int n)
    {
        t_start = omp_get_wtime();
        for (int i = 0; i < n; i++)
        {
            z[i] = x[i] + y[i];
        }
        t_end = omp_get_wtime();
    }

    static void execute_parallel_add(int x[], int y[], int z[], int n)
    {

        t_start = omp_get_wtime();
#pragma omp parallel for
        for (int i = 0; i < n; i++)
        {
            z[i] = x[i] + y[i];
        }
        t_end = omp_get_wtime();
    }

    /*

    x = 1 2 3
    y = 4 5 6

    z = (1*4 + 2*5 + 3*6) = (4+10+18) = 32

    */
    static void execute_serial(int x[], int y[], int z[], int n)
    {
        t_start = omp_get_wtime();
        z[0] = 0;
        for (int i = 0; i < n; i++)
        {
            z[0] += x[i] + y[i];
        }
        t_end = omp_get_wtime();
    }

    static void execute_parallel(int x[], int y[], int z[], int n)
    {

        t_start = omp_get_wtime();
        z[0] = 0;
#pragma omp parallel for
        for (int i = 0; i < n; i++)
        {
            z[0] += x[i] + y[i];
        }
        t_end = omp_get_wtime();
    }
};

// function to generate random elements in int array
void generate_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = (rand() % 100);
    }
}

void execute_add(int x[], int y[], int z[], int n)
{
    memset(z, 0, sizeof(z[0]) * n);
    cout << setw(TWIDTH) << n << " |";
    Solution::execute_serial_add(x, y, z, n);
    cout << setw(TWIDTH) << get_time_difference() << " |";
    Solution::execute_parallel_add(x, y, z, n);
    cout << setw(TWIDTH) << get_time_difference() << " |" << endl;
}

void execute_mul(int x[], int y[], int z[], int n)
{
    memset(z, 0, sizeof(z[0]) * n);
    cout << setw(TWIDTH) << n << " |";
    Solution::execute_serial(x, y, z, n);
    cout << setw(TWIDTH) << get_time_difference() << " |";
    Solution::execute_parallel(x, y, z, n);
    cout << setw(TWIDTH) << get_time_difference() << " |" << endl;
}

int main()
{
    omp_set_num_threads(NUM_THREADS); // set no. of threads

    int x[MAX_SIZE], y[MAX_SIZE], z[MAX_SIZE];
    int n = MAX_SIZE;
    generate_array(x, n);
    generate_array(y, n);

    cout << endl
         << "For Addition: ";
    cout << endl
         << setw(TWIDTH) << "size" << setw(TWIDTH) << "serial" << setw(TWIDTH) << "parallel" << endl
         << endl;
    for (int i = _JUMP_ADD; i <= 10000; i += _JUMP_ADD)
    {
        execute_add(x, y, z, i);
    }

    cout << endl
         << "For Multiplication: ";
    cout << endl
         << setw(TWIDTH) << "size" << setw(TWIDTH) << "serial" << setw(TWIDTH) << "parallel" << endl
         << endl;
    for (int i = _JUMP_MUL; i <= MAX_SIZE; i += _JUMP_MUL)
    {
        execute_mul(x, y, z, i);
    }

    return 0;
}