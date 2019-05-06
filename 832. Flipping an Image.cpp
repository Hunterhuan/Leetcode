class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int>> res = A;
        for(int i=0;i<A.size();++i){
            int len = A[0].size();
            for(int j=0;j<A[0].size();++j){
                res[i][j] = !A[i][len-1-j];
            }
        }
        return res;
    }
};