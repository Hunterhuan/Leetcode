class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        if (N == 1)
            return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> res;
        for (int i = 1; i <= 9; i++)
            helper(res, i, N - 1, K);
        return res;
    }
    void helper(vector<int>& res, int curint, int N, int K) {
        if (N == 0) {
            res.push_back(curint);
            return;
        }
        int last = curint % 10;
        if (last + K <= 9)
            helper(res, curint * 10 + last + K, N - 1, K);
        if (last - K >= 0 && K)
            helper(res, curint * 10 + last - K, N - 1, K);
    }
};