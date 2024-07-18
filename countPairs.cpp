class Solution {
private:
        void findLeaves(TreeNode* node, vector<TreeNode*>& trail, vector<TreeNode*>& leaves, unordered_map<TreeNode*, vector<TreeNode*>>& map) {
            if (!node) return;
            trail.push_back(node);
            if (!node->left && !node->right) {
                map[node] = trail;
                leaves.push_back(node);
            } else {
                findLeaves(node->left, trail, leaves, map);
                findLeaves(node->right, trail, leaves, map);
            }
            trail.pop_back();
        }
    
        int findCommonAncestorDepth(const vector<TreeNode*>& track1, const vector<TreeNode*>& track2) {
            int minLength = min(track1.size(), track2.size());
            for (int k = 0; k < minLength; k++) {
                if (track1[k] != track2[k]) return k;
            }
            return minLength;
        }
public:
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, vector<TreeNode*>> map;
        vector<TreeNode*> leaves;
        vector<TreeNode*> trail;
        findLeaves(root, trail, leaves, map);
        int count = 0;
        for (int i = 0; i < leaves.size(); i++) {
            for (int j = i + 1; j < leaves.size(); j++) {
                vector<TreeNode*>& track1 = map[leaves[i]];
                vector<TreeNode*>& track2 = map[leaves[j]];
                int commonAncestorDepth = findCommonAncestorDepth(track1, track2);
                int dist = track1.size() + track2.size() - 2 * commonAncestorDepth;
                if (dist <= distance) count++;
            }
        }
        return count;
    }

};
