class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLength = 0;
        int left = 0;
        for(int rigth = 0 , zeros = 0; right < nums.size() ; right++){
            if(nums[right] == 0) zeros++; // increases window size
            while(zeros > k){
                if(nums[left++] == 0) zeros--; // decreases window size
            }
                maxLength = max(maxLenght,right - left +1);
        }
        return maxLenght;
    }
};