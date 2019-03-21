// 题很简单，很短的代码就能实现
class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p) {
            if(q && p -> val == q -> val) 
                return isSameTree(p -> left, q -> left) && isSameTree(p -> right, q -> right);
            return false;
        } else if(q)
            return false;
        return true;
    }
};