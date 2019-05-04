class Solution {
public:
    int cnt = 0;
    int countArrangement(int N){
        vector<bool> visited(N+1, false);
        calculate(N, 1, visited);
        return cnt;
    }
    void calculate(int N, int pos, vector<bool> & visited){
        if(pos>N)
            ++cnt;
        for(int i=1;i<=N;++i){
            if(!visited[i] && (pos%i ==0 || i%pos ==0)){
                visited[i] = true;
                calculate(N, pos+1, visited);
                visited[i] = false;
            }
        }
    }
};