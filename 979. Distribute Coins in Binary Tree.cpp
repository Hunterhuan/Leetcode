// 别人的思路很妙，这道题挺棒的，需要记下来思路


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }
    // 统计把自身，左右子树都平衡，需要移动的coins个数
    void helper(TreeNode* root, int& res) {
        if (!root) return;
        // 左、右子树缺多少
        int left = need(root->left);
        int right = need(root->right);
        //左，右子树和自身都平衡需要的移动数
        res += abs(left) + abs(right);
        helper(root->left, res);
        helper(root->right, res);
    }
    // 为了使该子树均匀，需要的coins数
    // 节点数 - coins
    int need(TreeNode* root) {
        if (!root) return 0;
        if (count_.count(root))
            return count_[root];
        int res = need(root->left) + 1 - root->val + need(root->right);
        count_[root] = res;
        return res;
    }
private:
    unordered_map<TreeNode*, int> count_;
};