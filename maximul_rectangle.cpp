#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
private:
    int depth(vector<vector<char>>& matrix, int row, int col, vector<vector<int>>& dep) {
        if (dep[row][col] != -1) return dep[row][col];
        if (matrix[row][col] == '0') return dep[row][col] = 0;
        int d = 0;
        for (int i = row; i < matrix.size(); i++) {
            if (matrix[i][col] == '1') d++;
            else break;
        }
        return dep[row][col] = d;
    }

    vector<int> nextMin(vector<vector<char>>& matrix, int row, vector<vector<int>>& dep) {
        int n = matrix[0].size();
        vector<int> next(n, n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && depth(matrix, row, st.top(), dep) > depth(matrix, row, i, dep)) {
                next[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return next;
    }

    vector<int> prevMin(vector<vector<char>>& matrix, int row, vector<vector<int>>& dep) {
        int n = matrix[0].size();
        vector<int> prev(n, -1);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && depth(matrix, row, st.top(), dep) > depth(matrix, row, i, dep)) {
                prev[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return prev;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int max_area = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dep(rows, vector<int>(cols, -1));

        for (int i = 0; i < rows; i++) {
            vector<int> next = nextMin(matrix, i, dep);
            vector<int> prev = prevMin(matrix, i, dep);
            for (int j = 0; j < cols; j++) {
                int d = depth(matrix, i, j, dep);
                int left = prev[j];
                int right = next[j];
                max_area = max(max_area, d * (right - left - 1));
            }
        }
        return max_area;
    }
};

int main() {
    Solution solution;
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    int max_area = solution.maximalRectangle(matrix);
    cout << "Maximal Rectangle Area: " << max_area << endl;
    return 0;
}
