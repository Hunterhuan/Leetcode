// 第一开始没有思路，然后就递归分开算。挺有意思的题
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)
            return 0;
        int left = 0;
        if(root->left){
            if(!root->left->left && !root->left->right)
                left = root->left->val;
            else
                left = sumOfLeftLeaves(root->left);
        }
        int right = sumOfLeftLeaves(root->right);
        return left + right;
    }
};