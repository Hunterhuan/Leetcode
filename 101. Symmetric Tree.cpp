// 判断是否对称，很简单，用递归就可以了

class Solution {
public:
    bool issame(TreeNode *root1,TreeNode *root2)
    {
        if(root1==NULL && root2==NULL)
            return true;
        if(root1==NULL || root2==NULL)
            return false;
        else
        {
            if(root1->val != root2->val)
                return false;
            else
                return (issame(root1->right,root2->left)&&issame(root1->left,root2->right));
        }
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        else
            return issame(root->right,root->left);
    }
};