#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool check(string s, string p, int i, int j, vector<vector<int>>& dp) {
        if (i == s.length() && j == p.length())
            return dp[i][j] = 1;
        if (j == p.length())
            return dp[i][j] = 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        bool match = (i < s.length() && (s[i] == p[j] || p[j] == '.'));

        if (j + 1 < p.length() && p[j + 1] == '*') {
            return dp[i][j] = (check(s, p, i, j + 2, dp) || (match && check(s, p, i + 1, j, dp)));
        }

        if (match)
            return dp[i][j] = check(s, p, i + 1, j + 1, dp);

        return dp[i][j] = 0;
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length() + 1, vector<int>(p.length() + 1, -1));
        return check(s, p, 0, 0, dp);
    }
};

int main() {
    Solution sol;
    cout << sol.isMatch("aab", "c*a*b") << endl;
    return 0;
}

//better solution with 0ms runtime 

// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         int n = s.length(), m = p.length();
//         bool up[n+1][m+1];
//         up[0][0] = true;
        
//         for(int i=0; i<=n; i++){
//             for(int j=1; j<=m; j++){
//                 if(p[j-1] == '*'){
//                     up[i][j] = up[i][j-2] || (i > 0 && (s[i-1] == p[j-2] || p[j-2] == '.') && up[i-1][j]);
//                 }
//                 else{
//                     up[i][j] = i > 0 && up[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
//                 }
//             }
//         }
        
//         return up[n][m];
//     }
// };
