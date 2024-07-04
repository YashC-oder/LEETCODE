class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        bool order = true;
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> zigzagTraverse;

        while(!q.empty()){
            int size = q.size();
            vector<int> current;
            order = !order;
            for(int i = 0;i<size;i++){
                TreeNode* node = q.front(); q.pop();
                current.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(order) reverse(current.begin(),current.end());
            zigzagTraverse.push_back(current);
        }

        return zigzagTraverse;
    }
};