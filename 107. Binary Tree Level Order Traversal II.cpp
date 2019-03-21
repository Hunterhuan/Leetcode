// 简单。没必要做了
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> level(q.size());
            auto sz = q.size();
            for (int i=0; i<sz; i++) {
                auto node = q.front();
                q.pop();
                level[i] = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(move(level));
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};