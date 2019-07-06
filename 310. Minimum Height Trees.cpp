// solution1:
// 从leaves 开始，不断的向根靠拢。
class Solution {
public:
vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
	if (n == 1) {
		return {0};
	}
	vector<int> result;
	vector<vector<int>> graph(n, vector<int>());
	vector<int> degree(n, 0);
	queue<int> leafs;

	for (auto item: edges) {
		graph[item.first].push_back(item.second);
		graph[item.second].push_back(item.first);
		++ degree[item.first];
		++ degree[item.second];
	}

	for (int node = 0; node < n; ++ node) {
		if (degree[node] == 1) {
			leafs.push(node);
		}
	}
	// 学会别人的队列是怎么用的。记录一个初始长度，就知道要pop几次了。
	int left = n;
	while (left > 2) {
		int leaf_size = leafs.size();
		for (int i = 0; i < leaf_size; ++ i) {
			int node = leafs.front();
			leafs.pop();
			-- left;
			for (auto peer_node : graph[node]) {
				-- degree[peer_node];
				if (degree[peer_node] == 1) {
					leafs.push(peer_node);
				}
			}
		}
	}

	while (!leafs.empty()) {
		result.push_back(leafs.front());
		leafs.pop();
	}
	return result;
	}
};


// solution2:
// 随便一个点，找到离他最远的，再找到离这个点最远的。
// 中间就是根
class Solution {
public:
    unordered_map<int, vector<int> > M;
    int N;

    int dfs(int node){
        int max_depth = 0;
        M[node][M[node].size() - 1] = -1;
        for (int i = 0; i < M[node].size() - 1; ++i){
            int next_node = M[node][i];
            if (M[next_node][M[next_node].size() - 1] != 0) continue;
            max_depth = max(max_depth, dfs(next_node) + 1);
        }
        return M[node][M[node].size() - 1] = max_depth;
    }

    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> ret;
        ret.push_back(0);
        if (edges.size() == 0) return ret;
        
        N = n;
        M.clear();
        
        // constract the graph. O(n)
        for (auto p : edges){
            int a = p.first, b = p.second;
            M[a].push_back(b);
            M[b].push_back(a);
        }
        
        // the last element will record the depth of that node
        for (int i = 0; i < N; ++i) M[i].push_back(0);
        
        // treat 0 as root first
        // dfs to get the depth of each node. O(n)
        int depth = dfs(0);
        
        // rotate the root of the tree to get the shortested. O(n)
        int root = 0;
        while (true){
            ret.clear(); 
            ret.push_back(root);
            map<int, int> mii;
            int new_root;
            for (int i = 0; i < M[root].size() - 1; ++i){
                int next_node = M[root][i];
                mii[M[next_node][M[next_node].size() - 1] * -1]++;
                if (mii.begin()->first * -1 == M[next_node][M[next_node].size() - 1]){
                    new_root = next_node;
                }
            }
            map<int, int>::iterator it = mii.begin();
            if (it->second > 1) break;
            
            // transfer the node of deepest sub-tree as the root
            mii.erase(it);
            int last_depth = M[root][M[root].size() - 1];
            if (mii.size()) M[root][M[root].size() - 1] = mii.begin()->first * -1 + 1;
            else M[root][M[root].size() - 1] = 0;
            if (last_depth == M[new_root][M[new_root].size() - 1]){
                ret.push_back(new_root);
                break;
            }
            root = new_root;
        }
        return ret;
    }
};


// 还可以不断的去删叶子节点。一直删直到没有