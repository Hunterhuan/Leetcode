// 自己的solution，试图找到最后的结果，结果TLE了。
// 猜想正确结果应该是通过坐标来直接换算的。
class Solution {
public:
    string decodeAtIndex(string S, int K) {
        string res;
        for(int i=0; i<S.size();++i){
            if(isdigit(S[i])){
                int times = S[i]-'0';
                string s = res;
                for(int j=1;j<times;++j){
                    res += s;
                }
            }
            else{
                res += S[i];
            }
            if(res.size()>K)
                return res.substr(K-1,1);
        }
        return res.substr(K-1,1);
    }
};



// 别人的solution。虽然也没有用到stack
class Solution {
public:
    string decodeAtIndex(string S, int K) {
        long N = 0, i;
        // 先找到K到哪为之
        for (i = 0; N < K; ++i)
            N = isdigit(S[i]) ? N * (S[i] - '0') : N + 1;
        while (i--)
            // 不断得将K缩小。很厉害的方法。想不到想不到
            if (isdigit(S[i]))
                N /= S[i] - '0', K %= N;
            else if (K % N-- == 0)
                return string(1, S[i]);
        return "hb";
    }
};