/*dp[i][j] 就是以i结尾，diff为j的长度*/
class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size(), ans = 0;
        vector<unordered_map<int, int>> f(n);
        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++) {
                int s = A[j] - A[i];
                if (f[j].find(s) == f[j].end()) {
                    f[i][s] = 1;
                } else {
                    f[i][s] = f[j][s] + 1;
                }
                ans = max(ans, f[i][s]);
            }
        return ans + 1;
    }
};