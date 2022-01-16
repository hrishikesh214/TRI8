/**
 * @file code.cpp
 * @author PE06 Hrishikesh Vaze
 * @brief HPC - LAB3 - Bubble Sort OMP
 */

#include <iostream>
#include <vector>
#include <omp.h>
#include <pthread.h>
#include <iomanip>
#include <string>

typedef std::vector<int> int_vec;
using namespace std;

#define TWIDTH 25 // width of table

double t_start = 0, t_end = 0;

/**
 * @brief Get the time difference
 * @return string
 */
string get_time_difference()
{
    return (to_string((t_end - t_start) * 1000) + " ms");
}

class BubbleSort
{
public:
    int_vec arr_for_serial;
    int_vec arr_for_parallel;
    BubbleSort()
    {
        clear();
    }
    void set_arr(int_vec arr)
    {
        arr_for_serial = arr_for_parallel = arr;
    }
    void clear()
    {
        arr_for_serial.clear();
        arr_for_parallel.clear();
    }
    /**
     * @brief sorts array in serial or normal way
     *
     */
    void execute_serial()
    {
        t_start = omp_get_wtime();
        for (int i = 0; i < arr_for_serial.size(); i++)
        {
            for (int j = 0; j < arr_for_serial.size() - 1; j++)
            {
                if (arr_for_serial[j] > arr_for_serial[j + 1])
                {
                    swap(arr_for_serial[j], arr_for_serial[j + 1]);
                }
            }
        }
        t_end = omp_get_wtime();
    }

    /**
     * @brief sorts array in parallel way
     *
     */
    void execute_parallel()
    {
        t_start = omp_get_wtime();

        int n = arr_for_parallel.size();
        for (int i = 0; i < n; i++)
        {
            int first = i % 2;

#pragma omp parallel for default(none) shared(arr_for_parallel, first, n)
            for (int j = first; j < n - 1; j = j + 2)
            {
                if (arr_for_parallel[j] > arr_for_parallel[j + 1])
                {
                    swap(arr_for_parallel[j], arr_for_parallel[j + 1]);
                }
            }
        }
        t_end = omp_get_wtime();
    }
};

// executes sort in both manner for given no. of datapoints
void execute(int dp)
{
    int_vec x;
    x.resize(dp);

    // generate random int array
    for (int i = 0; i < dp; i++)
    {
        x[i] = rand() % dp;
    }

    BubbleSort bs;
    bs.set_arr(x);
    cout << setw(TWIDTH) << dp << " |";
    bs.execute_serial();
    cout << setw(TWIDTH) << get_time_difference() << " |";
    bs.execute_parallel();
    cout << setw(TWIDTH) << get_time_difference() << " |" << endl;
}

int main()
{

    cout << endl
         << setw(TWIDTH) << "data points" << setw(TWIDTH) << "serial" << setw(TWIDTH) << "parallel" << endl;
    for (int i = 500; i <= 2000; i = i + 100)
    {
        execute(i);
    }
    return 0;
}