class Solution {
private:
    int makeProfit(vector<int>& prices, int fee,int day,vector<vector<int>>& dp,bool holding){
        if(day >= prices.size()) return 0;
        int& current = dp[day][holding];
        if(current != -1) return current;

        int doNothing = makeProfit(prices,fee,day+1,dp,holding);
        int doSomething;

        if(holding){
            doSomething = prices[day] + makeProfit(prices,fee,day+1,dp,false) - fee;
        }else{
            doSomething = -prices[day] + makeProfit(prices,fee,day+1,dp,true);
        }

        return current = max(doNothing,doSomething);
    }
    int tabMakeProfit(vector<int>& prices,int fee){
        int size = prices.size();
        vector<vector<int>> dp(size+1,vector<int>(2,0));

        for(int i = size-1;i>=0;i--){
            for(int j = 0;j<2;j++){
                if(j){
                    dp[i][j] = max(dp[i+1][j],prices[i]+dp[i+1][0] - fee);
                }else{
                    dp[i][j] = max(dp[i+1][j],-prices[i]+dp[i+1][1]);
                }
            }
        }

        return dp[0][0];
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return makeProfit(prices,fee,0,dp,false);
    }
};