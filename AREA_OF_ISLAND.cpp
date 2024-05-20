class Solution {
public:
    int dfs(vector<vector<int>>& grid ,int row,int col){
        if(row >= grid.size() || col >= grid[0].size() || row < 0 || col < 0 || grid[row][col] == 0) return 0;
        
        grid[row][col] = 0;

        return 1 + dfs(grid,row-1,col) + dfs(grid,row+1,col) + dfs(grid,row,col-1) + dfs(grid,row,col+1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        int row = grid.size();
        int col = grid[0].size();
        for(int i = 0; i<row ;i++){
            for(int j = 0; j<col ;j++){
                if(grid[i][j])
                max_area += max( dfs(grid,i,j) , max_area );
            }
        }
        return max_area;
    }
};