// 跟另外一道题很相似，改一下就做出来了
class Solution {
public:
    TreeNode *buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    TreeNode *buildTree(vector<int> &inorder, int iLeft, int iRight, vector<int> &postorder, int pLeft, int pRight) {
        if (pLeft > pRight || iLeft > iRight) return NULL;
        int i = 0;
        for (i = iRight; i >= iLeft; --i) {
            if (postorder[pRight] == inorder[i]) break;
        }
        TreeNode *cur = new TreeNode(postorder[pRight]);
        cur->left = buildTree(inorder, iLeft, i - 1, postorder, pLeft, pLeft + i -1-iLeft);
        cur->right = buildTree(inorder, i+1, iRight, postorder, pRight-1-(iRight-(i+1)), pRight-1);
        return cur;
    }
};