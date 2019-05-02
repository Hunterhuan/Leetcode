// 很简单
class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.size()!=B.size()){
            return false;
        }
        if(A.size()==0)
            return true;
        A = A + A;
        if(A.find(B)!=(-1))
            return true;
        return false;
    }
};
