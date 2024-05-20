class Solution {
public:
    bool check(string s, string p, int i, int j, vector<vector<int>>& dp) {
        if (i == s.length() && j == p.length()) return dp[i][j] = 1;
        if (j == p.length()) return dp[i][j] = 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (p[j] == '*') {
            if (i == s.length()) return dp[i][j] = check(s, p, i, j + 1, dp); 
            return dp[i][j] = check(s, p, i, j + 1, dp) || check(s, p, i + 1, j, dp);
        }
        if (i < s.length() && (s[i] == p[j] || p[j] == '?')) return dp[i][j] = check(s, p, i + 1, j + 1, dp);
        return dp[i][j] = 0;
    }
    
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length() + 1, vector<int>(p.length() + 1, -1));
        return check(s, p, 0, 0, dp);
    }
};