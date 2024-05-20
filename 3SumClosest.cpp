class Solution {
public:
    int threeSumClosest(vector<int>& nums, int t) {
        sort(nums.begin(),nums.end());

        int closestSum = 1e5;

        for(int i = 0;i < nums.size() ; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int target = t - nums[i];
            
            int left = i+1,right = nums.size()-1;

            while(left < right){
                int sum = nums[left] + nums[right];
                if(sum == target || abs(t - (sum + nums[i])) < abs(t - closestSum)){
                    closestSum = (sum + nums[i]);
                }
                if(sum < target){
                    left++;
                }else{
                    right--;
                }
            }
        }

        return closestSum;
    }
};


