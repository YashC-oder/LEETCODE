class Solution {
private:
    int size;
    int Longestsubseq(vector<int>& nums,int value,int index,vector<int>& dp){
        if(index >= size) return 0;
        if(value < nums[index]){
            return max(dp[index],Longestsubseq(nums,value,index+1,dp));
        }
        return Longestsubseq(nums,value,index+1,dp);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        size = nums.size();
        vector<int> dp(size,1);
        int maxSequence = 1;

        for(int i = size-1;i>=0;i--){
            int current = nums[i];
            dp[i] += Longestsubseq(nums,current,i,dp);
            maxSequence = max(maxSequence,dp[i]);
        }

        return maxSequence;
    }
};


/*------------------------------------------------------------------------------------*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;

        vector<int> dp;
        for (int num : nums) {
            auto it = lower_bound(dp.begin(), dp.end(), num);
            if (it == dp.end()) {
                dp.push_back(num);
            } else {
                *it = num;
            }
        }

        return dp.size();
    }
};
