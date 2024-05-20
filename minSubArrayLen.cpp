class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        int sum = 0, minLength = INT_MAX;

        while (right < n) {
            sum += nums[right++];
            while (sum >= target) {
                minLength = min(minLength, right - left);
                sum -= nums[left++];
            }
        }

        return (minLength == INT_MAX) ? 0 : minLength;
    }
};
