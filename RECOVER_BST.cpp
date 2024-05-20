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
public:
    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* previous = nullptr;
        TreeNode* curr = root;
        
        while(curr){
            if(curr->left){
                
                TreeNode* predecessor = curr->left;
                while(predecessor->right && predecessor->right != curr){
                    predecessor = predecessor->right;
                }

                if(!predecessor->right){
                    predecessor->right  = curr;
                    curr = curr->left;
                }else{
                    if(previous && previous->val > curr->val){ // In inorder traversal result in ascending order result . so here i checking the discrepancy
                        if(!first){
                            first = previous;
                        }
                        second = curr;
                    }

                    predecessor->right = nullptr;
                    previous = curr;
                    curr = curr->right;

                }
            }else{
                if (previous && previous->val > curr->val) {
                    if (!first) {
                        first = previous;
                    }
                    second = curr;
                }
                
                previous = curr;
                curr = curr->right;
            }
          }  

          if (first && second) {
            swap(first->val, second->val);             
        }

    }
};

// another approuch with 0ms but uses recursion(using function call stack memory <= space complexity )

// class Solution {
// public:
//     TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;
//     void dfs(TreeNode* curr) {
//         if (!curr) return;
//         dfs(curr->left);
//         if (prev && prev->val > curr->val) {
//             if (!first) {
//                 first = prev;
//                 second = curr;
//             } else {
//                 second = curr;
//             }
//         }
//         prev = curr;
//         dfs(curr->right);
//     }
//     void recoverTree(TreeNode* root) {
//         dfs(root);
//         swap(first->val, second->val);
//     }
// };