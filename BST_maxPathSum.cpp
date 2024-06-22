class Solution {
private:
    int pathSum(TreeNode* root,int& maxPath){
        if(!root) return -1001;
        int current = root->val;
        int left = pathSum(root->left,maxPath);
        int right = pathSum(root->right,maxPath);

        maxPath = max({maxPath,left,right,current+left+right});

        return max({current,current+left,current+right});
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;
        int result = pathSum(root,maxPath);

        return max(maxPath,result);
    }
};