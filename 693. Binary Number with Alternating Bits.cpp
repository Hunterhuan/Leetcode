// 交替检验一下就行了
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int i=0;
        for(;i<32;++i){
            if((n>>(31-i))&1)
                break;
        }
        bool flag = true;
        ++i;
        for(;i<32;++i){
            if((n>>(31-i))&1){
                if(flag==false){
                    flag=true;
                }
                else
                    return false;
            }
            else{
                if(flag)
                    flag = false;
                else
                    return false;
            }
        }
        return true;
    }
};