// 可以用队列进行层次遍历吧。
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        int count = 0;
        TreeNode *tmp;
        while(!q.empty()){
            tmp = q.front();
            q.pop();
            if(tmp->left)
                q.push(tmp->left);
            if(tmp->right)
                q.push(tmp->right);
            count++;
        }
        return count;
        
    }
};

// 别人用的二分搜索方法很妙，用递归。每次都count一个完整的树
class Solution {
public:
    int countNodes(TreeNode* root) {
        int heightLeft = 0, heightRight = 0;
        TreeNode *pLeft = root, *pRight = root;
        while (pLeft) {
            heightLeft++;
            pLeft = pLeft->left;
        }
        while (pRight) {
            heightRight++;
            pRight = pRight->right;
        }
        if (heightLeft == heightRight) return pow(2, heightLeft) -1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};