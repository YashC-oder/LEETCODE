class BSTIterator {
private:
    TreeNode* FlattenBST(TreeNode* root){
        if(!root) return nullptr;
        TreeNode* node = new TreeNode(root->val);
        TreeNode* left = FlattenBST(root->left);
        TreeNode* right = FlattenBST(root->right);
        TreeNode* Head = left;
        while(left && left->right){
            left = left->right;
        }
        node->left = left;
        node->right = right;
        if(node->left){
            node->left->right = node;
        }else{
            Head = node;
        }
        if(node->right) node->right->left = node;

        return Head;
    }

    TreeNode* head;
    TreeNode* current;
public:
    BSTIterator(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        head = new TreeNode(0);
        head->right = FlattenBST(root);
        current = head;
    }
    
    int next() {
        current = current->right;
        return current->val;
    }
    
    bool hasNext() {
        return current->right;
    }
};

/*-----------------------------------------------------------------------------------------*/

class BSTIterator {
private:
    vector<int> inorder;
    int current = 0;
    int size;
    void traverse(TreeNode* root, vector<int> &inorder) {
        if(!root) return;
        traverse(root -> left, inorder);
        inorder.push_back(root -> val);
        traverse(root -> right, inorder);
    }
public:
    BSTIterator(TreeNode* root) {
        traverse(root, inorder);
        inorder.insert(inorder.begin() ,0);
        size = inorder.size();
    }
    
    int next() {
        return inorder[++current];
    }
    
    bool hasNext() {
        if(current < size) return true;
        else return false;
    }
};