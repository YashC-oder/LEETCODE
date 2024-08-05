class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int size = nums.size();
        int maxi = 0;
        int current_max = 0;
        int prev_zero = -1;

        for(int i = 0 ; i<size;i++){
            int current = nums[i];
            if(current == 0){
                current_max = max(i - prev_zero -1,0);
                prev_zero = i;
            }else{
                current_max++;
                maxi = max(maxi,current_max);
            }
        }

        return maxi == size ? maxi-1:maxi;
    }
};