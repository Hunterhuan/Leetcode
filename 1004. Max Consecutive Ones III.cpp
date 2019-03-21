// 又因为边界问题处理了好久。唉，ε=(´ο｀*)))唉
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int l = -1, r = 0;
        int cnt = 0;
        for(r=0;r<A.size();++r){
            if(!A[r])
                ++cnt;
            if(cnt==K+1)
                break;
        }
        int res = r - l -1;
        while(r<A.size()){
            r++;
            l++;
            while(r<A.size() && A[r]) r++;
            while(l<A.size() && A[l]) l++;
            res = max(res, r-l-1);
        }
        return res;
    }
};