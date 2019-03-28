// dp 存下来，跟自己的思路完全一样
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<=n;++i){
            for(int j=0;j<=i-1;++j){
                dp[i] += dp[j]*dp[i-1-j];
            }
        }
        return dp[n];
    }
};