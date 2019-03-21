// 类似于计算金字塔，别人的answer没有包括存储下来，我加进去之后，就效率更高了。但遇到了bug，后来发现是忘了把N-1
class Solution {
public:
    vector<TreeNode*> search(vector<vector<TreeNode*>> &all, vector<bool> &visited, int N){
        if(visited[N-1])
            return all[N-1];
        
        for(int i=1; i<N-1; i+=2){
            for(auto  &left: search(all, visited, i)){
                for(auto  &right: search(all, visited, N-i-1)){
                    TreeNode * root = new TreeNode(0);
                    root->left = left;
                    root->right = right;
                    all[N-1].push_back(root);
                }
            }
        }
        visited[N-1] = true;
        return all[N-1];
    }
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<vector<TreeNode*>> all(N);
        vector<bool> visited(N, false);
        all[0].push_back(new TreeNode(0));
        visited[0] = true;
        return search(all, visited, N);
    }
};