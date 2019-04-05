// 想到尝试bfs，发现gg了
// 如果零钱很小的时候，会超时
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount<=0)
            return 0;
        int res = 1;
        queue<int> q;
        q.push(amount);
        while(!q.empty()){
            int n = q.size();
            while(n--){
                int tmp = q.front();
                q.pop();
                for(int i=0;i<coins.size();++i){
                    if(tmp-coins[i]==0)
                        return res;
                    else if(tmp-coins[i]>0)
                        q.push(tmp-coins[i]);
                }
            }
            ++res;
        }
        return -1;
    }
};


// 一维dp
// 但自己的效率不是很高，遇到了很多bug

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0)
            return 0;
        vector<int> dp(amount+1,INT_MAX);
        for(int i=0;i<coins.size();++i)
            if(coins[i]<=amount)
                dp[coins[i]] = 1;
        for(int i=1;i<=amount;++i){
            for(int j=0;j<coins.size();++j){
                if(i-coins[j] >=1 && dp[i-coins[j]]!=INT_MAX)
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);
            }
        }
        if(dp[amount]==INT_MAX)
            return -1;
        return dp[amount];
    }
};

// 另一个思路，遍历的顺序不一样
#define BIG_NUM 1000
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<int> DP(amount+1,BIG_NUM);
        DP[0]=0; 
        
        for (auto coin : coins)
            for (int i = coin; i <= amount; i++)
                DP[i]=std::min(DP[i],DP[i-coin]+1); 
        
        return DP[amount]==BIG_NUM ? -1 : DP[amount]; 
    }
};