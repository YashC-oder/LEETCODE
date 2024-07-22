class Solution {
private:
    void countGoodNodes(TreeNode* node,int maxi,int& count){
        if(!node) return;

        int node_val = node->val;

        if(node_val >= maxi) count++;

        maxi = max(node_val,maxi);

        countGoodNodes(node->left,maxi,count);
        countGoodNodes(node->right,maxi,count);
    }
public:
    int goodNodes(TreeNode* root) {
        int count = 0;
        countGoodNodes(root,INT_MIN,count);
        return count;
    }
};