/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:

    void inorderTraverse(TreeNode* root,vector<int>& inorder){
        if(!root) return;
        inorderTraverse(root->left,inorder);
        inorder.push_back(root->val);
        inorderTraverse(root->right,inorder);
    }

public:
    bool isValidBST(TreeNode* root) {
        if(!root) return false;

        vector<int> inorder;

        inorderTraverse(root,inorder);

        int size = inorder.size();
        for(int i = 0;i < size; i++)
            for(int j = i+1 ; j<size ; j++)
                if(inorder[j] < inorder[i] || inorder[j] == inorder[i])
                    return false;

        return true;
    }
};

/*----------------------------------------------------------------------------------------------------------------------------------------*/

class Solution {
public:
    bool check(TreeNode*root, long mini = LLONG_MIN, long maxi = LLONG_MAX){
        if(root == nullptr) return true;
        if(root->val >= maxi || root->val <= mini) return false;
        else return check(root->left,mini,root->val) && check(root->right,root->val,maxi);
    }
    bool isValidBST(TreeNode* root) {
        return check(root);
    }
};