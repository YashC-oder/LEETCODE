class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        int size = queries.size();
        vector<int> result(size, 0);
        
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < size; ++i){
            sortedQueries.emplace_back(queries[i], i);
        }  
        sort(sortedQueries.begin(), sortedQueries.end());

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;
        minHeap.emplace(grid[0][0], make_pair(0, 0));

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;

        vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        int count = 0; 
        int index = 0;

        while (index < size) {
            int query = sortedQueries[index].first;
            int resultIndex = sortedQueries[index].second;

            while (!minHeap.empty() && minHeap.top().first < query) {
                auto [val, pos] = minHeap.top();
                minHeap.pop();
                int r = pos.first, c = pos.second;
                count++;

                for (auto [dr, dc] : directions) {
                    int nr = r + dr, nc = c + dc;
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                        visited[nr][nc] = true;
                        minHeap.emplace(grid[nr][nc], make_pair(nr, nc));
                    }
                }
            }
            result[resultIndex] = count;
            index++;
        }

        return result;
    }
};
