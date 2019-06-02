class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<int>> graph(N+1, vector<int>(N+1,-1));
        for(auto t:times){
            graph[t[0]][t[1]] = t[2];
        }
        vector<int> delay(N+1,INT_MAX); 
        delay[K] = 0;
        queue<vector<int>> q;
        for(int i=1;i<N+1;++i){
            if(graph[K][i]!=-1)
                q.push({K,i});
        }
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            int d = delay[t[0]] + graph[t[0]][t[1]];
            if(d<delay[t[1]]){
                delay[t[1]] = d;
                for(int i=1;i<N+1;++i){
                    if(graph[t[1]][i]!=-1)
                        q.push({t[1],i});
                }
            }
        }
        int res = 0;
        for(int i=1;i<N+1;++i){
            if(delay[i]==INT_MAX)
                return -1;
            res = max(res, delay[i]);
        }
        return res;
    }
};