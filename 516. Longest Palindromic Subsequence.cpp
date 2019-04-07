// 搞错题意了，下面代码是求连续回文串的
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int res = 1;
        int len = s.size();
        if(len<=1)
            return len;
        vector<vector<bool>> dp(len,vector<bool>(len,false));
        for(int i=0;i<len;++i){
            dp[i][i] = true;
            for(int j=1;j<=i-1;++j){
                if(dp[j][i-1] && s[j-1]==s[i])
                {
                    dp[j-1][i] = true;
                    res = max(i-j+2, res);
                }
            }
        }
        return res;
    }
};

// 这个才是正确answer
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int N = s.size();
        vector<vector<int>> dp(N,vector<int>(N, 0));
        for(int i=s.length()-1;i>=0;i--)
        {
            dp[i][i]=1;
            for(int j=i+1;j<s.length();j++)
            {
                if(s[i]==s[j])
                    dp[i][j]=dp[i+1][j-1]+2;
                else
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
        }
        return dp[0][s.length()-1];
    }
};