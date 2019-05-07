class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int len = A.size();
        A[len-1] += K;
        int r = 0;
        for(int i=len-1;i>=0;--i){
            A[i] += r;
            r = A[i]/10;
            A[i] %= 10;
            if(r==0)
                break;
        }
        while(r!=0){
            A.insert(A.begin(),r%10);
            r = r/10;
        }
        return A;
    }
};