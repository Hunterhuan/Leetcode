// solution1: dfs 
// 很巧妙的一个方法，作者思路真的很强。
// 在代码中写注释。
class Solution {
public:
    
    int getDown(TreeNode* root, int k, vector<int>&ans) {
        if (!root) return 0;
        if (k == 0) {
            ans.push_back(root->val);
            return 1;
        }
        k--;
        int ret = 0;
        if (root->left) {
            ret += getDown(root->left, k, ans);
        }
        if (root->right) {
            ret += getDown(root->right, k, ans);
        }
        return ret;
    }
    
    int dfs(TreeNode*root, TreeNode* target, int k, vector<int>&ret) {
        // 如果没有找到。就是-1
        if (!root) return -1;
        if (root == target) {
            // getDown 就是把当前节点下面的距离为k的节点加入ret中。
            getDown(target, k, ret);
            return 1;
        }
        // 如果不是-1， 那么d就是距离target 的距离
        int d = dfs(root->left, target, k, ret);
        if (d >= 0) {
            if (d == k) {
                ret.push_back(root->val);
            } else {
                // 如果d小于k，就说明可以向上追溯，那就从另外一个子节点中向下追溯找到距离为k-d-1的节点
                getDown(root->right,   k-d-1, ret);
            }
            return d + 1;
            
        }
        
        d = dfs(root->right, target, k, ret);
        if (d>=0) {
            if (d == k) {
                ret.push_back(root->val);
            } else {
                 getDown(root->left,  k-d-1, ret);
            }
            return d+1;
        }
        
        return -1;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> ret;
        if (!root) return ret;
        dfs(root, target, K, ret);
        return ret;
    }
};


// solution2: 建立反向边，用map建立节点指向父节点的关系
class Solution {
public:
    void build(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&redges) {
        if (!root) return;
        if (root->left) {
            redges[root->left] = root;
            build(root->left, redges);
        }
        if (root->right) {
            redges[root->right] = root;
            build(root->right, redges);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> redges;
        build(root, redges);
        queue< pair<TreeNode*, int> > q;
        q.push( make_pair(target, 0) );
        vector<int> ans;
        
        unordered_set<TreeNode*> visit;
        visit.insert(target);
        
        while (!q.empty()) {
            pair<TreeNode*, int> tp = q.front();
            q.pop();
            if (tp.second == k) {
                ans.push_back( tp.first->val );
                continue;
            }
 
            if (tp.first->left && visit.find(tp.first->left) == visit.end()) {
                q.push(  make_pair(tp.first->left, tp.second + 1)  );
                visit.insert(tp.first->left);
            }
            if (tp.first->right && visit.find(tp.first->right) == visit.end()) {
                q.push(  make_pair(tp.first->right, tp.second + 1)  );
                visit.insert(tp.first->right);
            }
            if (redges.find(tp.first) != redges.end() && visit.find(redges[tp.first]) == visit.end() ) {
                q.push(  make_pair(redges[tp.first], tp.second + 1) );
                visit.insert(redges[tp.first]);
            }
        }
        
        return ans;
    }
};