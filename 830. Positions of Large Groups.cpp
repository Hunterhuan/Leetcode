// two pointers 很简单
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> res;
        int i=0, N = S.size();
        for(int j=0;j<N;++j){
            if(j==N-1 || S[j]!=S[j+1]){
                if(j-i+1>=3)
                    res.push_back({i,j});
                i = j+1;
            }
        }
        return res;
    }
};