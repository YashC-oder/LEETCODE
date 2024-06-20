class Solution {
private:
    int row , col;
    int path(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& dp){
        if(i >= row || j >= col || grid[i][j]) return 0;
        int& num = dp[i][j];
        if(num != -1) return num;
        return num = path(grid,i+1,j,dp) + path(grid,i,j+1,dp);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        row = obstacleGrid.size();
        col = obstacleGrid[0].size();
        vector<vector<int>>& dp(row,vector<int>(col,-1));
        dp[row-1][col-1] = 1;

        return path(obstacleGrid,0,0,dp);
    }
};