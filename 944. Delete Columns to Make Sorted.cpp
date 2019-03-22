// 简单，但效率不是很高
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int cnt = 0;
        if(!A.size())
            return cnt;
        for(int i=0;i<A[0].size();++i){
            for(int j=0;j<A.size()-1;++j){
                if(A[j][i]>A[j+1][i]){
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};