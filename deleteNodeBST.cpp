class Solution {
private:
    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) node = node->left;
        return node;
    }

    TreeNode* removeNode(TreeNode* root, int key) {
        if (root == nullptr) return root;

        if (key < root->val) {
            root->left = removeNode(root->left, key);
        } else if (key > root->val) {
            root->right = removeNode(root->right, key);
        } else {
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            TreeNode* temp = findMin(root->right);
            root->val = temp->val;
            root->right = removeNode(root->right, temp->val);
        }
        return root;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        return deleteNode(root, key);
    }
};
