class Solution {
private:
    void findPath(TreeNode* root, int targetSum, long long currentSum, unordered_map<long long, int>& prefixSumCount, int& count) {
        if (!root) return;

        currentSum += root->val;

        if (prefixSumCount.find(currentSum - targetSum) != prefixSumCount.end()) {
            count += prefixSumCount[currentSum - targetSum];
        }

        prefixSumCount[currentSum]++;

        findPath(root->left, targetSum, currentSum, prefixSumCount, count);
        findPath(root->right, targetSum, currentSum, prefixSumCount, count);

        prefixSumCount[currentSum]--;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixSumCount;
        prefixSumCount[0] = 1;
        int count = 0;
        findPath(root, targetSum, 0LL, prefixSumCount, count);
        return count;
    }
};
