/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


// 利用dfs去遍历，然后每得出一个结果就检车一下是否最小就行了。

class Solution {
private:
    string res = "";
public:
    string smallestFromLeaf(TreeNode* root) {
        if(!root) return "";
        traversal(root,"");
        reverse(res.begin(),res.end());
        return res;
    }
    void traversal(TreeNode* node, string path){
        if(!node) return;
        path.push_back(node->val+'a');
        if(!node->left && !node->right)
            if(res == "") res = path;
            else res = lexicographic_check(path,res);
        else{
            traversal(node->left,path);
            traversal(node->right,path);
        }
    }
    string lexicographic_check(string compareA, string compareB){
        int indexA = compareA.length()-1;
        int indexB = compareB.length()-1;
        while(compareA[indexA] == compareB[indexB] && indexA >= 0 && indexB >= 0) 
            indexA--,indexB--;
        if(indexA * indexB < 0){
            if(indexA == -1) return compareA;
            else return compareB;
        }
        else
            return (compareA[indexA] < compareB[indexB] ? compareA : compareB);
    }
};