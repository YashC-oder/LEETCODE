class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();

        if(size == 1){
            return nums[0];
        }

        int prev = nums[0], curr = max(nums[0],nums[1]);

        for(int i = 2 ; i<size ; i++){
            int temp = curr;
            curr = max(curr,nums[i]+prev);
            prev = temp;
        }

        return curr;
    }
};