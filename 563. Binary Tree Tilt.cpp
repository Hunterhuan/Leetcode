// 很简单
class Solution {
public:
    int getTiltsum(TreeNode* root, int& sum){
        if(!root)
            return 0;
        int left = getTiltsum(root->left, sum);
        int right = getTiltsum(root->right, sum);
        sum += abs(left - right);
        return left+right+root->val;
    }
    int findTilt(TreeNode* root) {
        int sum = 0;
        getTiltsum(root, sum);
        return sum;
    }
};