class Solution {
private:
  int targetSum(vector<int>& nums, int target,int start,int sum,int sign){
    if(start >= nums.size()) return 0;
     sum += sign * nums[start];
     if(sum == target && start == nums.size() -1){
        return 1;
     }
     return targetSum(nums,target,start+1,sum,1) + targetSum(nums,target,start+1,sum,-1);
  }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return targetSum(nums,target,0,0,1) + targetSum(nums,target,0,0,-1);
    }
};