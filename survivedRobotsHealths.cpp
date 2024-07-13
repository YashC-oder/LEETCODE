class Solution {
private:
    void customSort(vector<pair<int, pair<int, char>>>& arr1, vector<int>& arr2, int n) {
        vector<int> indices(n);
        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }

        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return arr2[a] < arr2[b];
        });

        vector<pair<int, pair<int, char>>> sortedArr1(n);
        for (int i = 0; i < n; i++) {
            sortedArr1[i] = arr1[indices[i]];
        }

        for (int i = 0; i < n; i++) {
            arr1[i] = sortedArr1[i];
        }
    }

public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int size = positions.size();
        if (size == 1) return healths;

        vector<pair<int, pair<int, char>>> robots;

        for (int i = 0; i < size; i++) {
            int health = healths[i];
            char direction = directions[i];
            robots.push_back({i, {health, direction}});
        }

        customSort(robots, positions, size);

        stack<pair<int, int>> st;
        vector<bool> survived(size, false);

        for (int i = 0; i < size; i++) {
            auto [index, info] = robots[i];
            auto [currHealth, currDirection] = info;
            if (currDirection == 'R') {
                st.push({currHealth, index});
            } else {
                while (!st.empty() && currHealth > 0) {
                    auto [topHealth, topIndex] = st.top();
                    st.pop();
                    if (currHealth == topHealth) {
                        currHealth = 0;
                    } else if (currHealth > topHealth) {
                        currHealth--;
                    } else {
                        topHealth--;
                        st.push({topHealth, topIndex});
                        currHealth = 0;
                    }
                }
                if (currHealth > 0) {
                    survived[index] = true;
                    healths[index] = currHealth;
                }
            }
        }

        while (!st.empty()) {
            auto [topHealth, topIndex] = st.top();
            st.pop();
            survived[topIndex] = true;
            healths[topIndex] = topHealth;
        }

        vector<int> result;
        for (int i = 0; i < size; i++) {
            if (survived[i]) {
                result.push_back(healths[i]);
            }
        }

        return result;
    }
};