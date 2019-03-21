// dp问题。找到前i最小的。

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;
        int sell = 0;
        for(int i=0;i<prices.size();++i){
            buy = min(prices[i],buy);
            sell = max(sell, prices[i]-buy);
        }
        return sell;
    }
};