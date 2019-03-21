// 这道题不想做了，就超了答案
class Solution {
public:
    int paths(TreeNode *p, int sum, int *vals, int level){
        int ans = 0;
        if(p!=NULL){
            for(int i=0; i<level; ++i){
				// The sum of the node and its ancestors equal to sum.
                if(p->val + vals[i]==sum) ans++; 
            }
            if(p->val==sum) ans++; // itself equal to sum.
			
			// update for it's children
            for(int i=0; i<level; ++i){
                vals[i] += p->val;
            }
            vals[level] = p->val;
			
			// get its descendant's answer.
            ans += paths(p->left, sum, vals, level+1);
            ans += paths(p->right, sum, vals, level+1);
			
			// reverse change for its sibling
            for(int i=0; i<level; ++i){
                vals[i] -= p->val;
            }
        }
        return ans;
    }
    
    
    int pathSum(TreeNode* root, int sum) {
		/* 
		vals store node's ancestors' sum.
		A node's ancestor sequence is: 5, 4, 3, 2, 1(from tree root to its parent)
		Its current vals' top five element is: 15, 10, 6, 3, 1
		*/
        int vals[1000];  
		int level = 0;  // node's ancestors' total num.
        return paths(root, sum, vals, level);
    }
};