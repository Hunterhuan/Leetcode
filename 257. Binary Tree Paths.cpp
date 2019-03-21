// 少考虑了一种情况，竟然还错了一次。不应该
// 对sring的使用一定要牢记
class Solution {
public:
    void find(TreeNode* root, string tmp, vector<string> &res){
        if(!root)
            return;
        tmp += "->";
        tmp += to_string(root->val);
        if(!root->left && !root->right)
            res.push_back(tmp);
        find(root->left, tmp, res);
        find(root->right, tmp, res);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(!root)
            return res;
        string tmp = to_string(root->val);
        if(!root->left && !root->right){
            res.push_back(tmp);
            return res;
        }
        find(root->left, tmp, res);
        find(root->right, tmp, res);
        return res;
    }
};