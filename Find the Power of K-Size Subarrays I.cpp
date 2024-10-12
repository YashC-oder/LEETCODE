class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> sequence(size, 1);
        
        for (int i = 1; i < size; i++) {
            if (nums[i] == nums[i-1] + 1) {
                sequence[i] = sequence[i-1] + 1;
            }
        }

        vector<int> result(size - k + 1, -1);

        for (int i = k - 1, j = 0; i < size; i++, j++) {
            if (sequence[i] >= k) {
                result[j] = nums[i];
            }
        }

        return result;
    }
};
