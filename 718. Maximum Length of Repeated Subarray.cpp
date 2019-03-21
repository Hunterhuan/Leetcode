// 这种使用动态规划。
// 也是参考了之后才会的
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int res = 0;
        int m = A.size(), n = B.size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        for(int i=0;i<m;++i){
            if(A[i] == B[0])
                dp[i][0] = 1;
        }
        for(int i=0;i<n;++i){
            if(A[0] == B[i])
                dp[0][i] = 1;
        }
        for(int i=1;i<n;++i){
            for(int j=1;j<m;++j){
                if(A[j] == B[i])
                    dp[j][i] = dp[j-1][i-1] + 1;
                res = max(res, dp[j][i]);
            }
        }
        return res;
    }
};

// 别人的简洁代码。很棒。得学会
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int res = 0;
        vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 1; j < dp[i].size(); ++j) {
                dp[i][j] = (A[i - 1] == B[j - 1]) ? dp[i - 1][j - 1] + 1 : 0;
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};