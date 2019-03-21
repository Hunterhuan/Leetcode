// sort思路
// 开始想到了这种solution。但没有动手去写。
// 以后想到了思路就要确定下来。不能在心里含糊。脑子不清晰
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
    vector<pair<int, int>> memo;
    //利用pair 存下difficulty和profit的对应关系，便于排序
    for (int i = 0; i < difficulty.size(); i++) 
        memo.push_back(make_pair(difficulty[i], profit[i]));
    sort(memo.begin(), memo.end());
    sort(worker.begin(), worker.end());
    int last = 0;
    int res = 0,j=0;
    for (int i = 0; i <worker.size(); i++) {
        // 对于每一个worker，找到对应的difficulty，找到对应的最大的profit
        while (j < difficulty.size() && worker[i] >= memo[j].first) { 
            last = max(last, memo[j].second);
            j++;
        }
        // 如果能批量+profit的话，估计能再省些time
        if (j <=difficulty.size()) res += last;
    }
    return res;      
    }
};



// dp思路
// dp思路很有趣。是个挺棒的方法。memory 用的稍多
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<int> dp(100000, 0);
        for (int i = 0; i < difficulty.size(); i++) {
            dp[difficulty[i]] = max(profit[i], dp[difficulty[i]]);
        }
        for (int i = 1; i < dp.size(); i++) {
            dp[i] = max(dp[i], dp[i-1]);
        }
        
        int ans = 0;
        for (int i=0; i < worker.size(); ++i) {
            ans += dp[worker[i]];
        }
        return ans;
    }
};