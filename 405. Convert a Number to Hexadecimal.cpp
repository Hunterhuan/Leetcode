// 每check4位，就加到字符串里面。
class Solution {
public:
    string toHex(int num) {
        vector<char> dic = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        string res;
        for(int i=0;i<8;++i){
            int tmp = 0;
            int time = 1;
            for(int j=0;j<4;++j){
                tmp += time*(num&1);
                num = num>>1;
                time = time<<1;
            }
            res = dic[tmp]+res;
        }
        int count = 0;
        while(count<8 && res[count]=='0')
            ++count;
        if(count==8)
            return "0";
        res.erase(0,count);
        return res;
    }
};