// easy的题，挺简单的
class Solution {
public:
    int Searchdepth(TreeNode* root, int &M){
        if(root==NULL)
            return(0);
        int left = Searchdepth(root->left, M);
        int right = Searchdepth(root->right, M);
        if(left + right  > M)
            M = left + right ;
        return 1+max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return(0);
        int M = 0;
        Searchdepth(root, M);
        return M;
    }
};