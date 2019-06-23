// 思路跟之前那个二分图是一样的。 把dislike的建图，然后进行二分染色。直到冲突
class Solution {
public:
    vector<vector<int>> graph;
    unordered_map<int, int> colors;

    bool dfs(int i, int color){
        auto it = colors.find(i);
        if (it != colors.end())
            return it->second == color;

        colors[i] = color;
        for (int j: graph[i]){
            if (!dfs(j, (color+1)%2))
                return false;
        }
        return true;
    }

    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        graph.resize(N+1);
        for (auto& d: dislikes){
            graph[d[0]].push_back(d[1]);
            graph[d[1]].push_back(d[0]);
        }

        for (int i=1;i<=N;++i)
            if (colors.find(i) == colors.end() && !dfs(i, 0))
                return false;

        return true;
    }
};

