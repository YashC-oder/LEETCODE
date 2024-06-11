class Solution {
private:
    int row,col;
    int minPath(vector<vector<int>>& triangle,int m ,int n,vector<vector<int>>& dp){
        if(m >= row || n >= col) return 0;

        if(dp[m][n] != -1) return dp[m][n];

        int left = minPath(triangle,m+1,n,dp);
        int right = minPath(triangle,m+1,n+1,dp);

        return dp[m][n] = triangle[m][n] + min(left,right);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        row = triangle.size();
        col = triangle[row-1].size();
        vector<vector<int>> dp(row,vector<int>(col,-1));

        return minPath(triangle,0,0,dp);
    }
};