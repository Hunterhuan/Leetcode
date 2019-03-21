/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    void postTravel(TreeNode* root, vector<int>& v){
        if(!root)
            return;
        postTravel(root->left, v);
        v.push_back(root->val);
        postTravel(root->right, v);
    }
public:
    vector<int> v;
    int cur_size;
    BSTIterator(TreeNode* root) {
        postTravel(root, v);
        cur_size = 0;
    }
    
    /** @return the next smallest number */
    int next() {
        int res = v[cur_size++];
        return res;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(cur_size>=v.size())
            return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
