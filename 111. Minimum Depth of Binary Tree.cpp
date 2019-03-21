
//第一次错了。以为是求最小深度。后来发现是求到leaf 的最短距离。就加了两个判断条件，如果不是页，那么就return，如果是页，那么就返回高度
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        if(root->left==NULL)
            return minDepth(root->right)+1;
        if(root->right==NULL)
            return minDepth(root->left) + 1;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        return min(left, right) + 1;
    }
};