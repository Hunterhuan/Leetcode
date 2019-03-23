// 因为所有的都有两次，那么 异或之后，都会回复原来的数。
// 0 异或什么，就会变成什么。
// 另外 a xor b xor a = (a xor a) xor b = 0 xor b = b
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum = 0;
        for(auto b:nums)
            sum ^= b;
        return sum;
    }
};