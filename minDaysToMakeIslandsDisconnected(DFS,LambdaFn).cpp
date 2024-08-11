class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        function<void(int, int, vector<vector<int>>&)> dfs = [&](int i, int j, vector<vector<int>>& visited) {
            if (i < 0 || j < 0 || i >= row || j >= col || visited[i][j] || grid[i][j] == 0) 
                return;
            
            visited[i][j] = 1;
            vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
            for (auto& direction : directions) {
                int r = i + direction.first;
                int c = j + direction.second;
                dfs(r, c, visited);
            }
        };

        auto countIslands = [&]() -> int {
            vector<vector<int>> visited(row, vector<int>(col, 0));
            int islands = 0;
            
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    if (grid[i][j] == 1 && !visited[i][j]) {
                        islands++;
                        dfs(i, j, visited);
                    }
                }
            }
            return islands;
        };
        
        int initialIslands = countIslands();
        if (initialIslands != 1) return 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;  
                    int islands = countIslands();
                    grid[i][j] = 1;
                    
                    if (islands != 1) return 1;
                }
            }
        }

        return 2;
    }
};
