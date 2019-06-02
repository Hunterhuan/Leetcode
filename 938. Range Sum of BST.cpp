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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(!root)
            return 0;
        int res = 0;
        if(root->left && root->val>=L){
            res += rangeSumBST(root->left, L, R);
        }
        if(root->val <=R && root->val >= L)
            res += root->val;
        if(root->right && root->val <=R){
            res += rangeSumBST(root->right, L, R);
        }
        return res;
    }
};