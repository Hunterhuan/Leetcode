// 跟power of two 差不多。
class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num<=0)
            return false;
        int cnt = 0;
        for(int i=0;i<32;i++){
            if(i%2==0){
                if(((num>>i)&1)==1)
                    ++cnt;
                if(cnt>=2)
                    return false;
            }
            else{
                if(((num>>i)&1)==1)
                    return false;
            }
        }
        return true;
    }
};