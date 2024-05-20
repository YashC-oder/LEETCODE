void morissTraveral(TreeNode* root){ // inorder
    TreeNode* curr = root;
    while(curr){
        if(curr->left){

            TreeNode* predecessor = curr->left;

            while(predecessor->right && predecessor->right!= nullptr){
                predecessor = predecessor->right;
            }

            if(!predecessor->right){

                predecessor->right = curr;
                curr = curr->left;

            }else{

                cout<< curr->val << " ";// root or right
                predecessor->right = nullptr;
                curr = curr->right;

            }
        }else{

            cout<< curr->val <<" "; // root or left
            curr = curr->right;
            
        }
    }
}

//preorder
void morrisTraversal(TreeNode* root) {
    TreeNode* curr = root;
    
    while (curr) {
        if (curr->left) {
            // Find the inorder predecessor of curr
            TreeNode* predecessor = curr->left;
            
            while (predecessor->right && predecessor->right != curr) {
                predecessor = predecessor->right;
            }
            
            if (!predecessor->right) {
                // Make current node as the right child of its inorder predecessor
                predecessor->right = curr;
                
                // Print current node (before going to left subtree)
                cout << curr->val << " ";
                
                // Move to the left child
                curr = curr->left;
            } else {
                // Revert the change made in if part to postordertore the original tree
                predecessor->right = nullptr;
                
                // Move to the right child after visiting left subtree
                curr = curr->right;
            }
        } else {
            // No left child, just move to right child
            cout << curr->val << " ";
            curr = curr->right;
        }
    }
}

vector<int> postorderTraversal(TreeNode* root)
{
    vector<int> result;
    if (root == nullptr)
        return result;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        result.push_back(current->data);

        // Enqueue right child before left child
        if (current->right)
            q.push(current->right);
        if (current->left)
            q.push(current->left);
    }

    reverse(result.begin(), result.end());
    return result;
}