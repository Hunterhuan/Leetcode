// 田忌赛马的道理。
// 对于每个B，从A中找到正好大于他的。剩余的随便排序就行了
class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<int> res(A.size(),-1);
        vector<pair<int,int>> vp;
        for(int i=0;i<B.size();++i)
            vp.push_back(pair<int,int>(B[i],i));
        sort(A.begin(),A.end());
        sort(vp.begin(),vp.end());
        vector<int> r;
        int cnt = 0;
        for(int i=0;i<vp.size();++i){
            while(cnt<A.size()){
                if(A[cnt]>vp[i].first){
                    res[vp[i].second] = A[cnt++];
                    break;
                }
                r.push_back(A[cnt]);
                cnt++;
            }
        }
        cnt = 0;
        for(int i=0;i<res.size();++i){
            if(res[i]==-1){
                res[i] = r[cnt++];
            }
        }
        return res;
    }
};