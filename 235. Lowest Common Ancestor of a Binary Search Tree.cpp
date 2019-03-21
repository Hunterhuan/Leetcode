// easy 的题确实很简单，跟搜索树一样。
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode * tmp = root;
        if(!root)
            return NULL;
        int value = root->val;
        if(value < p->val && value < q->val)
            return lowestCommonAncestor(root->right, p, q);
        else if(value > p->val && value > q->val)
            return lowestCommonAncestor(root->left, p, q);
        return root;
    }
};