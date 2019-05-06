class Solution {
public:
    int minFlipsMonoIncr(string S) {
        //S = "0101100011";
        int len = S.size();
        if(len<=1)
            return 0;
        vector<int> v1(len,0),v2(len,0);
        int sum1=0, sum2=0;
        for(int i=0;i<len;++i){
            v1[i] = sum1;
            v2[len-i-1] = sum2;
            if(S[i]=='1')
                ++sum1;
            if(S[len-i-1]=='0')
                ++sum2;
        }
        int res = INT_MAX;
        for(int i=0;i<len;++i){
            res = min(res, v1[i]+v2[i]);
        }
        return res;
    }
};