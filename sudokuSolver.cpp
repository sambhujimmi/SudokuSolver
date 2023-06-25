#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board)
    {
        printBoard(board);

        vector<vector<int>> empty;

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    empty.push_back({ i, j });
                }
            }
        }

        for (int i = 0; i < empty.size(); ++i)
        {
            int r = empty[i][0];
            int c = empty[i][1];
            char start;
            if (board[r][c] == '.') start = '1';
            else if (board[r][c] == '9')
            {
                board[r][c] = '.';
                i -= 2;
                continue;
            }
            else start = board[r][c] + 1;
            for (char k = start; k <= '9'; k++)
            {
                if (check(board, r, c, k))
                {
                    board[r][c] = k;
                    break;
                }
                else if (k == '9')
                {
                    board[r][c] = '.';
                    i -= 2;
                }
            }
        }

        printBoard(board);
    }

private:
    void printBoard(vector<vector<char>>& board)
    {
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                cout << board[i][j] << "\t";
            }
            cout << "\n";
        }
    }
    bool check(vector<vector<char>>& board, int row, int col, char val)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == val || board[row][i] == val) return false;
        }

        int boxr = (row / 3) * 3;
        int boxc = (col / 3) * 3;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[boxr + i][boxc + j] == val) return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sudoku;
    vector<vector<char>> board{ {'5', '3', '.', '.', '7', '.', '.', '.', '.'} ,
                                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                {'.', '.', '.', '.', '8', '.', '.', '7', '9'} };
    sudoku.solveSudoku(board);
        return 0;
}
