// 码代码第一次错了一点。不知道为什么。但最后ac了
class Solution {
public:
    int finddepth(TreeNode * root){
        if(!root)
            return 0;
        int left = finddepth(root->left);
        if(left==-1)
            return -1;
        int right = finddepth(root->right);
        if(right==-1)
            return -1;
        if(abs(left-right)<=1)
            return max(left,right)+1;
        return -1;
    }
    bool isBalanced(TreeNode* root) {
        if(finddepth(root)==-1)
            return false;
        else
            return true;
    }
};