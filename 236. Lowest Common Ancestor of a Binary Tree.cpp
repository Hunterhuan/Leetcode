// 这个是别人的思路，我打算再想一种思路
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return NULL;
        }
        if(root == p || root == q){
            return root;
        }
        TreeNode *left = lowestCommonAncestor(root->left,p,q);
        TreeNode *right = lowestCommonAncestor(root->right,p,q);
        if(left && right){
            return root;
        }
        return (left?left:right);
    }
};

// 很遗憾，自己的没有AC。难受。以后这个题还要从新做
/*class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;
        stack<pair<TreeNode *, int>> s;
        int type = 0
        s.push(make_pair(root, type));
        while(!s.empty()){
            TreeNode * tmp = s.top().first;
            s.pop();
            if(tmp==p || tmp == q){
                if(type==1){
                    while(true){
                        if(s.top().second==0)
                            return s.top().first;
                        s.pop();
                    }
                }
                ++type;
            }
            if(tmp->left)
                s.push(make_pair(tmp->left,type));
            if(tmp->right)
                s.push(make_pair(tmp->right, type))
        }
        return NULL;
    }
};*/