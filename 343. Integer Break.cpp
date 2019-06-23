// 数学推导发现拆成3份是最好的。
class Solution {
public:
    int integerBreak(int n) {
        int *dp;
        dp=new int [n+1];
        dp[1]=1;
        for(int i=2;i<=n;++i)
            dp[i]=0;
        for(int i=2;i<=n;++i)
        {
            for(int j=1;j<i;++j)
            {
                dp[i]=max(dp[i],max(j,dp[j])*max(i-j,dp[i-j]));
            }
        }
        return dp[n];
    }
};