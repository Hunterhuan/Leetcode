// 每次找到一个最小的subarray
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        vector<int> pos(26);
        for(int i=0;i<S.size();++i)
            pos[S[i]-'a'] = i;
        for(int i=0;i<S.size();++i){
            int index = pos[S[i]-'a'];
            int j = i;
            while(j<=index)
            {
                index = max(pos[S[j]-'a'], index);
                ++j;
            }
            res.push_back(index-i+1);
            i = index;
        }
        return res;
    }
};