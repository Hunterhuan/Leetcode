class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<vector<int>> graph(N+1);
        for(auto path:paths){
            graph[path[0]].push_back(path[1]);
            graph[path[1]].push_back(path[0]);
        }
        vector<int> flowers(N+1,0);
        for(int i=1;i<=N;++i){
            int used = 0;
            for(int k=0; k<graph[i].size();++k)
                used = used | 1<<(flowers[graph[i][k]]);
            flowers[i] = log2(31^used);
        }
        flowers.erase(flowers.begin());
        return flowers;
    }
};

