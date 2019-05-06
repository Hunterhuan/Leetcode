class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int len = A.size();
        if(len<3)
            return false;
        int i = 0;
        while(i<A.size()){
            if(i==A.size()-1||A[i]>=A[i+1])
                break;
            i++;
        }
        if(i==len-1 || i==0)
            return false;
        int j = len-1;
        while(j>=0){
            if(j==0 || A[j]>=A[j-1])
                break;
            j--;
        }
        return i==j;
    }
};