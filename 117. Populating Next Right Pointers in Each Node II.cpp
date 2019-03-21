// 比116难一些。代码也更复杂一些。但别人还是能够写的特别简洁，真的很厉害。
// 自己又写错了
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root || (!root->left && !root->right))
            return;
        TreeLinkNode *tempRoot = root, *tempIter = new TreeLinkNode(-1);
        while(tempRoot && !tempIter->next) { 
            if(tempRoot->left)
                tempIter = tempIter->next = tempRoot->left;
            if(tempRoot->right)
                tempIter = tempIter->next = tempRoot->right;
            tempRoot = tempRoot->next;
        }
        connect(root->left);
        connect(root->right);
    }
};