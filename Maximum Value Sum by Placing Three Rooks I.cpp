class Solution {
private:
    // tle
    int m, n;
    unordered_map<int, unordered_map<bitset<100>, long long>> dp; 

    long long backtrack(vector<vector<int>>& board, int rook, int row, bitset<100> bitmask) {
        if (rook == 0) {
            return 0;
        }
        if (row >= m) {
            return INT_MIN;  
        }
       
        if (dp[row].find(bitmask) != dp[row].end()) {
            return dp[row][bitmask];
        }

        long long max_sum = backtrack(board, rook, row + 1, bitmask);
        
        for (int col = 0; col < n; col++) {
            if (!bitmask[col]) {
                int current = board[row][col];
                bitset<100> newBitmask = bitmask;
                newBitmask[col] = 1;
                long long result = current + backtrack(board, rook - 1, row + 1, newBitmask);
                max_sum = max(max_sum, result);
            }
        }
        
        dp[row][bitmask] = max_sum;
        return max_sum;
    }

public:
    long long maximumValueSum(vector<vector<int>>& board) {
        m = board.size();
        if (m == 0) return 0;
        n = board[0].size();
        dp.clear();
        
        return backtrack(board, 3, 0, bitset<100>());
    }
};
