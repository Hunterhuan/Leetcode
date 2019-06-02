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
    int f(TreeNode*root, int& ans)
    {
        int l = 0,r=0;
        if(root->left)
        {
            l=f(root->left,ans)+bool(root->left->val == root->val);
        }
        if(root->right)
        {
            r=f(root->right,ans)+bool(root->right->val == root->val);
        }
        if(root->left && root->right && root->val == root->left->val && root->right->val == root->val)
        {
            ans=max(ans,l+r);
            return max(l,r);
        }
        if(root->left && root->left->val==root->val)
        {
            ans=max(ans,l);
            return l;
        }
        if(root->right && root->right->val==root->val)
        {
            ans=max(ans,r);
            return r;
        }
        return 0;
    }
    
    int longestUnivaluePath(TreeNode* root) {
        if(!root)return 0;
        int ans=0;
        f(root,ans);
        return ans;
    }
};