/**
 * @file code.cpp
 * @author PE06 Hrishikesh Vaze
 * @brief HPC - LAB2 - Simple matrix multiplication without parralellism
 */

#include <iostream>
using namespace std;

void print_matrix(int a[][3], int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void multiply_matrix(int a[][3], int b[][3], int c[][3], int n)
{
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
}

int main()
{
    int mat1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int mat2[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int mat3[3][3] = {0};

    print_matrix(mat1, 3);
    print_matrix(mat2, 3);

    multiply_matrix(mat1, mat2, mat3, 3);

    print_matrix(mat3, 3);
    cout << endl;
    return 0;
}