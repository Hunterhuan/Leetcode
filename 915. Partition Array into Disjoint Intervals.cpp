class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int len = A.size();
        vector<int> large(len,0);
        vector<int> less(len,0);
        int l = A[0];
        int r = A.back();
        for(int i=0;i<len;++i){
            large[i] = l = max(A[i],l);
            less[len-i-1] = r = min(A[len-i-1],r);
        }
        for(int i=0;i<len-1;++i){
            if(large[i]<=less[i+1])
                return i+1;
        }
        return 0;
    }
};