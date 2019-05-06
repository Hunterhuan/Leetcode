class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool inc = true;
        bool dec = true;
        for(int i = 0; i < A.size()-1; i++){
            inc = inc && (A[i+1] >= A[i]);
            dec = dec && (A[i+1] <= A[i]);
        }
        return inc || dec;
    }
};