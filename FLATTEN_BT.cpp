class Solution {
private:
    TreeNode* helper(TreeNode* root){
        if(root == nullptr) return nullptr;

        TreeNode* left = helper(root->left);
        root->left = nullptr;

        TreeNode* right = left;

        while(right && right->right != nullptr){
            right = right->right;
        }

        if(!right){
            left = helper(root->right);
        }else{
            right->right = helper(root->right);
        }
        root->right = left;

        return root;
    }
public:
    void flatten(TreeNode* root) {
        helper(root);
    }
};