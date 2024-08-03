#include <vector>
#include <queue>
#include <iostream>
// wrong solution failed at some testcases
using namespace std;

class Solution {
private:
    bool inSideCircle(int x, int y, const vector<vector<int>>& circles) {
        for (const auto& circle : circles) {
            int x_coord = circle[0];
            int y_coord = circle[1];
            int radius = circle[2];
            int x_diff = x - x_coord;
            int y_diff = y - y_coord;
            if ((x_diff * x_diff) + (y_diff * y_diff) <= (radius * radius)) {
                return true;
            }
        }
        return false;
    }

public:
    bool canReachCorner(int X, int Y, const vector<vector<int>>& circles) {
        if (inSideCircle(0, 0, circles) || inSideCircle(X, Y, circles)) {
            return false;
        }

        vector<vector<bool>> visited(X + 1, vector<bool>(Y + 1, false));
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == X && y == Y) {
                return true;
            }

            for (const auto& [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && ny >= 0 && nx <= X && ny <= Y && !visited[nx][ny] && !inSideCircle(nx, ny, circles)) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        return false;
    }
};

int main() {
    Solution sol;
    int X = 13;
    int Y = 5;
    vector<vector<int>> circles = {{3, 1, 1}, {8, 3, 1}, {12, 2, 1}, {6, 4, 1}, {6, 4, 1}, {4, 3, 1}, {5, 4, 1}};
    bool result = sol.canReachCorner(X, Y, circles);
    cout << (result ? "true" : "false") << endl;
    return 0;
}
