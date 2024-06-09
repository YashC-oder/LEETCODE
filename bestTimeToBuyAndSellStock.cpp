class Solution {
private:
    size_t size;
    
    int maxProfitHelper(vector<int>& prices, vector<vector<int>>& dp, int day, int holding) {
        if (day >= size) return 0;
        if (dp[day][holding] != -1) return dp[day][holding];
        
        int doNothing = maxProfitHelper(prices, dp, day + 1, holding);
        int doSomething;
        
        if (holding) {
            doSomething = prices[day] + maxProfitHelper(prices, dp, day + 1, 0);
        } else {
            doSomething = -prices[day] + maxProfitHelper(prices, dp, day + 1, 1);
        }
        
        dp[day][holding] = max(doNothing, doSomething);
        return dp[day][holding];
    }

public:
    int maxProfit(vector<int>& prices) {
        size = prices.size();
        vector<vector<int>> dp(size, vector<int>(2, -1));
        return maxProfitHelper(prices, dp, 0, 0);
    }
};


// 0ms
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int profit=0;
        int min_till_now = INT_MAX;
        for(int i=0;i<size;i++){
            if(prices[i]>min_till_now){
                profit += prices[i] - min_till_now;
                min_till_now = prices[i];
            } else {
                min_till_now = min(prices[i], min_till_now);
            }
        }
        return profit;
    }
};
