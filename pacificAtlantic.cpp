class Solution {
private:
struct Coordinate {
    int row;
    int col;
    Coordinate(int r, int c) : row(r), col(c) {}
};

bool canReach(vector<vector<int>>& heights, int startRow, int startCol, vector<vector<int>>& visited) {
    const int rows = heights.size();
    const int cols = heights[0].size();
    
    stack<Coordinate> stack;
    stack.push(Coordinate(startRow, startCol));
    visited[startRow][startCol] = true;
    
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    while (!stack.empty()) {
        Coordinate current = stack.top();
        stack.pop();
        
        for (auto& dir : directions) {
            int nextRow = current.row + dir.first;
            int nextCol = current.col + dir.second;
            
            if (nextRow >= 0 && nextRow < rows && nextCol >= 0 && nextCol < cols &&
                !visited[nextRow][nextCol] && heights[nextRow][nextCol] >= heights[current.row][current.col]) {
                stack.push(Coordinate(nextRow, nextCol));
                visited[nextRow][nextCol] = true;
            }
        }
    }
    
    // Check if we reached the boundary (Pacific or Atlantic)
    return visited[startRow][startCol];
  }
public:
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    const int rows = heights.size();
    const int cols = heights[0].size();
    
    vector<vector<int>> result;
    if (rows == 0 || cols == 0) return result;
    
    vector<vector<int>> canReachPacific(rows, vector<int>(cols, 0));
    vector<vector<int>> canReachAtlantic(rows, vector<int>(cols, 0));
    
    // Check reachability from Pacific (left and top borders)
    for (int i = 0; i < rows; ++i) {
        canReach(heights, i, 0, canReachPacific);
        canReach(heights, i, cols - 1, canReachAtlantic);
    }
    
    for (int j = 0; j < cols; ++j) {
        canReach(heights, 0, j, canReachPacific);
        canReach(heights, rows - 1, j, canReachAtlantic);
    }
    
    // Collect cells that can reach both Pacific and Atlantic
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (canReachPacific[i][j] && canReachAtlantic[i][j]) {
                result.push_back({i, j});
            }
        }
    }
    
    return result;
  }
};