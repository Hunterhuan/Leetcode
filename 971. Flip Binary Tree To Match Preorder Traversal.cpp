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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> res;
        int idx = 0;
        traversal(root,voyage,res,idx);
        return res;
    }
    void traversal(TreeNode* root, vector<int>& voyage, vector<int>& res, int& idx){
        if(!root) return;
        if(root->val != voyage[idx]){
            res = {-1};
            return;
        }
        else{
            if(root->left){
                if(voyage[idx+1]!= root->left->val){ // if current left child is not the same as voyage, swap it!
                    res.push_back(root->val);
                    swap(root->left,root->right);
                }
                if(root->left) // in case left swap with a null right child
                    traversal(root->left,voyage,res,++idx);
            }
            /*
            1. if we swap left, it mean current configuration for left is right, we don't need to check right child
            2. if we didn't have any operation on left child, it means that left child is already fine
            Either case, we don't need to check right node, next recursion will take care of that.
            */
            if(root->right)
                traversal(root->right,voyage,res,++idx);
        }
    }
};