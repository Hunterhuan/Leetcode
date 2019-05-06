// 双向遍历，找到离左离右都最远的就可以了。
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int len = seats.size();
        vector<int> v1(len,0);
        vector<int> v2(len,0);
        int lastone = -len-10, lastone2 = len+10;
        for(int i=0;i<len;++i){
            if(seats[i]==1){
                lastone = i;
                v1[i] = 0;
            }else{
                v1[i] = i-lastone;
            }
            if(seats[len-i-1]==1){
                lastone2 = len-i-1;
                v2[len-i-1] = 0;
            }else{
                v2[len-i-1] = lastone2-(len-i-1);
            }
        }
        int res = 0;
        for(int i=0;i<len;++i){
            res = max(res, min(v1[i],v2[i]));
        }
        return res;
    }
};