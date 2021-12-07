/**
 * @file code.cpp
 * @author PE06 Hrishikesh Vaze ()
 * @brief DAA Tut2 - Merge Sort
 */

#include <iostream>
#include <vector>
#define INFINITE 99999
using namespace std;

// print vector as well as array
template <class T>
void print_vector(T x, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
}

class Solution
{
public:
    vector<int> unsorted_array;
    vector<int> sorted_array;

    Solution *set_array(vector<int> nums)
    {
        unsorted_array = sorted_array = nums;
        return this;
    }

    vector<int> sort()
    {
        merge_sort(0, unsorted_array.size() - 1);
        return sorted_array;
    }

    void merge_sort(int p, int r)
    {
        if (p < r)
        {
            int q = (p + r) / 2;
            merge_sort(p, q);
            merge_sort(q + 1, r);
            merge(p, q, r);
        }
    }
    void merge(int p, int q, int r)
    {
        int i, j, k;
        int x = q - p + 1; // n1
        int y = r - q;     // n2
        int left_array[x + 2], right_array[y + 2];

        // store left and right array in temporary arrays
        for (i = 1; i <= x; i++)
        {
            left_array[i] = sorted_array[p + i - 1];
        }
        for (j = 1; j <= y; j++)
        {
            right_array[j] = sorted_array[q + j];
        }
        left_array[x + 1] = INFINITE;
        right_array[y + 1] = INFINITE;
        i = 1, j = 1;

        for (k = p; k <= r; k++)
        {
            if (left_array[i] <= right_array[j])
            {
                sorted_array[k] = left_array[i];
                i++;
            }
            else
            {
                sorted_array[k] = right_array[j];
                j++;
            }
        }
        print_vector(sorted_array, sorted_array.size());
    }
};

int main()
{
    int num_elements = 0, choice = 0;
    vector<int> nums;
    Solution *s = new Solution();

    do
    {
        cout << endl
             << "0. exit" << endl
             << "1. enter new array" << endl
             << "2. merge sort" << endl
             << "enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            break;
        case 1:
            nums.clear();
            cout << "enter number of elements: ";
            cin >> num_elements;
            cout << "start entering " << num_elements << " elements: ";
            for (int i = 0; i < num_elements; i++)
            {
                int num;
                cin >> num;
                nums.push_back(num);
            }
            break;
        case 2:
            cout << endl
                 << "unsorted array: ";
            print_vector(nums, num_elements);
            s->set_array(nums)->sort();
            cout << "sorted array: " << endl;
            print_vector(s->sorted_array, num_elements);
            break;
        default:
            cout << "invalid choice" << endl;
        }
    } while (choice != 0);
    cout << endl;
    return 0;
}

/*

3 2 5 4 -> 0 , 3 , q = 1

3 2 -> 0,1                  5 4 -> 2,3
p,q,r = 0,0,1
x,y = 1,1

L = 3
R = 2

1st iteration merge

p,q,r -> 0,1,3
x,y -> 2,2

L = 2 3
R = 4 5

*/