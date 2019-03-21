// 很简单，一次过。
// 用递归存下来就行了
class Solution {
public:
    void findpathsum(TreeNode* root, int value, int &sum){
        value = value * 10 + root->val;
        if(root->left)
            findpathsum(root->left, value, sum);
        if(root->right)
            findpathsum(root->right, value, sum);
        if(!root->left && !root->right){
            sum = sum + value;
        }
    }
    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        int sum = 0;
        findpathsum(root, 0, sum);
        return sum;
    }
};