// 不知道为啥，先把x y xor了都不行。效率那么低。
// 不知道leetcode怎么评的
class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        for(int i=0;i<32;++i){
            if((x^y)&1)
                ++count;
            x = x >> 1;
            y = y >> 1;
        }
        return count;
    }
};