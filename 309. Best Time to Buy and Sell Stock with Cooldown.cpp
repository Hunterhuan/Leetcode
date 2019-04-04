// 使用状态机
// 对于不同的状态，可以用多个数组，在不同的状态之间转移。
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<=1)
            return 0;
        vector<int> s0(n,0),s1(n,0),s2(n,0);
        s1[0] = -prices[0];
        s2[0] = INT_MIN;
        for(int i=1;i<n;++i){
            s0[i] = max(s0[i-1],s2[i-1]);
            s1[i] = max(s1[i-1],s0[i-1]-prices[i]);
            s2[i] = s1[i-1] + prices[i];
        }
        return max(s0[n-1],s2[n-1]);
    }
};