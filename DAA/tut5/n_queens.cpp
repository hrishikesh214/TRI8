#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> ans;

bool valid(vector<string> &board, int row, int col)
{
    for (int i = row; i >= 0; --i)
        if (board[i][col] == 'Q')
            return false;
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
        if (board[i][j] == 'Q')
            return false;
    for (int i = row, j = col; i >= 0 && j < board.size(); --i, ++j)
        if (board[i][j] == 'Q')
            return false;
    return true;
}
void dfs(vector<string> &board, int row)
{
    if (row == board.size())
    {
        ans.push_back(board);
        return;
    }
    for (int i = 0; i < board.size(); ++i)
    {
        if (valid(board, row, i))
        {
            board[row][i] = 'Q';
            dfs(board, row + 1);
            // back-track
            board[row][i] = '-';
        }
    }
}
vector<vector<string>> solve(int n)
{
    if (n <= 0)
        return {{}};
    vector<string> board(n, string(n, '-'));
    dfs(board, 0);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<string>> final_ans = solve(n);
    cout << "\n";
    for (int i = 0; i < final_ans.size(); i++)
    {
        cout << "Pattern : " << i + 1 << "" << endl;
        cout << endl;
        for (int j = 0; j < final_ans[0].size(); j++)
        {
            string s = final_ans[i][j];
            for (int k = 0; k < s.size(); k++)
            {
                cout << s[k] << " ";
            }
            cout << "\n";
        }
        cout << "\n\n";
    }
}
