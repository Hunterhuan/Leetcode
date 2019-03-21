// 前序遍历，这也太简单了吧
class Solution {
public:
    void preorder(TreeNode*root, vector<int> &res){
        if(root == NULL)
            return;
        res.push_back(root->val);
        preorder(root->left,res);
        preorder(root->right,res);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root,res);
        return res;
    }
};

// 非递归方法，那就用栈去实现
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root)   return result;
        stack<TreeNode*> node_stack;
        node_stack.push(root);
        while(!node_stack.empty()) {
            TreeNode *temp = node_stack.top();
            node_stack.pop();
            result.push_back(temp->val);
            if(temp->right)
                node_stack.push(temp->right);
            if(temp->left)
                node_stack.push(temp->left);
        }
        return result;
    }
};