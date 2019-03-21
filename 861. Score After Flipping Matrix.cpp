// 先从row变换，把首位全flip成1
// 然后对于每column，变换使1最多，就可以了。
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size();
        if(m==0)
            return 0;
        int n = A[0].size();
        int sum = 0;
        for(int i=0;i<m;++i){
            if(A[i][0]==0){
                for(int j=0;j<n;++j)
                    A[i][j] = (!A[i][j]);
            }
        }
        sum += (1<<(n-1))*m;
        for(int i=1;i<n;++i){
            int count = 0;
            for(int j=0;j<m;++j){
                if(A[j][i]==0)
                    ++count;
            }
            sum += (1<<(n-i-1))*max(count, m-count);
        }
        return sum;
    }
};