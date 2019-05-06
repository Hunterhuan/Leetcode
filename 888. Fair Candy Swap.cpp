class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sa = 0, sb = 0;
        for(auto x:A)
            sa += x;
        for(auto x:B)
            sb += x;
        int delta = (sb-sa)/2;
        unordered_map<int,bool> m;
        for(auto x:B)
            m[x] = true;
        for(auto x:A){
            if(m.find(x+delta)!=m.end())
                return {x,x+delta};
        }
        return {};
    }
};