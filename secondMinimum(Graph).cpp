class Solution {
private:
    int nextTime(int currentTime, int change) {
        if ((currentTime / change) % 2) { 
            currentTime = (currentTime / change + 1) * change; 
        }
        return currentTime;
    }
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {

        unordered_map<int, vector<int>> neighbours;
        for (const auto& e : edges) {
            int u = e[0], v = e[1];
            neighbours[u].push_back(v);
            neighbours[v].push_back(u);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, 1});

        vector<int> uniqueVisit(n + 1, 0);
        vector<int> dis(n + 1, -1);
        
        while (!q.empty()) {
            auto [currentTime, node] = q.top();
            q.pop();
            
            if (dis[node] == currentTime || uniqueVisit[node] >= 2) {
                continue;
            }
            
            uniqueVisit[node]++;
            dis[node] = currentTime;
            
            if (node == n && uniqueVisit[node] == 2) {
                return dis[node];
            }
            
            currentTime = nextTime(currentTime, change);
            
            for (int nei : neighbours[node]) {
                q.push({currentTime + time, nei});
            }
        }
        
        return -1;
    }
};
