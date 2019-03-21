// 这个没有写出来，c++的语法还需要再进行练习，比如引用& 指针的基本使用


// 对每个节点，执行该函数，直到找到了，然后就在右枝里面删去最小的

//递归
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if (root->val < key){
            root->right = deleteNode(root->right, key);
        } else {
            if (!root->left || !root->right) {
                root = (root->left) ? root->left : root->right;
            } else {
                TreeNode* rightMin = root->right;
                while (rightMin->left) rightMin = rightMin->left;
                root->val = rightMin->val;
                root->right = deleteNode(root->right, rightMin->val);
            }
        }
        return root;
    }
};