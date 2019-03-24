// 看看hamming distance 就可以了。
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
            return false;
        int cnt = 0;
        for(int i=0;i<32;++i){
            if(n>>i&1)
                ++cnt;
            if(cnt>=2)
                return false;
        }
        return true;
    }
};