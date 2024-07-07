class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0, maxSum = INT_MIN, minSum = INT_MAX;
        int currentMax = 0, currentMin = 0;

        for (int num : nums) {
            currentMax = max(currentMax + num, num);
            maxSum = max(maxSum, currentMax);
            currentMin = min(currentMin + num, num);
            minSum = min(minSum, currentMin);
            totalSum += num;
        }

        if (maxSum > 0) {
            return max(maxSum, totalSum - minSum);
        } else {
            return maxSum;
        }
    }
};