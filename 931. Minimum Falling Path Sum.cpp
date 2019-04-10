// 很简单的题
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int N = A.size();
        if(N==1)
            return A[0][0];
        for(int j = 1; j<N;++j){
            A[j][0] += min(A[j-1][0], A[j-1][1]);
            for(int i=1; i < N-1; ++i){
                A[j][i] += min(A[j-1][i-1],min(A[j-1][i], A[j-1][i+1]));
            }
            A[j][N-1] += min(A[j-1][N-1], A[j-1][N-2]);
        }
        int res = INT_MAX;
        for(auto a : A[N-1])
            res = min(res, a);
        return res;
    }
};