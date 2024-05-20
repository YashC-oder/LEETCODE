class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minute = -1;
        int row = grid.size();
        int col = grid[0].size();

        queue<pair<int, int>> rotten;
        vector<vector<int>> visited(row, vector<int>(col, 0));

        // Looking for rotten oranges
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 2) {
                    rotten.push({i, j});
                    visited[i][j] = 1; // Mark as visited
                }
            }
        }

        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!rotten.empty()) {
            minute++;
            int length = rotten.size();

            while (length--) {
                int i = rotten.front().first;
                int j = rotten.front().second;
                rotten.pop();

                // Check all four possible directions (up, down, left, right)
                for (const auto& dir : directions) {
                    int ni = i + dir[0];
                    int nj = j + dir[1];

                    // Ensure within bounds and check if the neighbor is a fresh orange
                    if (ni >= 0 && ni < row && nj >= 0 && nj < col && grid[ni][nj] == 1 && !visited[ni][nj]) {
                        visited[ni][nj] = 1; // Mark as visited
                        grid[ni][nj] = 2; // Set to rotten
                        rotten.push({ni, nj});
                    }
                }
            }
        }

        // Check if there are any fresh oranges left
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    return -1; // Still have fresh oranges left
                }
            }
        }

        return (minute == -1) ? 0 : minute; // Return 0 if no oranges were there to begin with
    }
};