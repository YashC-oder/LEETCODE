/*Dijkstra's algorithm*/

class Solution {
private:
    void findMinDistance(int node, unordered_map<int, vector<pair<int, int>>>& neighbours, unordered_map<int,int>& cities, int distanceThreshold) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> min_distance;
        unordered_set<int> visited;

        min_distance.push({0,node});

        while(!min_distance.empty()){
            auto [currentDis, currentNode] = min_distance.top();
            min_distance.pop();
            if(visited.find(currentNode) != visited.end()){
                continue;
            }
            visited.insert(currentNode);
            if(currentNode != node){
                if(currentDis <= distanceThreshold){
                    cities[node]++;
                }
            }

            for(auto& neighbour : neighbours[currentNode]){
                auto [next_node, distance] = neighbour;
                if(visited.find(next_node) == visited.end()){
                    min_distance.push({currentDis+distance, next_node});
                }
            }
        }
    }

public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int, int> cities;
        unordered_map<int, vector<pair<int, int>>> neighbours;
        
        for(int i = 0; i < n; i++){
            cities[i] = 0;
        }
        
        for(auto& edge : edges){
            int source = edge[0], destination = edge[1], distance = edge[2];
            neighbours[source].push_back({destination, distance});
            neighbours[destination].push_back({source, distance});
        }

        for(int i = 0; i < n; i++){
            findMinDistance(i, neighbours, cities, distanceThreshold);
        }

        int minCount = INT_MAX;
        int city = -1;

        for(auto& [key, val] : cities){
            if(val < minCount){
                minCount = val;
                city = key;
            } else if(val == minCount){
                city = max(city, key);
            }
        }

        return city;
    }
};

/*Floyd-Warshall algorithm*/

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        
        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }
        
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            dist[u][v] = w;
            dist[v][u] = w; 
        }
        
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] < INT_MAX && dist[k][j] < INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        
        int minReachable = n;
        int resultCity = -1;
        
        for (int i = 0; i < n; ++i) {
            int reachableCount = 0;
            for (int j = 0; j < n; ++j) {
                if (dist[i][j] <= distanceThreshold) {
                    reachableCount++;
                }
            }
            if (reachableCount < minReachable || (reachableCount == minReachable && i > resultCity)) {
                minReachable = reachableCount;
                resultCity = i;
            }
        }
        
        return resultCity;
    }
};
