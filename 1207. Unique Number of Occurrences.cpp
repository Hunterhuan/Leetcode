class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int cnt[3000] = {0};
        for(auto n:arr){
            cnt[n+1000]++;
        }
        int pos[2000] = {0};
        for(int i=0;i<3000;++i){
            if(cnt[i]!=0){
                if(pos[cnt[i]])
                    return false;
                pos[cnt[i]] = true;
            }
        }
        return true;
    }
};