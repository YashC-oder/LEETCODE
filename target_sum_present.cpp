class Solution{
    private:
    bool backtrack(vector<int>& array,int target ,int currentSum,int index){
        if(index > array.size() || currentSum > target) return false;
        if(currentSum == target) return true;
        return backtrack(array,target,currentSum+array[index],index+1) || backtrack(array,target,currentSum,index+1);
    }
    public:
    bool check(vector<int> array,int k){
        return backtrack(array,k,0,0);
    }
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n+1, vector<bool>(k+1, false));

    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; ++i) {
        for (int target = 1; target <= k; ++target) {
            bool skip = dp[i-1][target];
            bool take = false;
            if (arr[i-1] <= target) {
                take = dp[i-1][target - arr[i-1]];
            }
            dp[i][target] = take || skip;
        }
    }
    return dp[n][k];
}