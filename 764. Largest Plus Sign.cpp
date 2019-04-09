// 遍历几遍就可以了。
class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<int>> maps(N, vector<int>(N,1));
        for(auto m: mines){
            maps[m[0]][m[1]] = 0;
        }
        for(int i=0;i<N;++i){
            int count = 0;
            for(int j=0; j<N;++j){
                if(maps[i][j]==0)
                    count = 0;
                else{
                    ++count;
                    maps[i][j] = count;
                }
            }
            count = 0;
            for(int j=N-1; j>=0;--j){
                if(maps[i][j]==0)
                    count = 0;
                else{
                    count++;
                    maps[i][j] = min(maps[i][j], count);
                }
            }
            
        }
        for(int i=0;i<N;++i){
            int count = 0;
            for(int j=0; j<N;++j){
                if(maps[j][i]==0)
                    count = 0;
                else{
                    ++count;
                    maps[j][i] = min(count, maps[j][i]);
                }
            }
            count = 0;
            for(int j=N-1; j>=0;--j){
                if(maps[j][i]==0)
                    count = 0;
                else{
                    count++;
                    maps[j][i] = min(maps[j][i], count);
                }
            }
        }
        int res = 0;
        for(int i = 0;i < N ; ++i){
            for(int j=0;j < N ; ++j)
                res = max(res, maps[i][j]);
        }
        return res;
    }
};