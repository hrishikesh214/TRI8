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

class Knapsack
{
public:
    std::vector<std::pair<int, int>> items; // holding both profit and weight of items

    /**
     * @brief Sets Items
     *
     * @param profits profit array for item
     * @param weights weight array for item
     */
    void setItems(std::vector<int> profits, std::vector<int> weights)
    {
        if (profits.size() != weights.size())
        {
            std::cout << "Error: profits and weights are not of same size" << std::endl;
            return;
        }
        for (int i = 0; i < weights.size(); i++)
        {
            items.push_back(std::make_pair(profits[i], weights[i]));
        }
    }

    /**
     * @brief prints the item vector
     * @param x vector of pairs with same type
     */
    template <typename T>
    void print_items(std::vector<std::pair<T, T>> x = {})
    {
        for (auto item : x)
        {
            std::cout << "(" << item.first << ", " << item.second << ") ";
        }
        std::cout << std::endl;
    }

    void execute(int capacity)
    {
        std::vector<float> ratios, ratio_array; // for displaying purpose

        std::cout << "initial array: ";
        print_items(items);

        // calculating ratio of profit/weight for displaying
        for (auto item : items)
        {
            ratio_array.push_back((float)item.first / (float)item.second);
        }
        std::cout << "ratio array: ";
        print(ratio_array);

        // sort according to ratio of profit/weight
        std::sort(items.begin(), items.end(), [&](const auto &a, const auto &b) -> float
                  { return (float)a.first / a.second > (float)b.first / b.second; });

        std::cout << "sorted array: ";
        print_items(items);

        // start filling bag
        int current_capacity = 0; // for holding current weight
        int current_profit = 0;   // and profit
        int selected = 0;         // for counting selected items

        // iterating through all items
        for (auto item : items)
        {
            // can add item as whole
            if (current_capacity + item.second <= capacity)
            {
                current_capacity += item.second;
                current_profit += item.first;
                selected++;
                ratios.push_back(1);
            }
            // for adding fractional item
            else
            {
                int remaining_capacity = capacity - current_capacity;
                if (remaining_capacity == 0)
                {
                    ratios.push_back(0);
                    continue; // once added continue for displaying 0 in ratio (X array)
                }
                float __ratio = (float)remaining_capacity / item.second;
                float __profit = (float)(item.first * __ratio);
                current_profit += __profit;
                current_capacity += remaining_capacity;
                ratios.push_back(__ratio);
                selected++;
            }
        }
        std::cout << "selected items: " << selected << std::endl
                  << std::endl
                  << "total profit: " << current_profit << std::endl
                  << "X: ";
        print(ratios);
    }
};

int main()
{
    using namespace std;

    int n = 0, choice = 0;
    vector<int> __values, __weights;
    Knapsack ks;

    do
    {
        cout << endl
             << "0. exit" << endl
             << "1. Knapsack Problem" << endl
             << "enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            break;
        case 1:
            __values.clear();
            __weights.clear();
            cout << endl
                 << "enter number of elements: ";
            cin >> n;
            cout << "start entering values of " << n << " items: ";
            for (int i = 0; i < n; i++)
            {
                int num;
                cin >> num;
                __values.push_back(num);
            }
            cout << "start entering weigths of " << n << " items: ";
            for (int i = 0; i < n; i++)
            {
                int num;
                cin >> num;
                __weights.push_back(num);
            }
            ks.setItems(__values, __weights);
            cout << "enter capacity of bag: ";
            cin >> n;
            cout << endl;
            ks.execute(n);
            break;
        default:
            cout << "invalid choice!" << endl;
        }
    } while (choice != 0);
    cout << endl;
    return 0;
}

// 1 5 20 30 66 40 60 10 20 30 40 50 100
