// 又是莫名其妙的错误。难道必须要左右结果出来一个return一个？
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root){
            return false;
        }
        if(root->left == NULL && root->right==NULL){
            if(sum==root->val)
                return true;
            else
                return false;
        }
        bool left,right;
        sum = sum - (root->val);
        if(root->left){
            left = hasPathSum(root->left, sum);
            if(left)
                return true;
        }
        if(root->right){
            right = hasPathSum(root->right, sum);
            if(right)
                return true;
        }
        return false;
    }
};


// 别人的思路简洁明了
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == nullptr) return false;
        if(root->left == nullptr && root->right == 0){
            if(root->val == sum) return true;
            else return false;
        }
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
};
