class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // finding solution for day1 => day1&4 => day1&4&6 => ...
        days.insert(days.begin(), 0);
        vector<int> tickets = {1, 7, 30};
        vector<int> dp(days.size(), 0);
        for (int i = 1; i < days.size(); i++) {
            for (int j = 0; j < 3; j++) {
                int start_from = i; // first the first previous date not covered
                while (days[i]-tickets[j]+1 <= days[start_from] && start_from >= 1) start_from -= 1;
                dp[i] = dp[i] == 0 ? dp[start_from] + costs[j] : min(dp[i], dp[start_from] + costs[j]);
            }      
        }
        return dp.back();
    }
};