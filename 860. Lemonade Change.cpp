// 找零钱的问题。easy，竟然把顺序搞错了。应该优先找大的。
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> v(2,0);
        for(int i=0;i<bills.size();++i){
            if(bills[i]==20){
                if(v[0]>=1 && v[1]>=1){
                    v[0]--;
                    v[1]--;
                }
                else if(v[0]>=3){
                    v[0]-=3;
                }
                else
                    return false;
            }
            else if(bills[i]==10){
                if(v[0]>=1)
                    v[0]-=1;
                else
                    return false;
                v[1]+=1;
            }
            else if(bills[i]==5)
                v[0]+=1;
        }
        return true;
    }
};