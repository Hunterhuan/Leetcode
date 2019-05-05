// 得分析一下题
class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        for(int i=0;i<A.size();++i){
            if(i!=A[i]){
                if(i!=A[i+1] || A[i]!=(i+1))
                    return false;
                ++i;
            }
        }
        return true;
    }
};