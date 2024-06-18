class Solution {
private:
    int traverse(TreeNode* root,int& sum){
        if(!root) return 0;
        sum += root->val;
        return 1 + traverse(root->left,sum) + traverse(root->right,sum);
    }
public:
    int averageOfSubtree(TreeNode* root) {
        if(!root) return 0;
        int count = 0;
        int sum = 0;
        int num_nodes = traverse(root,sum);
        int avg = sum / num_nodes;

        if(root->val == avg) count = 1;

        return count + averageOfSubtree(root->left) + averageOfSubtree(root->right);

    }
};