/*想太简单了，想着就是一直碰撞就行了。
最后别人分析认为这就是一道背包问题
就是在求 是否能够把所有的石块分成两部分，这两部分重量和的差值最小的一道题。
换成背包问题就是在sum/2的限制下，最多能装多少重量。*/


class Solution
{
public:
    int lastStoneWeightII(vector<int>& stones)
    {
        int sum = accumulate(stones.begin(),stones.end(),0);
        vector<bool> dp(sum/2,0);
        dp[0]=1;
        for(int s:stones)
            for(int j=sum/2;j>=s;j--)
                dp[j] = dp[j]|dp[j-s];
        int res = sum;
        for(int i=0;i<=sum/2;i++)
            res = min(res, sum-dp[i]*i*2);
        return res;
    }
};