class Solution {
private:
    bool dfs(vector<vector<char>>& board, int row, int col, string& word, int index, vector<vector<int>>& visited) {
    if (index == word.length()) {
        return true;
    }
    
    if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || visited[row][col] || board[row][col] != word[index]) {
        return false;
    }
    
    visited[row][col] = 1;
    
    bool found = dfs(board, row + 1, col, word, index + 1, visited) ||
                 dfs(board, row - 1, col, word, index + 1, visited) ||
                 dfs(board, row, col + 1, word, index + 1, visited) ||
                 dfs(board, row, col - 1, word, index + 1, visited);
    
    visited[row][col] = 0;
    
    return found;
}

public:
   bool exist(vector<vector<char>>& board, string word) {
    int m = board.size();
    int n = board[0].size();
    vector<vector<int>> visited(m, vector<int>(n, 0));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dfs(board, i, j, word, 0, visited)) {
                return true;
            }
        }
    }
    
    return false;
}

};