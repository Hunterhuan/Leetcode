// 利用递归很简单
class Solution {
public:
    void findallpath(TreeNode * root, int sum, vector<vector<int>> &res, vector<int> path){
        if(!root)
            return;
        path.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(root->val == sum){
                res.push_back(path);
            }
            return;
        }
        
        findallpath(root->left, sum-root->val, res, path);
        findallpath(root->right, sum-root->val, res, path);
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        findallpath(root, sum, res, path);
        return res;
    }
};