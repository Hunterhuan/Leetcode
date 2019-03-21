// 这个是自己实现的，代码冗余度挺高的。但效率好像也挺高的。
class Solution {
public:
    TreeNode* flattenall(TreeNode * root){
        if(!root)
            return NULL;
        if(root->left==NULL && root->right==NULL)
            return root;
        if(root->left==NULL)
            return flattenall(root->right);
        if(root->right==NULL){
            root->right = root->left;
            root->left = NULL;
            return flattenall(root->right);
        }
        TreeNode * left=flattenall(root->left);
        TreeNode * right = flattenall(root->right);
        left->right  = root->right;
        root->right = root->left;
        root->left = NULL;
        return right;
    }
    void flatten(TreeNode* root) {
        flattenall(root);
        return;
    }
};

// 别人实现的真的短。用for循环太牛逼了。
class Solution {
public:
    void flatten(TreeNode* root) {
        for(auto it = root; root; root = root->right) {
            if (!root->right) swap(root->right, root->left);
            else if (root->left) {
                swap(root->left, root->right);
                for(it = root; it->right; it = it->right);
                swap(it->right, root->left);
            }
        }
    }
};