// 很简单，每次二分就可以了
class Solution {
public:
    TreeNode* getTree(vector<int>&nums, int begin, int end){
        if(begin==end)
            return NULL;
        int middle = (begin+end)/2;
        TreeNode * node = new TreeNode(nums[middle]);
        node->left = getTree(nums, begin, middle);
        node->right = getTree(nums, middle+1, end);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)
            return NULL;
        int len = nums.size();
        TreeNode* root = getTree(nums, 0,len);
        return root;
    }
};