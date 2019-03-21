// 递归方法很简单
class Solution {
public:
    void postorder(TreeNode*root, vector<int> &res){
        if(root == NULL)
            return;
        postorder(root->left,res);
        postorder(root->right,res);
        res.push_back(root->val);

    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root,res);
        return res;
    }
};

//非递归方法
// 有一些需要反复放入stack中

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        
        stack<tuple<TreeNode*, bool>> s;
        s.emplace(root, false);
        while (!s.empty())
        {
            bool finished; TreeNode* crt;
            tie(crt, finished) = s.top();
            if (!finished)
            {
                get<1>(s.top()) = true;
                if (crt->right) s.emplace(crt->right, false);
                if (crt->left) s.emplace(crt->left, false);
            }
            else
            {
                result.push_back(crt->val);
                s.pop();
            }
        }
        return result;
    }
};