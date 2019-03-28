// 这种垃圾题都能写这么久
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n==0)
            return 0;
        for(int i=1;i<n;++i){
            triangle[i][0] += triangle[i-1][0];
            for(int j=1;j<i;++j){
                triangle[i][j] += min(triangle[i-1][j],triangle[i-1][j-1]);
            }
            triangle[i][i] += triangle[i-1][i-1];
        }
        int res = INT_MAX;
        for(int i=0;i<n;++i)
            res = min(res, triangle[n-1][i]);
        return res;
    }
};