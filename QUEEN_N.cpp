#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int size;
    vector<vector<string>> solutions;

    bool isSafe(int row, int col, vector<vector<string>>& board) {
        // Check row and columns
        for (int i = 0; i < size; ++i)
            if (board[i][col] == "Q" || board[row][i] == "Q") return false;

        // Check diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
            if (board[i][j] == "Q") return false;
        
        for (int i = row, j = col; i < size && j < size; ++i, ++j)
            if (board[i][j] == "Q") return false;

        for (int i = row, j = col; i >= 0 && j < size; --i, ++j)
            if (board[i][j] == "Q") return false;
        
        for (int i = row, j = col; i < size && j>=0; ++i, --j)
            if (board[i][j] == "Q") return false;
        
        return true;
    }

    vector<string> tostring(vector<vector<string>>& board) {
        vector<string> vec;
        for (int i = 0; i < size; ++i) {
            string str = "";
            for (int j = 0; j < size; ++j) {
                str += board[i][j];
            }
            vec.push_back(str);
        }
        return vec;
    }

    void solve(vector<vector<string>>& board, int n, int row = 0) {
        if (n == 0) {
            solutions.push_back(tostring(board));
            return;
        }
        if (row >= size) return;

        // Look for solution
        for (int col = 0; col < size; ++col) {
            if (isSafe(row, col, board)) {
                board[row][col] = "Q";
                solve(board, n - 1, row + 1);
                board[row][col] = ".";
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        size = n;
        vector<vector<string>> board(size, vector<string>(size, "."));
        solve(board, n);
        return solutions;
    }
};

int main() {
    Solution s;
        vector<vector<string>> str = s.solveNQueens(1);
    for (const auto& solution : str) {
        for (const string& row : solution) {
            cout << row << " ";
        }
        cout << endl;
    }
    return 0;
}
