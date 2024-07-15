#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int findMaxProfit(vector<int>& prices, int size, vector<vector<int>>& dp, int day, bool holding) {
        if (day >= size) return 0;

        int& current = dp[day][holding];
        if (current != -1) return current;

        int doNothing = findMaxProfit(prices, size, dp, day + 1, holding);
        int doSomething;

        if (holding) {
            doSomething = prices[day] + findMaxProfit(prices, size, dp, day + 1, false);
        } else {
            doSomething = -prices[day] + findMaxProfit(prices, size, dp, day + 1, true);
        }

        return current = max(doNothing, doSomething);
    }
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        vector<vector<int>> dp(size, vector<int>(2, -1));
        return findMaxProfit(prices, size, dp, 0, 0);
    }
};

int main() {
    Solution solution;
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    cout << "Max Profit: " << solution.maxProfit(prices) << endl;
    return 0;
}
