// 递归判断是否符合
class Solution {
public:
    bool sametree(TreeNode* s, TreeNode* t){
        if(!s && !t) return true; // both null
        if(!s || !t) return false; //imbalance
        if(s->val != t->val) return false;
        // values matched
        return sametree(s->left,t->left) && sametree(s->right,t->right);
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s && !t) return true; // both null
        if(!s || !t) return false; // imbalance
        if(sametree(s,t)) return true;
        if (isSubtree(s->left,t) || isSubtree(s->right,t)) return true;
        return false;
    }
};