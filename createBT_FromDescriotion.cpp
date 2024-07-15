class Solution {
private:
    TreeNode* createNode(int rootVal, unordered_map<int, TreeNode*>& nodes) {
        if (nodes.find(rootVal) != nodes.end()) 
            return nodes[rootVal];
        return nodes[rootVal] = new TreeNode(rootVal);
    }

    void createTree(vector<int>& description, unordered_map<int, TreeNode*>& nodes, unordered_map<int, bool>& parent) {
        int rootVal = description[0];
        int childVal = description[1];
        bool isLeft = description[2];

        TreeNode* root = createNode(rootVal, nodes);
        TreeNode* child = createNode(childVal, nodes);

        if (isLeft) {
            root->left = child;
        } else {
            root->right = child;
        }

        parent[childVal] = true;
        if (parent.find(rootVal) == parent.end()) {
            parent[rootVal] = false;
        }
    }

public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, bool> parent;
        unordered_map<int, TreeNode*> nodes;

        for (auto& description : descriptions) {
            createTree(description, nodes, parent);
        }

        TreeNode* root = nullptr;

        for (auto& [key, val] : parent) {
            if (!val) {
                root = nodes[key];
                break;
            }
        }

        return root;
    }
};