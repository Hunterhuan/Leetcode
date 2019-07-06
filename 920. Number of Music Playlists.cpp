class Solution {
public:
    const long long MOD = (long long) (1e9+7);
    int numMusicPlaylists(int N, int L, int K) {
        long long dp[105][105] = {};
        int i, j;
        dp[0][0] = 1;
        for (i=1; i<=L; i++)
        {
            for (j=1; j<=min(N,i); j++)
            {
                dp[i][j] = dp[i-1][j-1]*(N-j+1);
                dp[i][j] %= MOD;
                dp[i][j] += dp[i-1][j]*max(0, j-K);
                dp[i][j] %= MOD;
            }
        }
        return dp[L][N];
    }
};