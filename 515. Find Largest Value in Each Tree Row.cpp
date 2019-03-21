// 这道题主要是考验 queue和pair的使用。挺棒的
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<pair<TreeNode *, int>> q;
        vector<int> res;
        if(!root)
            return res;
        q.push(make_pair(root, 0));
        pair<TreeNode *,int > p;
        while(!q.empty()){
            p = q.front();
            q.pop();
            if(p.second >= res.size()){
                res.push_back(p.first->val);
            }
            else if(p.first->val > res[p.second])
                res[p.second] = p.first->val;
            if(p.first->left)
                q.push(make_pair(p.first->left, p.second+1));
            if(p.first->right)
                q.push(make_pair(p.first->right, p.second+1));
        }
        return res;
    }
};