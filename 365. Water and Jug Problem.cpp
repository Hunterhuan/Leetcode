// 当即想到dfs。但不是最终结果。
// 结果竟然是找最大公约数
// 因为一定存在  z = m*x + n*y
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        return z == 0 || (x + y >= z && z % gcd(x, y) == 0);
    }
    int gcd(int x, int y) {
        return y == 0 ? x : gcd(y, x % y);
    }
};