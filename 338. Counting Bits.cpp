// 不断的迭代产生的。
// eg: 在2-4过程中，就是1-2再加1产生的。

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> bits(num+1, 0);
        int k = 1;
        for (int i = 1; i <= num; ++i) {
            k = i == 2*k ? 2*k : k;
            bits[i] = bits[i-k] + 1;
        }
        return bits;
    }
};