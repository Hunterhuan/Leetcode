// 太妙了。我只想到用int来标记上下限，但别人用指针去传递。
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isBst(root);      
    }

    bool isBst(TreeNode* root, TreeNode* l=NULL, TreeNode* r=NULL) {
        if (root == NULL) return true;
        if (l && root->val <= l->val) return false;
        if (r && root->val >= r->val) return false;
        return isBst(root->left, l, root) && isBst(root->right, root, r);
    }
};

// 用int 去做，一直被int_max 和int_min 给报错

class Solution {
public:
    bool checkvalid(TreeNode * root, int down, int up){
        if(!root)
            return true;
        if(root->val >= up || root->val <= down)
            return false;
        else{
            return (checkvalid(root->left, down, root->val) && checkvalid(root->right, root->val, up));
        }
    }
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        return (checkvalid(root->left, INT_MIN, root->val) && checkvalid(root->right, root->val, INT_MAX));
    }
};