/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// solution1: no dp
// 自己写dp的时候才发现，很多细节都很棘手，很难处理。
// 这个是不用dp的方案
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return gen(1, n);
    }
    // gen(left, right) 就是从left到right能组成多少种情况
    vector<TreeNode*> gen(int left, int right) {
        if (left > right) return vector<TreeNode*>();
        if (left == right) return { new TreeNode(left) };
        
        vector<TreeNode*> midtrees;
        for (int i = left; i <= right; ++i) {
            // get all left subtrees
            // 左树
            vector<TreeNode*> ltrees = gen(left, i - 1);
            
            // get all right subtrees
            // 右树
            vector<TreeNode*> rtrees = gen(i + 1, right);
            
            int j = 0;
            do {
                int k = 0;
                do {
                    TreeNode* nt = new TreeNode(i);
                    nt->left = j >= ltrees.size() ? NULL : ltrees[j];
                    nt->right = k >= rtrees.size() ? NULL : rtrees[k];
                    
                    midtrees.push_back(nt);
                    ++k;
                } while (k < rtrees.size());
                ++j;
            } while (j < ltrees.size());
        }
        return midtrees;
    }
};



// solution: dp
// 相比于前一个方法，dp就是把中间结果都存了下来
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        vector<TreeNode*> nul = {NULL};
        vector<vector<vector<TreeNode*>>> trees(n);
        // all trees in trees[i][j] contain exactly the numbers from j+1 to j+i+1
        for (int i = 0; i < n; ++i) {
            trees[i].resize(n-i);
            for (int j = 0; j < n-i; ++j) {
                for (int k = 0; k <= i; ++k) {
                    auto jk1 = j+k+1;
                    auto& left = k == 0 ? nul : trees[k-1][j];
                    auto& right = k == i ? nul : trees[i-k-1][jk1];
                    for (auto l : left) for (auto r : right) {
                        trees[i][j].emplace_back(new TreeNode(jk1));
                        trees[i][j].back()->left = l;
                        trees[i][j].back()->right = r;
                    }
                }                    
            }
        }
        return trees.back()[0];
    }
};