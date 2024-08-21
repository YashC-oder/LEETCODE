class Solution {
private:
    int minTurns(string& str, int start, int end, vector<vector<int>>& dp) {
        if (start > end) return 0;
        int& current = dp[start][end];
        if (current != -1) return current;

        current = minTurns(str, start + 1, end, dp) + 1;

        for (int i = start + 1; i <= end; i++) {
            if (str[i] == str[start]) {
                current = min(current, minTurns(str, start + 1, i - 1, dp) + minTurns(str, i, end, dp));
            }
        }

        return current;
    }

public:
    int strangePrinter(string s) {
        string modified = string(1, s[0]);
        for (int i = 1; i < s.size(); i++) {
            if (s[i] != s[i - 1]) {
                modified += s[i];
            }
        }
        vector<vector<int>> dp(modified.size(), vector<int>(modified.size(), -1));
        return minTurns(modified, 0, modified.size() - 1, dp);
    }
};
