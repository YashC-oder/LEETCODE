class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx = -1;
        size_t size = nums.size();

        for(int i = size-2; i>=0 ; i--){
            if(nums[i]<nums[i+1]){
                idx=i;
                break;
            }
        }

        if(idx==-1) return reverse(nums.begin(),nums.end());

        for(int ptr = size-1; ptr>idx ; ptr-- ){
            if(nums[idx]<nums[ptr]){
                swap(nums[idx],nums[ptr]);
                break;
            }
        }

        reverse(nums.begin()+idx+1,nums.end());

    }
};