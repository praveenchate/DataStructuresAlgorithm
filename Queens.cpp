#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void printVector(vector<vector<char>> board)
{
    int n = board.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(vector<vector<char>> &board, int row, int col)
{
    int n = board.size();

    // Horizontal check -row is common
    for (int j = 0; j < n; j++)
    {
        if (board[row][j] == 'Q')
        {
            return false;
        }
    }

    // Vertical check -col is common
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 'Q')
        {
            return false;
        }
    }

    // left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }

    // right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }
    return true;
}
// to return the count
//  int nQueens(vector<vector<char>> &board, int row)
//  {
//      int n = board.size();
//      // Base case
//      if (row == n)
//      {
//          printVector(board);
//          cout << "---------------------------------" << endl;
//          return 1;
//      }
//      int count = 0;
//      // columns iteration
//      for (int j = 0; j < n; j++)
//      {
//          if (isSafe(board, row, j))
//          {
//              board[row][j] = 'Q';

//             count += nQueens(board, row + 1);
//             // Now to clear the board
//             board[row][j] = '.';
//         }
//     }
//     return count;
// }

void nQueens(vector<vector<char>> &board, int row)
{
    int n = board.size();
    // Base case
    if (row == n)
    {
        printVector(board);
        cout << "---------------------------------" << endl;
        return;
    }
    // columns iteration
    for (int j = 0; j < n; j++)
    {
        if (isSafe(board, row, j))
        {
            board[row][j] = 'Q';

            nQueens(board, row + 1);
            // Now to clear the board
            board[row][j] = '.';
        }
    }
}

int gridWays(int r, int c, int n, int m, string ans)
{
    // 2 base cases are present
    // Base Case1
    if (r == n - 1 && c == m - 1)
    {
        cout << ans << endl;
        return 1;
    }
    // Base Case2
    if (r >= n || c >= m)
    {
        return 0;
    }

    // going right
    int way1 = gridWays(r, c + 1, n, m, ans + "R");

    // going down
    int way2 = gridWays(r + 1, c, n, m, ans + "D");

    return way1 + way2;
}

int main()
{
    // vector<vector<char>> board;
    // int n = 4;
    // for (int i = 0; i < n; i++)
    // {
    //     vector<char> newRow;
    //     for (int j = 0; j < n; j++)
    //     {
    //         newRow.push_back('.');
    //     }
    //     board.push_back(newRow);
    // }
    // // printVector(board);
    // cout << "----------------------------------" << endl;
    // nQueens(board, 0);
    // // cout << "Count: " << count;
    int n = 3;
    int m = 3;
    string ans = "";
    cout << gridWays(0, 0, n, m, ans) << endl;
}
