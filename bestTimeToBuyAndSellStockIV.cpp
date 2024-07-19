class Solution {
private:
    int size;
    int maxTrans;
    
    int findProfit(vector<int>& prices, int day, int Buytransaction, int Selltransaction, bool holding, vector<vector<vector<int>>>& dp) {
        int transaction = Buytransaction + Selltransaction;
        if (day >= size || transaction == maxTrans) 
            return 0;

        int& current = dp[day][transaction][holding];
        if (current != -1) 
            return current;

        int doNothing = findProfit(prices, day + 1, Buytransaction, Selltransaction, holding, dp);
        int doSomething;

        if (holding) {
            // If holding a stock, we can sell it
            doSomething = prices[day] + findProfit(prices, day + 1, Buytransaction, Selltransaction + 1, false, dp);
        } else {
            // If not holding a stock, we can buy it
            doSomething = -prices[day] + findProfit(prices, day + 1, Buytransaction + 1, Selltransaction, true, dp);
        }

        return current = max(doNothing, doSomething);
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        size = prices.size();
        maxTrans = 2 * k;
        vector<vector<vector<int>>> dp(size, vector<vector<int>>(maxTrans + 1, vector<int>(2, -1)));
        return findProfit(prices, 0, 0, 0, false, dp);
    }
};
