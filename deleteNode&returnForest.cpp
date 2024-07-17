class Solution {
public:
    vector<TreeNode*> result;
    unordered_set<int> to_delete_set;
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (int i : to_delete)
            to_delete_set.insert(i);
        deleteNode(root, result, to_delete_set, true);
        return result;
    }

    TreeNode* deleteNode(TreeNode* node, vector<TreeNode*>& result,unordered_set<int>& to_delete_set, bool is_root) {
        if (!node) return nullptr;
        bool deleted = to_delete_set.find(node->val) != to_delete_set.end();
        if (is_root && !deleted)
            result.push_back(node);
        node->left = deleteNode(node->left, result, to_delete_set, deleted);
        node->right = deleteNode(node->right, result, to_delete_set, deleted);
        return deleted ? nullptr : node;
    }
};