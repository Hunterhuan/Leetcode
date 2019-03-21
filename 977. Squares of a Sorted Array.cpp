// 双指针，从两边向中间夹
// reverse() 这个函数要记得
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res;
        int l = 0, r = A.size()-1;
        while(l<=r){
            if(abs(A[l]) > abs(A[r])){
                res.push_back(A[l]*A[l++]);
            }
            else
                res.push_back(A[r]*A[r--]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};