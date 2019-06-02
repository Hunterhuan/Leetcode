/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int min_;
    
    int minDiffInBST(TreeNode* root) {
        min_ = INT_MAX;
        dfs(root);
        return min_;
    }
    
    void dfs(TreeNode* n) {
        if (!n) return ;
        if (n->left) {
            int val = Rval(n->left);
            min_ = min(min_, n->val - val);
        }
        if (n->right) {
            int val = Lval(n->right);
            min_ = min(min_, val - n->val);
        }
        dfs(n->left);
        dfs(n->right);
    }
    
    int Lval(TreeNode* n) {
        int val = 0;
        for (; n; n = n->left) val = n->val;
        return val;
    }
    
    int Rval(TreeNode* n) {
        int val = 0;
        for (; n; n = n->right) val = n->val;
        return val;
    }
};