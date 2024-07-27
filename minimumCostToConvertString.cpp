class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int size = original.size();
        const int INF = INT_MAX;
        vector<vector<int>> costs(26, vector<int>(26, INF));
        for (int i = 0; i < 26; i++) {
            costs[i][i] = 0;
        }

        for (int i = 0; i < size; i++) {
            costs[original[i] - 'a'][changed[i] - 'a'] = min(costs[original[i] - 'a'][changed[i] - 'a'], cost[i]);
        }

        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (costs[i][k] < INF && costs[k][j] < INF) {
                        costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j]);
                    }
                }
            }
        }

        long long min_cost = 0;

        for (int i = 0; i < source.size(); i++) {
            int current_cost = costs[source[i] - 'a'][target[i] - 'a'];
            if (current_cost == INF) return -1;
            min_cost += current_cost;
        }

        return min_cost;
    }
};
