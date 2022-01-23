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
    std::vector<std::vector<int>> board;            // board for placing the queens
    int n;                                          // size of board
    int count = 1;                                  // count of solutions
    std::vector<std::vector<std::vector<int>>> ans; // final answer

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

    void print_board(std::vector<std::vector<int>> _board = {})
    {
        if (_board.empty())
            _board = board;
        for (int i = 0; i < n; i++)
        {
            print(_board[i]);
        }
    }

    void print_ans()
    {
        for (int i = 0; i < ans.size(); i++)
        {
            std::cout << "Pattern #" << i + 1 << ": " << std::endl;

            print_board(ans[i]);
            std::cout << std::endl;
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
    void solve(int row)
    {
        if (row == n)
            // return true;
            return ans.push_back(board);
        for (int col = 0; col < n; col++)
        {
            if (isOk(row, col))
            {
                board[row][col] = 1;
                // print_board();
                solve(row + 1);
                board[row][col] = 0;
            }
        }
    }

    void execute(int _n)
    {
        setup(_n);
        solve(0);
        print_ans();
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