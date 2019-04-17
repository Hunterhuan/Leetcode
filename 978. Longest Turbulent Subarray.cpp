class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int N = A.size();
        if(N<2)
            return N;
        int left = 0, right = 1;
        int max_len = 1;
        while(right<N){
            bool flag = (A[right]>A[left]);
            while(right < N){
                if(flag && A[right]>A[right-1]){
                    right++;
                    flag = false;
                }
                else if(!flag && A[right]<A[right-1]){
                    right++;
                    flag = true;
                }
                else
                    break;
            }
            max_len = max(max_len, right-left);
            if(right==N)
                break;
            if(A[right]==A[right-1]){
                left = right;
                right = left +1;
            }
            else{
                left = right-1;
            }
        }
        return max_len;
    }
};



class Solution {
public:
    int compare(int x, int y){
        return (x < y) ? -1 : ((x == y) ? 0 : 1);
    }
    
    int maxTurbulenceSize(vector<int>& A) {
        int N = A.size();
        int ans = 1;
        int anchor = 0;
        
        for(int i=1; i<N;++i){
            int c = compare(A[i-1], A[i]);
            if(c==0)
                anchor = i;
            else if(i==N-1 || c*compare(A[i], A[i+1])!=-1){
                ans = max(ans, i-anchor + 1);
                anchor = i;
            }
        }
        return ans;
    }
};
