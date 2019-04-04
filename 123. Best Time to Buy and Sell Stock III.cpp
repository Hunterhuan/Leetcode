// solution1
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sell1 = 0, sell2 = 0, buy1 = INT_MIN, buy2 = INT_MIN;
        for(auto price: prices){
        	// 第一次买过的资产
            buy1 = max(buy1, -price);
            // 第一次卖的资产
            sell1 = max(sell1, buy1+price);
            // 第二次买
            buy2 = max(buy2, sell1-price);
            // 第二次卖
            sell2 = max(sell2, buy2+price);
        }
        return sell2;
    }
};


// solution2：一维dp
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if(n==0)
			return 0;
		vector<int> dp(n,0);
		int tmp = 0;
		for(int i=1;i<=2;i++){
			int balance = -prices[0];
			tmp = dp[0];
			for(int j=1;j<n;++j){
				int copy = dp[j];
				dp[j] = max(dp[j-1], balance + prices[j]);
				balance = max(balance, tmp-prices[j]);
				tmp = copy;
			}
		}
		return dp[n-1];
	}
};


// solution3: 二维dp
// 效率最高
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if(n==0)
			return 0;
		vector<vector<int>> dp(3,vector<int>(n,0));
		for(int i=1;i<=2;++i){
			int balance = -prices[0];
			for(int j=1;j<n;++j){
				dp[i][j] = max(dp[i][j-1],balance+prices[j]);
				balance = max(balance, dp[i-1][j-1]-prices[j]);
			}
		}
		return dp[2][n-1];
	}
};