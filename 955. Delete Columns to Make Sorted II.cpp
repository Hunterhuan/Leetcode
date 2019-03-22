// 不断的缩小比较的范围。
// 先比较第一column,如果有逆向的，就delete
// 如果有相等的，那么就往后面看，对这些相等的，
// 需要在后面几行中确定大小。如果逆行，那么就删掉。
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int cnt = 0;
        int m = A.size();
        if(!m)
            return cnt;
        vector<bool> flags(m-1); 
        int n = A[0].size();
        for(int j=0; j<n;++j){
            bool flag = false;
            for(int i=0;i<m-1;++i){
                if(!flags[i] &&A[i][j]>A[i+1][j]){
                    cnt++;
                    flag = true;
                    break;
                }
            }
            if(flag)
                continue;
            for(int i=0;i<m-1;++i){
                if(A[i][j] < A[i+1][j])
                    flags[i] = true;
            }
        }
        return cnt;
    }
};