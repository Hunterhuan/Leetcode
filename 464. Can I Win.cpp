// 辣鸡题
// 不知道别人为什么使用遍历？
// 难道这道题不能直接算的吗？
class Solution {
public:
    vector<int>  DP;
    bool helper(int N, int T, int bitmap, int sum) {
        if (DP[bitmap] != -1)
            return DP[bitmap];
        for (int i = N; i >= 1; --i) {
            int mask = (1 << (i-1));
            if (bitmap & mask) continue;
            
            if (sum+i >= T || !helper(N, T, bitmap|mask, sum+i)) {
                DP[bitmap] = true;
                return true;
            }
        }
        DP[bitmap] = false;
        return false;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int bitmap = 0;
        int N = maxChoosableInteger;
        int T = desiredTotal;
        int sum = 0;
        if (T > (N * (N+1)/2))
            return false;
        
        DP = vector<int>(1<<N, -1);
        return helper(N, T, bitmap, sum);
    }
};