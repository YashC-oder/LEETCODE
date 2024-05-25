#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Min heap to store {distance, node} pairs
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_distance;
        unordered_map<int, int> min_time;
        unordered_map<int, vector<pair<int, int>>> neighbours;

        // Building the graph
        for (int i = 0; i < times.size(); i++) {
            int source = times[i][0];
            int destination = times[i][1];
            int distance = times[i][2];
            neighbours[source].push_back({destination, distance});
        }

        // Starting with node k and distance 0
        min_distance.push({0, k});

        while (!min_distance.empty()) {
            pair<int, int> node = min_distance.top();
            min_distance.pop();
            
            int curr_dist = node.first;
            int curr_node = node.second;

            // If this node is already visited, continue
            if (min_time.find(curr_node) != min_time.end()) {
                continue;
            }

            // Record the shortest time to reach this node
            min_time[curr_node] = curr_dist;

            // Explore the neighbors
            for (auto& neighbour : neighbours[curr_node]) {
                int next_node = neighbour.first;
                int edge_weight = neighbour.second;

                // If this neighbor hasn't been visited yet
                if (min_time.find(next_node) == min_time.end()) {
                    min_distance.push({curr_dist + edge_weight, next_node});
                }
            }
        }

        // If we couldn't visit all nodes, return -1
        if (min_time.size() != n) {
            return -1;
        }

        // Find the maximum time from the shortest paths to all nodes
        int time = 0;
        for (auto& node : min_time) {
            time = max(time, node.second);
        }

        return time;
    }
};
