// bfs，很简单，每次取bfs最后一个加到vector里面就可以了
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;
        
        queue<TreeNode*> q; q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode* p = q.front(); q.pop();
                if (p->left) q.push(p->left);
                if (p->right) q.push(p->right);
                if (i == n-1) result.push_back(p->val);
            }
        }
        
        return result;
    }
    
};