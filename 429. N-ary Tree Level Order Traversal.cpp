/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int len = q.size();
            vector<int> tmp;
            for(int i=0;i<len;++i){
                auto n = q.front();
                tmp.push_back(n->val);
                q.pop();
                for(int j=0;j<n->children.size();++j){
                    q.push(n->children[j]);
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};