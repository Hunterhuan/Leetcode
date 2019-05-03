// 第一个solution，效率低。 复杂度为O(mmn)

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m==0)
            return 0;
        int n = matrix[0].size();
        int res = 0;
        if(n==0)
            return 0;
        vector<vector<int>> v(m,vector<int>(n,0));
        for(int i=0;i<m;++i){
            int count = 0;
            for(int j=0;j<n;++j){
                if(matrix[i][j]=='0')
                    count = 0;
                else{
                    v[i][j] = ++count;
                    int min_len = v[i][j];
                    for(int k=i;k>=0&&min_len!=0;--k){
                        min_len = min(v[k][j],min_len);
                        res = max(res, min_len*(i-k+1));
                    }
                }
            }
        }
        return res;
    }
};