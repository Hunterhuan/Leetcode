// 错了几次，因为自己把题意搞错了。
//但感觉不值 hard 难度
class Solution {
public:
    int findtoleaf(TreeNode *root, int &maxvalue){
        if(!root)
            return 0;
        int left = max(findtoleaf(root->left, maxvalue),0);
        int right = max(findtoleaf(root->right, maxvalue),0);
        if(left + right + root->val > maxvalue)
            maxvalue = left + right + root->val;
        return max(left, right) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxvalue = INT_MIN;
        findtoleaf(root, maxvalue);
        return maxvalue;
    }
};