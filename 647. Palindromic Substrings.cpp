// 直接count就行了。第一种思路
class Solution {
public:
    int countSubstrings(string s) {
        int N = s.size(), ans = 0;
        for(int center = 0; center <= 2*N-1;++center){
            int left = center/2;
            int right = left + center %2;
            while(left >=0 && right <N && s[left]==s[right]){
                ans++;
                left--;
                right++;
            }
        }
        return ans;
    }
};


// dp的思路。dp效率却不是很高
class Solution {
public:
    int countSubstrings(string s) {
        int sz = s.size();
        int res = 0;
        if (sz == 0)
            return res;
        // create a 2D DP array: the row represents the start pos of the substring
        // and the column represents the end position of the substring
        // For example: In the string "abcba", dp[1][3] represents the substring "bcb"
        vector<vector<bool>> dp(sz, vector<bool>(sz, false));
        for (int i = 0; i < sz; i++)
        {
            dp[i][i] = true;
            res++;
        }
        
        for (int i = sz-1; i >= 0; i--)
        {
            for (int j = sz-1; j > i; j--)
            {
                // account for palindromes of size 2.
                if (s[i] == s[j] && j-i == 1)
                {
                    dp[i][j] = true;
                    res++;
                }
                // when palindrome size is three or more
                else if (s[i] == s[j] && dp[i+1][j-1] == true)
                {
                    dp[i][j] = true;
                    res++;
                }
            }
        }
        return res;
    }
};