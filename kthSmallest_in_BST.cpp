class Solution {
private:
    void traverse(TreeNode* root,vector<int>& inorder, int k){
        if(!root) return;
        if(root->left) traverse(root->left,inorder,k);
        if(inorder.size() == k) return;
        inorder.push_back(root->val);
        if(root->right) traverse(root->right,inorder,k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
      vector<int> inorder;
      traverse(root,inorder,k);
      return inorder.back();
    }
};


/***************************************************************************************/

class Solution {
private:
    struct Node{
        TreeNode* node;
        int index;
        Node():node(nullptr),index(0){}
    }
    void traverse(TreeNode* root,Node& n, int k){
       if(!root || n.index >= k) return;
       traverse(root->left,n,k);
       n.index++;
       if(n.index == k){
        n.node = root;
        return;
       }
       traverse(root->right,n,k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
      Node n = new Node();
      traverse(root,n,k);
      return n.node->val;
    }
};