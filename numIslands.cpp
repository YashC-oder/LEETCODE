class Solution {
private:
    int row , col;
    void dfs(vector<vector<char>>& grid,int i ,int j){
        if(i >= row || j >= col || i < 0 || j < 0 || grid[i][j] == '0') return;
        grid[i][j] = '0';
        dfs(grid,i,j+1);
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);
        dfs(grid,i-1,j);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        row = grid.size();
        col = grid[0].size();

        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(grid[i][j] == '1'){
                    count++;
                    dfs(grid,i,j);
                }
            }
        }

        return count;
    }
};