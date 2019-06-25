// dp solution
// 自己一直在想，怎么
//cash, the maximum profit we could have if we did not have a share of stock, and 
//hold, the maximum profit we could have if we owned a share of stock.
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int cash = 0, hold = -prices[0];
        for(int i=1;i<prices.size();++i){
        	// from i to i+1
        	// maybe sell our stock
            cash = max(cash, hold + prices[i] - fee);
            // maybe buy a stock
            hold = max(hold, cash - prices[i]);
        }
        return cash;
    }
};


// 贪心算法
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if(n<2)
            return 0;
        int ans = 0;
        int minimum = prices[0];
        for(int i = 1;i<n;++i){
            // minimum 记录当前的最小值，其实就是买入点
            if(prices[i] < minimum)
                minimum = prices[i];
            // 如果盈利大于fee 的话，就可以卖出
            else if(prices[i]>minimum + fee){
                ans += prices[i] -fee-minimum;
                // 然后minimum设为当前减去fee
                minimum = prices[i] - fee;
            }
        }
        return ans;
    }
};