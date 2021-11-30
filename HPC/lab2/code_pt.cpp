/**
 * @file code.cpp
 * @author PE06 Hrishikesh Vaze
 * @brief HPC - LAB2 - Simple matrix multiplication without parralellism
 */

#include <iostream>
#include <omp.h>
#include <pthread.h>
#include <iomanip>
using namespace std;

#define MAX_ROWS 500 // max rows of matrix
#define MAX_COLS 100 // max cols of matrix
#define TWIDTH 30    // width of table

double t_start, t_end;               // to store start and end time
int num_cores = omp_get_num_procs(); // no of cpu cores

int mat1[MAX_ROWS][MAX_COLS] = {0}; // matA
int mat2[MAX_ROWS][MAX_COLS] = {0}; // matB
int mat3[MAX_ROWS][MAX_COLS] = {0}; // matC

// serial multiplication
void multiply_matrix_serial(int a[][MAX_COLS], int b[][MAX_COLS], int c[][MAX_COLS], int n)
{
    t_start = omp_get_wtime();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    t_end = omp_get_wtime();
}

// parallel multiplication
void multiply_matrix_parallel(int a[][MAX_COLS], int b[][MAX_COLS], int c[][MAX_COLS], int n)
{
    t_start = omp_get_wtime();

#pragma omp parallel for
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    t_end = omp_get_wtime();
}

string get_time_difference()
{
    return (to_string((t_end - t_start) * 1000) + " ms");
}

void calculate_diff(int n)
{
    int data_points = n * MAX_COLS;
    cout << endl
         << setw(TWIDTH) << data_points;
    // normal serial
    multiply_matrix_serial(mat1, mat2, mat3, n);

    cout << setw(TWIDTH) << get_time_difference();

    // parallel with default cores
    multiply_matrix_parallel(mat1, mat2, mat3, n);
    cout << setw(TWIDTH) << get_time_difference();

    // parallel with all cores
    omp_set_num_threads(num_cores); // use all cores
    multiply_matrix_parallel(mat1, mat2, mat3, n);
    cout << setw(TWIDTH) << get_time_difference();
}

int main()
{
    cout << endl
         << setw(TWIDTH) << "data points" << setw(TWIDTH) << "serial" << setw(TWIDTH) << "parallel (default cores)" << setw(TWIDTH) << "parallel (all cores)";
    for (int i = 10; i < MAX_ROWS; i = i + 10)
    {
        calculate_diff(i);
    }

    cout << endl;
    return 0;
}