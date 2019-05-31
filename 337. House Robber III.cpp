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
    map<TreeNode*, int> steal;
    map<TreeNode*, int> refuse;
public:
    int rob(TreeNode* root) {
        dfs(root);
        return max(steal[root], refuse[root]);
    }
    void dfs(TreeNode* root){
        if(!root)
            return;
        dfs(root->left);
        dfs(root->right);
        steal[root] = root->val + refuse[root->left] + refuse[root->right];
        refuse[root] = max(refuse[root->left], steal[root->left]) + max(refuse[root->right], steal[root->right]);
    }
};