/**
 * @file code.cpp
 * @author PE06 Hrishikesh Vaze
 * @brief Tut5 - N Queen problem using Backtracking approach
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

class NQueen
{
public:
    std::vector<std::vector<int>> board; // board for placing the queens
    int n;                               // size of board
    int count = 1;                       // count of solutions

    /**
     * @brief sets the board size
     * @param _n
     */
    void setup(int _n)
    {
        n = _n;

        board.resize(n);
        // now resize each vector
        for (int i = 0; i < n; i++)
        {
            board[i].clear();
            board[i].resize(n);
        }
    }

    void print_board()
    {
        std::cout << std::endl
                  << "Board #" << count << ": " << std::endl;
        for (int i = 0; i < n; i++)
        {
            print(board[i]);
        }
    }

    /**
     * @brief check weather given points are safe or not
     *
     */
    bool isOk(int row, int col)
    {
        int i, j;

        // check for col
        for (int i = 0; i < row; i++)
        {
            if (board[i][col] == 1)
            {
                return false;
            }
        }

        // check for upper diagonal
        for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 1)
            {
                return false;
            }
        }

        // check for lower diagonal
        for (i = row, j = col; i >= 0 && j < n; i--, j++)
        {
            if (board[i][j] == 1)
            {
                return false;
            }
        }

        return true;
    }

    /**
     * @brief nqueen algo
     *
     */
    bool solve(int row)
    {
        if (row == n)
            return true;
        for (int col = 0; col < n; col++)
        {
            if (isOk(row, col))
            {
                board[row][col] = 1;
                // print_board();
                if (solve(row + 1))
                    return true;
                board[row][col] = 0;
            }
        }
        return false;
    }

    void execute(int _n)
    {
        for (int i = 0; i < n; i++)
        {
            setup(_n);
            board[0][i] = 1;
            if (solve(1))
            {
                print_board();
                count++;
            }
            board[0][i] = 0;
        }
    }
};

int main()
{
    using namespace std;
    NQueen nq;
    int n = 0;

    // first take input
    cout << "Enter no of queens: ";
    cin >> n;

    // execute
    nq.execute(n);

    cout << endl;
    return 0;
}