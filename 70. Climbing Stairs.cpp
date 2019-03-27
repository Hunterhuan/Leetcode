// 不要忘了n=1
class Solution {
public:
    int climbStairs(int n) {
        //n=3;
        if(n==1)
            return 1;
        vector<int> dp(n+1,0);
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3;i<=n;++i){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};