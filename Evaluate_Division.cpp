#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        vector<double> ans;
        // graph[A][B] := A / B
        unordered_map<string, unordered_map<string, double>> graph;

        // Populate the graph with equations and values
        for (int i = 0; i < equations.size(); ++i) {
            const string& A = equations[i][0];
            const string& B = equations[i][1];
            double val = values[i];
            graph[A][B] = val;
            graph[B][A] = 1.0 / val; // handle the inverse relationship
        }

        // Process each query using DFS to compute the result
        for (const auto& query : queries) {
            const string& start = query[0];
            const string& end = query[1];
            unordered_set<string> visited;
            double result = dfs(graph, start, end, visited);
            ans.push_back(result);
        }

        return ans;
    }

private:
    // DFS to find the result of start / end
    double dfs(const unordered_map<string, unordered_map<string, double>>& graph,
               const string& start, const string& end,
               unordered_set<string>& visited) {
        // If start or end doesn't exist in the graph
        if (!graph.count(start) || !graph.count(end))
            return -1.0;

        // If we reached the end node
        if (start == end)
            return 1.0;

        // Mark the start node as visited
        visited.insert(start);

        // Traverse neighbors of the current node
        for (const auto& neighbor : graph.at(start)) {
            const string& nextNode = neighbor.first;
            double value = neighbor.second;
            if (visited.count(nextNode) == 0) {
                double result = dfs(graph, nextNode, end, visited);
                if (result != -1.0) {
                    // Calculate the result for start / end
                    return value * result;
                }
            }
        }

        // No valid path found from start to end
        return -1.0;
    }
};

int main() {
    Solution sol;
    vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};

    vector<double> result = sol.calcEquation(equations, values, queries);

    // Output the result of each query
    for (double res : result) {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}
