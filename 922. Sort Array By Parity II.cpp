//easy 题，简单
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> res(A.size());
        int odd = 1, even = 0;
        for(int i=0;i<A.size();++i){
            if(A[i]%2){
                res[odd] = A[i];
                odd += 2;
            }
            else{
                res[even] = A[i];
                even += 2;
            }
        }
        return res;
    }
};