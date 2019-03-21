class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";
        int length = num.length();
        int start = 0;
        int need = k;
        while(res.length()<length-k){
            char tmp = num[start];
            for(int i=start; i<need+res.length()+1;++i){
                if(num[i]<tmp){
                    start = i;
                    tmp = num[i];
                }
            }
            start++;
            res.push_back(tmp);
        }
        while (!res.empty() && res[0] == '0') res.erase(res.begin());
        return res.empty() ? "0" : res;
    }
};