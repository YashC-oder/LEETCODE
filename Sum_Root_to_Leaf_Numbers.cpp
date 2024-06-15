class Solution {
private:
    void Numbers(TreeNode* root ,int& sum, int num = 0){
       if(root){
            num = num*10 + root->val;
       }
       if(root->left || root->right){
            if(root->left){
                Numbers(root->left,sum,num);
            }
            if(root->right){
                Numbers(root->right,sum,num);
            }
       }else{
            sum += num;
       }
    }
public:
    int sumNumbers(TreeNode* root,int num = 0) {
        int sum = 0;
        Numbers(root,sum);
        return sum;
    }
};