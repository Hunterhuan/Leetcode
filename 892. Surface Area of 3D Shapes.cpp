class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int N = grid.size();
        if(N==0)
            return 0;
        int res = 0;
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                if(grid[i][j]!=0){
                    res += grid[i][j]*6;
                    res -= 2*(grid[i][j]-1);
                    if(i<N-1)
                        res -= 2*min(grid[i][j], grid[i+1][j]);
                    if(j<N-1)
                        res -= 2*min(grid[i][j], grid[i][j+1]);
                }
            }
        }
        return res;
    }
};