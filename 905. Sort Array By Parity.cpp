class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int l = 0, r = A.size()-1;
        while(l<r){
            while(l<A.size()-1 && A[l]%2!=1)
                ++l;
            while(r>-1 && A[r]%2==1)
                --r;
            if(l<r){
                int tmp = A[l];
                A[l] = A[r];
                A[r] = tmp;
            }
        }
        return A;
    }
};