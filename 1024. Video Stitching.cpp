// 贪心法。每次都找能到最远的
class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return (a[0]<b[0])||(a[0]==b[0] && a[1]<b[1]);
    }
    int videoStitching(vector<vector<int>>& clips, int T) {
        int N = clips.size();
        sort(clips.begin(), clips.end(), cmp);
        if(clips[0][0]!=0 || clips[N-1][1]<T)
            return -1;
        int end = 0;
        int i = 0;
        int count = 0;
        for(i=0;i<N;){
            ++count;
            int max_end = 0;
            if(clips[i][0] > end)
                break;
            for(;i<N;++i){
                if(clips[i][0]>end)
                    break;
                max_end = max(max_end, clips[i][1]);
            }
            end = max_end;
            if(end>=T)
                return count;
        }
        return -1;
    }
};