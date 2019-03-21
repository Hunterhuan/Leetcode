// 太简单了
class Solution {
public:
    void invert(TreeNode * root){
        if(!root)
            return;
        TreeNode * tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        invert(root->left);
        invert(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
};