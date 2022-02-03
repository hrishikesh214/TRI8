/**
 * @file code.cpp
 * @author PE06 Hrishikesh Vaze
 * @brief Tut3 - knapsack problem (fractional) using greedy approach
 *
 */

#include <iostream>
#include <vector>
#include <algorithm> // for sort

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
    std::vector<int> vec;

public:
    std::vector<int> sort(std::vector<int> _vec)
    {
        vec = _vec;
        sort(0, vec.size() - 1);
        return vec;
    }
    void sort(int p, int r)
    {
        if (p < r)
        {
            int q = random_partition(p, r);
            sort(p, q - 1);
            sort(q + 1, r);
        }
    }

    int partition(int p, int r)
    {
        int pivot, pi, i;
        pi = p;
        pivot = r;
        for (i = p; i < r; i++)
        {
            if (vec[i] < vec[pivot])
            {
                std::swap(vec[i], vec[pi]);
                pi++;
            }
        }
        std::swap(vec[pivot], vec[pi]);
        print(vec);
        return pi;
    }

    int random_partition(int p, int r)
    {
        // int pivot = vec[r];
        int pivot = rand() % (r - p) + p;
        std::swap(vec[pivot], vec[r]);
        std::cout << "pivot index: " << pivot << std::endl;
        return partition(p, r);
    }
};

int main()
{
    using namespace std;

    int choice, n;
    QuickSort qs;
    std::vector<int> x = {7, 8, 2, 3, 1};
    do
    {
        cout << endl
             << "0. exit" << endl
             << "1. Randomised Quick Sort" << endl
             << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            break;
        case 1:
            cout << "Enter number of elements: ";
            cin >> n;
            x.clear();
            cout << endl
                 << "Start entering numbers: ";
            for (int i = 0; i < n; i++)
            {
                int num;
                cin >> num;
                x.push_back(num);
            }
            cout << endl
                 << "Before sorting: ";
            print(x);
            cout << endl;
            x = qs.sort(x);
            cout << endl
                 << "After sorting: ";
            print(x);
            break;
        default:
            cout << "invalid choice!" << endl;
        }
    } while (choice != 0);
    cout << endl;
    return 0;
    return 0;
}