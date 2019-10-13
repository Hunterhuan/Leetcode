class Solution {
public:
    int balancedStringSplit(string s) {
        int cnt = 0;
        int res = 0;
        for(auto c:s){
            if(c=='L')
                ++cnt;
            else
                --cnt;
            if(cnt==0)
                ++res;
        }
        return res;
    }
};