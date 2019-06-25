/*不会，也不懂，看不懂别人的代码*/

class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
        int N = A.size();
        
        if (N == 3) {
            return accumulate(A.begin(), A.end(), 1, multiplies<int>());
        }
        
        vector<vector<int>> dp(N, vector<int>(N, INT_MAX));
        
        for (int l = 3; l <= N; ++l) {
            for (int s = 0; s <= N - l; ++s) {
                int e = s + l - 1;
                
                for (int p = s + 1; p < e; ++p) {
                    // Divide [s..e] into three polygon - [s..p][p..e][s,p,e]
                    int lhs = (p - s == 1) ? 0 : dp[s][p]; ;
                    int rhs = (e - p == 1) ? 0 : dp[p][e];
                    dp[s][e] = min(dp[s][e], lhs + rhs + A[s] * A[p] * A[e]);
                }
            }
        }
        
        
        return dp[0][N - 1];
    }
};