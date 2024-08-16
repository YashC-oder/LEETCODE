class Solution {
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        int size = edges.size() + 1;  
        vector<int> dp(size + 1, -1); 
        unordered_map<int, vector<int>> edge;
        vector<int> parent(size + 1, -1); 

        for (auto& arr : edges) {
            int first = arr[0];
            int second = arr[1];
            edge[first].push_back(second);
            edge[second].push_back(first);
        }

        function<void(int, int)> setParent = [&](int node, int par) {
            parent[node] = par;
            for (const int& child : edge[node]) {
                if (child != par) {
                    setParent(child, node);
                }
            }
        };

        setParent(0, -1);

        function<int(int, int)> countSize = [&](int node, int par) -> int {
            int& current = dp[node];
            if (current != -1) return current;
            int count = 1;
            for (const int& child : edge[node]) {
                if (child != par) {
                    count += countSize(child, node);
                }
            }
            return current = count;
        };

        auto isGood = [&](int node) -> bool {
            int childSize = -1;
            for (const int& child : edge[node]) {
                if (child != parent[node]) {
                    int currentSize = countSize(child, node);
                    if (childSize == -1) {
                        childSize = currentSize;
                    } else if (childSize != currentSize) {
                        return false;
                    }
                }
            }
            return true;
        };

        int count = 0;
        for (int i = 0; i < size; i++) {
            if (isGood(i)) count++;
        }

        return count;
    }
};
