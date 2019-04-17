class Solution {
public:
    int knightDialer(int N) {
      const int mod = (int)1e9 + 7;
      std::vector<std::vector<int>> neighbours {
        {4,6}, {6,8}, {7,9}, {4,8}, {3,9,0},
        {}, {1,7,0}, {2,6}, {1,3}, {2,4}
      };
      // dp[i][n] is the number of distint numbers ending with digit i and 
      // having n hops remaining
      std::vector<std::vector<int>> dp(10, std::vector<int>(N));
      // base case
      for (int i = 0; i < 10; ++i) dp[i][0] = 1;
      for (int n = 1; n < N; ++n) {
        for (int i = 0; i < 10; ++i) {
          for (auto v: neighbours[i]) {
            dp[i][n] = (dp[i][n] + dp[v][n-1]) % mod;
          }
        }
      }
      int ans = 0;
      for (int i = 0; i < 10; ++i)
        ans = (ans + dp[i][N-1]) % mod;
      return ans;
    }
};
