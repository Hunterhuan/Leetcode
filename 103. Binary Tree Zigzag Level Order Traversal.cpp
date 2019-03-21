// 我用的递归，还可以使用stack来实现，其实就是bfs
#include <stack>
class Solution {
public:
    vector<TreeNode*> add(vector<TreeNode*> layer){
        vector<TreeNode*> nextlayer;
        int length = layer.size();
        for(int i=0;i<length;++i){
            if(layer[i]->left)
                nextlayer.push_back(layer[i]->left);
            if(layer[i]->right)
                nextlayer.push_back(layer[i]->right);
        }
        return nextlayer;
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL)
            return res;
        vector<TreeNode*> layer;
        layer.push_back(root);
        int count=0;
        while(layer.empty()==false){
            vector<int> tmp;
            if(count%2==0){
                for(int i=0;i<layer.size();++i){
                    tmp.push_back(layer[i]->val);
                }
            }
            else{
                for(int i=layer.size()-1; i>=0; --i)
                    tmp.push_back(layer[i]->val);
            }
            count++;
            res.push_back(tmp);
            layer = add(layer);
        }
        return res;
    }
};