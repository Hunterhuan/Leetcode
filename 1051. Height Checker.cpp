class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> heights_tmp = heights;
        sort(heights_tmp.begin(), heights_tmp.end());
        int res = 0;
        for(int i=0;i<heights.size();++i){
            if(heights[i]!=heights_tmp[i])
                ++res;
        }
        return res;
    }
};