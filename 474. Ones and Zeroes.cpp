// 类似于背包问题。
// 但这个可以用之前的问题去拓展
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int cnt0, cnt1;
        
        for(auto str:strs) {
            cnt0 = 0;
            cnt1 = 0;
            for(auto c:str) {
                if(c == '0') ++cnt0;
                else ++cnt1;
            }
            
            for(int i=m; i>=cnt0; --i) {
                for(int j=n; j>=cnt1; --j) {
                    dp[i][j] = max(dp[i][j], dp[i-cnt0][j-cnt1]+1);
                }
            }
        }
        
        return dp[m][n];
    }
};