// 层次遍历，挺简单的
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if(!root)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *tmp;
        int res;
        while(!q.empty()){
            tmp = q.front();
            q.pop();
            res = tmp->val;
            if(tmp->right)
                q.push(tmp->right);
            if(tmp->left)
                q.push(tmp->left);
        }
        return res;
    }
};