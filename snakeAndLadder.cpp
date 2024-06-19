class Solution {
private:
    int size;
    
    pair<int, int> index(int position) {
        int row = size - 1 - (position - 1) / size;
        int col = (position - 1) % size;
        if ((size - 1 - row) % 2 == 1) {
            col = size - 1 - col;
        }
        return {row, col};
    }

public:
    int snakesAndLadders(vector<vector<int>>& board) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        size = board.size();
        vector<int> visited(size * size + 1, 0);
        queue<pair<int, int>> q;
        q.push({1, 0});
        visited[1] = 1;

        while (!q.empty()) {
            auto [position, moves] = q.front();
            q.pop();

            if (position == size * size) {
                return moves;
            }

            for (int i = 1; i <= 6 && position + i <= size * size; ++i) {
                int nextPosition = position + i;
                auto [row, col] = index(nextPosition);
                if (board[row][col] != -1) {
                    nextPosition = board[row][col];
                }
                if (!visited[nextPosition]) {
                    visited[nextPosition] = 1;
                    q.push({nextPosition, moves + 1});
                }
            }
        }

        return -1;
    }
};
