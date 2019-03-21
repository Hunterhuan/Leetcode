

//这个跟之前一样，都是记录下来存的.只不过用的是set
class Solution {
public:
set<int>values;
bool findTarget(TreeNode* root, int k) {
    
    if(!root) return 0;
    
    if(values.find(k-root->val)!=values.end()) return 1;
    values.insert(root->val);
return findTarget(root->right,k) ||findTarget(root->left,k);   
}
};

//先先序遍历，得到有序的，然后再O(n)遍历
class Solution {
public:
    void inorder(TreeNode *root, vector<int>& res){
        if(root==NULL)
            return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
bool findTarget(TreeNode* root, int k) {
    vector<int> list;
    inorder(root, list);
    int left=0, right = list.size()-1;
    while(left < right){
        int sum = list[left] + list[right];
        if(sum == k)
            return true;
        else if(sum < k)
            left ++;
        else
            right--;
    }
    return false;
}
};