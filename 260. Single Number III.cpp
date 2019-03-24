// 别人的solution，困难



class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int AXORB = 0;
        for(int num:nums)
            AXORB ^= num;
        // 遍历一遍，那么最后得到的结果是 A xor B.

        // 找到数字A和数字B中不相同的一位。并设置为1，其他设置为0.
        int bitFlag = (AXORB & (~(AXORB - 1)));

        // 那之后的所有的都分为两类了。
        // 该位置为0，和该位置为1的两类。
        // 对每一类来说都是single number I 那道题
        vector<int> res(2,0);
        for(int num:nums){
            if((num & bitFlag)==0)
                res[0] ^= num;
            else
                res[1] ^= num;
        }
        return res;
    }
};