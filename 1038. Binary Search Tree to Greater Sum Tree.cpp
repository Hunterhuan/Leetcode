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
private:
    int help(TreeNode* root, int start){
        //cout<<root->val<<' '<<start<<endl;
        int tmp = start;
        if(root->right){
            tmp = help(root->right, start);
        }
        root->val = root->val + tmp;
        tmp = root->val;
        if(root->left){
            tmp = help(root->left, root->val);
        }
        return tmp;
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        if(!root)
            return NULL;
        help(root, 0);
        return root;
    }
};