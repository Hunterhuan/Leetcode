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
    vector<int> sq1;
    vector<int> sq2;
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        getLeaf(root1, sq1);
        getLeaf(root2, sq2);
        int len1 = sq1.size();
        int len2 = sq2.size();
        if(sq1 == sq2){
            return true;
        }
        else{
            return false;
        }

    }

    void getLeaf(TreeNode* root, vector<int> &sq){
        if(!root){
            return;
        }
        else{
            if(!root->left && !root->right){
                sq.push_back(root->val);
            }
            if(root->left){
                getLeaf(root->left, sq);
            }
            if(root->right){
                getLeaf(root->right, sq);
            }
        }
    }
};