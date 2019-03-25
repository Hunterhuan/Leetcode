// 对这个数前缀0，就按1填进去。
// 一旦开始有1存在，后面就copy进去就行了。
// 最后再反转一下。
class Solution {
public:
    int findComplement(int num) {
        int i=0;
        int res = 0;
        for(;i<32;++i){
            if((num>>(31-i))&1)
                break;
            res+=1;
            res = res<<1;
        }
        for(;i<32;++i){
            if((num>>(31-i))&1)
                ++res;
            if(i==31)
                break;
            res = res<<1;
        }
        res = ~res;
        return res;
    }
};