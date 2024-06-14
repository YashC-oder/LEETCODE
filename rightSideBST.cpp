// 2ms DFS
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> right = rightSideView(root->right);
        vector<int> left = rightSideView(root->left);

        for(int i = right.size(); i<left.size() ;i++){
            right.push_back(left[i]);
        }
        right.insert(right.begin(),root->val);
        return right;
    }
};


// 2ms BFS
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};

        vector<int> rightView;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                if (i == levelSize - 1) {
                    rightView.push_back(node->val);
                }

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }

        return rightView;
    }
};