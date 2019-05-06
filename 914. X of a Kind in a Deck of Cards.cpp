// 最大公约数。
class Solution {
public:
    int gcd(int x, int y){
        return x==0? y:gcd(y%x, x);
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        vector<int> v(10000,0);
        for(auto d:deck)
            v[d]++;
        int g = -1;
        for(int i=0;i<10000;++i){
            if(v[i]>0){
                if(g==-1)
                    g = v[i];
                else{
                    g = gcd(g,v[i]);
                }
                if(g<=1)
                    return false;
            }
        }
        return true;
    }
};