class Solution {
public:
    int fib(int N) {
        vector<int> v(31);
        v[0] = 0;
        v[1] = 1;
        for(int i=2;i<=N;++i){
            v[i] = v[i-1] + v[i-2];
        }
        return v[N];
    }
};