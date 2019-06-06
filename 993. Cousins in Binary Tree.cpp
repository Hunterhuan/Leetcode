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
    bool isCousins(TreeNode* root, int x, int y) {
        if( f(root,x,y)==101 ) return true;
        return false;
    }
private:
    int f(TreeNode* root, int& x, int& y){
        if(!root) return -101;
        if(root->val==x || root->val==y ) return 1;
        
        int l= f(root->left, x,y );
        if(l>100) return l;
        int r= f(root->right,x,y );
        if(r>100) return r;
        if(l>0 && r>0 ){
            if(l==r && l!=1) return 101;
            return -101;
        }
        if(l>0) return l+1;
        if(r>0) return r+1;
        return -101;
        
        
    }
};