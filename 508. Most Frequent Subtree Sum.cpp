// 跟501类似，练习了一次unordered_map 的使用，棒

class Solution {
public:
    int find(TreeNode * root, unordered_map<int, int>& m, int &mx){
        if(!root)
            return 0;
        int sum = find(root->left, m, mx) + find(root->right, m, mx) + root->val;
        mx = max(mx, ++m[sum]);
        return sum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> res;
        int mx = 0;
        unordered_map<int, int> m;
        find(root, m, mx);
        for(auto a: m){
            if(a.second == mx){
                res.push_back(a.first);
            }
        }
        return res;
    }
};