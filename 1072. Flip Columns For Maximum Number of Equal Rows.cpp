class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        //matrix = {{0,0,0},{0,0,1},{1,1,0}};
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 1;
        vector<bool> visited(m, false);
        vector<int> nb(m, -1);
        for(int i=0;i<m;++i){
            if(visited[i])
                continue;
            if(nb[i]==-1)
            {
                for(int k=0;k<n;++k){
                    if(matrix[i][k])
                        ++nb[i];
                }
                ++nb[i];
            }
            int tmp = 1;
            visited[i] = true;
            for(int j=i+1;j<m;++j){
                if(nb[j]==-1){
                    for(int k=0;k<n;++k){
                        if(matrix[j][k])
                            ++nb[j];
                    }
                    ++nb[j];
                }
                if(nb[i]!=nb[j] && nb[i]!=(n-nb[j])){
                    continue;
                }
                bool inverse = false;
                if(matrix[i][0]!=matrix[j][0])
                    inverse = true;
                int k;
                for(k=0;k<n;++k){
                    if((inverse && matrix[i][k]!=matrix[j][k]) || (!inverse && matrix[i][k]==matrix[j][k]))
                        continue;
                    else
                        break;
                }
                if(k==n){
                    visited[j] = true;
                    ++tmp;
                }
            }
            res = max(tmp, res);
        }
        return res;
    }
};