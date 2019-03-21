// find k th smallest , very easy, 只要用中序遍历就能按顺序便利下来了。
class Solution {
public:
    void travel(TreeNode*root, vector<int>& res, int k){
        if(res.size()>=k)
            return;
        if(root->left)
            travel(root->left, res, k);
        res.push_back(root->val);
        if(root->right)
            travel(root->right, res, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;
        travel(root, res, k);
        return res[k-1];
    }
};