/**
 * @file code.cpp
 * @author PE06 Hrishikesh Vaze
 * @brief HPC - LAB2 - Simple matrix multiplication OMP
 */

#include <iostream>
#include <omp.h>
#include <pthread.h>
#include <iomanip>
#include <cstring> // for memset
#include <string>
using namespace std;

#define MAX_ROWS 500 // max rows of matrix
#define MAX_COLS 500 // max cols of matrix
#define TWIDTH 25    // width of table

double t_start, t_end;               // to store start and end time
int num_cores = omp_get_num_procs(); // no of cpu cores

string get_time_difference()
{
    return (to_string((t_end - t_start) * 1000) + " ms");
}

class Solution
{
public:
    int mat1[MAX_ROWS][MAX_COLS]; // matA
    int mat2[MAX_ROWS][MAX_COLS]; // matB
    int mat3[MAX_ROWS][MAX_COLS]; // matC

    Solution()
    {
        clear();
    }

    void clear()
    {
        // initialize all matrix to a value 0 for simplicity
        // all matrix element are 0
        memset(mat1, 0, sizeof(mat1[0][0]) * MAX_ROWS * MAX_COLS);
        memset(mat2, 0, sizeof(mat2[0][0]) * MAX_ROWS * MAX_COLS);
        memset(mat3, 0, sizeof(mat3[0][0]) * MAX_ROWS * MAX_COLS);
    }

    // serial multiplication
    void multiply_matrix_serial(int n)
    {
        t_start = omp_get_wtime();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mat3[i][j] = 0;
                for (int k = 0; k < n; k++)
                {
                    mat3[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }
        t_end = omp_get_wtime();
    }

    // parallel multiplication
    void multiply_matrix_parallel(int n)
    {
        t_start = omp_get_wtime();

#pragma omp parallel for
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mat3[i][j] = 0;
                for (int k = 0; k < n; k++)
                {
                    mat3[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }
        t_end = omp_get_wtime();
    }
};

void calculate_diff(int n)
{
    int data_points = n * n;
    Solution ans;
    cout << endl
         << "| " << setw(TWIDTH) << data_points << " |";
    // normal serial
    ans.multiply_matrix_serial(n);

    cout << setw(TWIDTH) << get_time_difference() << " |";

    // parallel with default cores
    ans.multiply_matrix_parallel(n);
    cout << setw(TWIDTH) << get_time_difference() << " |";

    // parallel with all cores
    omp_set_num_threads(num_cores); // use all cores
    ans.multiply_matrix_parallel(n);
    cout << setw(TWIDTH) << get_time_difference() << " |";
}

int main()
{
    cout << endl
         << setw(TWIDTH) << "data points" << setw(TWIDTH) << "serial" << setw(TWIDTH) << "parallel" << setw(TWIDTH) << "all cores";
    for (int i = 10; i < 1000; i = i + 10)
    {
        calculate_diff(i);
    }

    cout << endl;
    return 0;
}