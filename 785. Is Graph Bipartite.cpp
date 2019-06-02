class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1);
        for (int i = 0; i < n; ++i) {
            if (colors[i] == -1) {          // the node i has not been colored, so color it
                if (!BFS(graph, colors, 0, i)) {
                    return false;
                }
            }
        }
        return true;
    }
private:
    bool BFS(vector<vector<int>> &graph, vector<int> &colors, int color, int node) {
        queue<int> q;
        q.push(node);
        colors[node] = color;
        while (!q.empty()) {
            int i = q.front(), c = colors[i];
            q.pop();
            for (auto next : graph[i]) {
                if (colors[next] == -1) {   // not colored, so color it using another color
                    q.push(next);
                    colors[next] = 1 - c;
                }
                else {                      // already colored, so check whether it is compatible
                    if (colors[next] != 1 - c) {
                        return false;
                    }
                }
            }
        }
        return true;
    } 
};