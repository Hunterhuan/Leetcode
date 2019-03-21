// 思路很清晰。难度不高
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int cur = 0;
        int res = 0;
        int i = 0;
        while(i<g.size() && cur<s.size()){
            if(g[i]<=s[cur]){
                ++res;
                ++i;
            }
            ++cur;
        }
        return res;
    }
};