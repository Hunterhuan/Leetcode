class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int sum = 0;
        for(auto a:A)
            if(a%2==0)
                sum += a;
        vector<int> res;
        for(auto v:queries){
            if(A[v[1]]%2==0){
                sum -= A[v[1]];
            }
            A[v[1]] += v[0];
            if(A[v[1]]%2==0)
                sum += A[v[1]];
            res.push_back(sum);
        }
        return res;
    }
};