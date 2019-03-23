// 我的solution，通过count找到可能符合情况的。再遍历验证
// 效率不高
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        if(A.size()!=B.size())
            return -1;
        //A = {3,5,1,2,3};
        //B = {3,6,3,3,4};
        int n = A.size();
        vector<int> cnt(7,0);
        vector<int> cnt2(7,0);
        for(int i=0;i<n;++i){
            cnt[A[i]]++;
            cnt2[B[i]]++;
        }
        int min_res = INT_MAX;
        for(int i=1;i<7;++i){
            if(cnt[i]+cnt2[i]>=n){
                bool flag = true;
                for(int j=0;j<n;++j){
                    if(A[j]!=i && B[j]!=i){
                        flag = false;
                        break;
                    }
                }
                if(flag)
                    min_res = min(min_res, min(n-cnt[i], n-cnt2[i]));
            }
        }
        return (min_res==INT_MAX)? -1:min_res;
    }
};



// 这个效率也不高
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        if(A.size()!=B.size())
            return -1;
        int len = A.size();
        vector<vector<int>> v(6, vector(3,0));
        for (int i = 0; i < len; i++){
            if (A[i] == B[i]) {
                v[A[i]-1][2]++;
            }
            else {
                v[A[i] - 1][0]++;
                v[B[i] - 1][1]++;
            }
        }
        int ret = INT_MAX;
        for (int i = 0; i < v.size(); i++){
            if (v[i][0]+v[i][1]+v[i][2] == len) {
                ret = min(v[i][0], v[i][1]);
            }
        }
        return ret == INT_MAX? -1 : ret;
    }
};