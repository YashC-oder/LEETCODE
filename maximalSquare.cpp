class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;

        int row = matrix.size();
        int col = matrix[0].size();
        int max_side = 0;

        vector<vector<int>> dp(row, vector<int>(col, 0));

        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(matrix[i][j] == '1') {
                    if(i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                    }
                    max_side = max(max_side, dp[i][j]);
                }
            }
        }

        return max_side * max_side;
    }
};
