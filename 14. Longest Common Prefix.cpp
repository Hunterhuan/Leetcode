// 还可使用分治法，来减少比较的次数
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        if(len==0)
            return "";
        string tmp = strs[0];
        int l = tmp.size();
        for(int i=1;i<len;++i){
            for(int j=0;j<l&&j<strs[i].size();++j){
                if(strs[i][j]!=tmp[j]){
                    l = j;
                    break;
                }
            }
            l = min(int(strs[i].size()),l);
        }
        return tmp.substr(0,l);
    }
};