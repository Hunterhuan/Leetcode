// 很有技巧性的题，应该记住的。

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root && root->left){
            root->left->next = root->right;
            if(root->next){
                root->right->next = root->next->left;
            }
        connect(root->left);
        connect(root->right);
        }

    }
};