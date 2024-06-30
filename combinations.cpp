class Solution {
private:
    int size;

    void combinations(int start, int k, vector<int>& tillNow, vector<vector<int>>& result) {
        if (k == 0) {
            result.push_back(tillNow);
            return;
        }

        for (int i = start; i <= size - k + 1; ++i) {
            tillNow.push_back(i);
            combinations(i + 1, k - 1, tillNow, result);
            tillNow.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> tillNow;
        size = n;
        combinations(1, k, tillNow, result);
        return result;
    }
};
