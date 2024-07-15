class Solution {
private:
    int findMaxProfit(vector<int>& prices, int size, vector<vector<vector<int>>>& dp, int day, int transactions, bool holding) {
        if (day >= size || transactions == 2) return 0; 
        
        int &current = dp[day][transactions][holding];
        if (current != -1) return current;

        int doNothing = findMaxProfit(prices, size, dp, day + 1, transactions, holding);
        int doSomething;

        if (holding) {
            doSomething = prices[day] + findMaxProfit(prices, size, dp, day + 1, transactions + 1, false);
        } else {
            doSomething = -prices[day] + findMaxProfit(prices, size, dp, day + 1, transactions, true);
        }
        
        return current = max(doNothing, doSomething);
    }
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        vector<vector<vector<int>>> dp(size, vector<vector<int>>(3, vector<int>(2, -1)));
        return findMaxProfit(prices, size, dp, 0, 0, false);
    }
};
