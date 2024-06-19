class Solution {
public:
    int findMin(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int size = nums.size();

        if(size == 1) return nums.at(0);

        int left = 0,right = size-1;

        while(left < right){
            int mid = left + (right - left) / 2;

            if(nums[mid] > nums[right]){
                left = mid+1;
            }else{
                right = mid;
            }
        }

        return nums[left];
    }
};