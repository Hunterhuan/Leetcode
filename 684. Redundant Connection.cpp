// 用并查集，不断的把所有的点都加进去就行了。
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size();
        int parent[1001] = {};
        for (int i = 0; i < 1001; i++) {    //初始化所有节点的根为自身；
            parent[i] = i;
        }

        for (int i = 0; i < N; i++) {
            vector<int> cur = edges[i];
            int a = cur[0], b = cur[1];
            if (findRoot(parent, a) == findRoot(parent, b)) return cur;  //根节点相同则返回此边
            parent[findRoot(parent, b)] = findRoot(parent, a);  //根节点不同，则修改根节点，连通两个子图
        }
        return {};
    }
    int findRoot(int* parent, int n) {    //寻根方法
        if (parent[n] == n) return n;    //如果某节点的根就是它本身，它则是根节点
        parent[n] = findRoot(parent, parent[n]);    //如果不是，则向上追溯到根节点并修正成新的根节点
        return parent[n];      // 返回修正后的根节点
    }    
};