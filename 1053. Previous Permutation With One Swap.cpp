class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int len = A.size();
        if (len<2 || is_sorted(A))
            return A;
        
        int cand = len-2;
        while (cand>=0 && A[cand+1]>=A[cand]){
            cand--;
        }
        
        int sw =swap_with (A, cand+1);
        swap (A[cand], A[sw]);
        return A;
        
    }
    
    int swap_with(vector<int> &A, int left){
        int right= A.size()-1;
        int val = A[left-1];
        int res= left;  
        while (left<=right){
            int mid = left+ (right-left)/2;           
            if (A[mid]<val){           
               if (A[res]<A[mid]) /*the preference for candid_2 is to be on left side as discussed by second example*/
                 res= mid;
               left=mid+1;
            } else
                right = mid-1;
        }
        
        return res;
    }
    bool is_sorted(vector<int> &A){
        for (int i= 1; i<A.size()-1;++i){
            if (A[i-1]>A[i])
                return false;
        }
        return true;
    }
};