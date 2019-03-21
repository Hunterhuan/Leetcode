// 傻逼一样，这么简单的题还没反应过来。
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profits = 0;
        for(int i=1;i<prices.size();++i){
            if(prices[i]>prices[i-1])
                profits += prices[i]-prices[i-1];
        }
        return profits;
    }
};