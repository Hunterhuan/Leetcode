class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> m;
        int tmp;
        int max_len = 0;
        for(auto a:arr){
            if(m.count(a-difference)){
                tmp = m[a];
                m[a] = max(tmp, m[a-difference]+1);
            }
            else
                m[a] = 1;
            max_len = max(max_len, m[a]);
        }
        return max_len;
    }
};