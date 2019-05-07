// solution : count by delta.


class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int N = A.size();
        vector<vector<int>> count(2*N+1,vector<int>(2*N+1,0));
        for(int i=0;i<N;++i){
            for(int j = 0;j<N;++j){
                if(A[i][j]==1){
                    for(int i2 = 0;i2<N;++i2){
                        for(int j2 = 0;j2 <N;++j2){
                            if(B[i2][j2]==1)
                                count[i-i2+N][j-j2+N] += 1;
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(auto row:count)
            for(auto v:row)
                ans = max(ans,v);
        return ans;
    }
};