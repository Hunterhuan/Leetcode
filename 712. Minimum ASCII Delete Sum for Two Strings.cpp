// 直接抄的solution
// 这个容易理解
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) 
    {
        // dp[i][j] 就是表示前i和前j要删掉多少才能相等
        int m = s1.length(), n = s2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++)
            dp[i][0] = dp[i - 1][0] + (int)(s1[i-1]);
        for (int i = 1; i <= n; i++)
            dp[0][i] = dp[0][i-1] + (int)(s2[i-1]);
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(dp[i - 1][j] + (int)s1[i-1], dp[i][j - 1] + (int)s2[j-1]);
            }
        }
        return dp[m][n];
    }
};