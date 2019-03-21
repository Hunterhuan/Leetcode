// 把BST倒着遍历，遍历的同时再赋值就可以了
class Solution {
public:
    void travel(TreeNode* root, int& sum){
        if(root->right)
            travel(root->right, sum);
        sum += root->val;
        root->val = sum;
        if(root->left)
            travel(root->left, sum);
    }
    TreeNode* convertBST(TreeNode* root) {
        if(!root)
            return root;
        int tmp = 0;
        travel(root, tmp);
        return root;
    }
};