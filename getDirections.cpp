class Solution {
private:
    TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
        if (!root) return nullptr;
        if (root->val == p || root->val == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left && right) return root;
        return left ? left : right;
    }
    
    bool findPath(TreeNode* node, int value, string& path) {
        if (!node) return false;

        if (node->val == value) return true;

        if (node->left && findPath(node->left, value, path)) {
            path.push_back('L');
            return true;
        }

        if (node->right && findPath(node->right, value, path)) {
            path.push_back('R');
            return true;
        }

        return false;
    }
    
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lcaNode = lowestCommonAncestor(root, startValue, destValue);

        string pathToStart = "", pathToDest = "";
        findPath(lcaNode, startValue, pathToStart);
        findPath(lcaNode, destValue, pathToDest);

        for (char& c : pathToStart) {
            c = 'U';
        }
        
        reverse(pathToDest.begin(), pathToDest.end());

        return pathToStart + pathToDest;
    }
};
