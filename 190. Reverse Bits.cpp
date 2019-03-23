// 我的solution
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(int i=0;i<31;++i){
            res |= (n&1);
            n >>= 1;
            res <<= 1; 
        }
        res |= (n&1);
        return res;
    }
};

// 别人的效率极高
// 从两端。厉害
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
      uint32_t result = 0;
        for(int i = 0; i < 16; ++i) {
          result |= ((n & (1 << i)) << (31 - 2*i));
          result |= ((n & (1 << (31 - i))) >> (31 - 2*i));
        }
      
      return result;
    }
};