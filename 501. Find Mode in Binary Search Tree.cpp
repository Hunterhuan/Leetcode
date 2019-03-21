// 没想到一个easy的题都想不出简单的思路，还最后看的别人的代码。
// 一定要学会用unordered_map, 这个STL非常有用。
// 最妙的是别人用 中序遍历 来利用unordered_map不排序的特性。
// 一定要重新做的
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        int mx = 0;
        unordered_map<int, int> m; 
        inorder(root, m, mx);
        for (auto a : m) {
            if (a.second == mx) {
                res.push_back(a.first);
            }
        }
        return res;
    }
    void inorder(TreeNode* node, unordered_map<int, int>& m, int& mx) {
        if (!node) return;
        inorder(node->left, m, mx);
        mx = max(mx, ++m[node->val]);
        inorder(node->right, m, mx);
    }
};