// 递归完成。想到的方法也就这样了。


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node *helper(Node * node, unordered_map<int,Node*>& seen){
        if(!node)
            return NULL;
        auto iter = seen.find(node->val);
        if(iter!=seen.end())
            return iter->second;
        Node * cur_node = new Node(node->val, {});
        seen[node->val] = cur_node;
        for(int i=0;i<(node->neighbors).size();++i){
            cur_node->neighbors.push_back(helper(node->neighbors[i],seen));
        }
        return cur_node;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<int,Node*> seen;
        return helper(node, seen);
    }
};


