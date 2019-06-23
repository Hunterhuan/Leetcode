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
    void preorder(TreeNode* root, vector<TreeNode*> &tmp){
        if(!root)
            return;
        if(root->left)
            preorder(root->left, tmp);
        tmp.push_back(root);
        if(root->right)
            preorder(root->right, tmp);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        vector<TreeNode*> tmp;
        preorder(root, tmp);
        tmp.push_back(NULL);
        for(int i=0;i<tmp.size()-1;++i){
            tmp[i]->left = NULL;
            tmp[i]->right = tmp[i+1];
        }
        return tmp[0];
    }
};