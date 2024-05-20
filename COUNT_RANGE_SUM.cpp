class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> prefixSum(n + 1);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        return mergeSortCount(prefixSum, 0, n + 1, lower, upper);
    }
    
    int mergeSortCount(vector<long long>& prefixSum, int left, int right, int lower, int upper) {
        if (right - left <= 1) return 0;
        int mid = left + (right - left) / 2;
        int count = mergeSortCount(prefixSum, left, mid, lower, upper) + mergeSortCount(prefixSum, mid, right, lower, upper);
        int j = mid, k = mid, t = mid;
        vector<long long> cache(right - left);
        for (int i = left, r = 0; i < mid; ++i, ++r) {
            while (k < right && prefixSum[k] - prefixSum[i] < lower) ++k;
            while (j < right && prefixSum[j] - prefixSum[i] <= upper) ++j;
            while (t < right && prefixSum[t] < prefixSum[i]) cache[r++] = prefixSum[t++];
            cache[r] = prefixSum[i];
            count += j - k;
        }
        copy(cache.begin(), cache.begin() + t - left, prefixSum.begin() + left);
        return count;
    }
};
