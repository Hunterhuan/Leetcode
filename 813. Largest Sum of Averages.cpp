// largest sum of averages
// 常规思路应该是bfs，这应该对dp问题更加加深认识。
// bfs为什么会TML，就是因为没有存储。
// dp问题就是要记录状态，然后再一步一步的达到最好

class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int N = A.size();
        // 方便求average
        vector<double> P(N+1,0);
        for(int i=0;i<N;++i)
            P[i+1] = P[i] + A[i];
        vector<double> dp(N,0);
        for(int i=0;i<N;++i){
            dp[i] = (P[N]-P[i])/(N-i);
        }
        for(int k = 0; k< K-1;++k){
            for(int i=0;i<N;++i){
                for(int j=i+1; j<N;++j){
                    dp[i] = max(dp[i], (P[j]-P[i])/(j-i) + dp[j]);
                }
            }
        }
        return dp[0];
    }
};