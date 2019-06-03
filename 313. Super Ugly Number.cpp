class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> index(primes.size(),0);
        vector<int> res;
        res.push_back(1);
        --n;
        while(n){
            int min_number = INT_MAX;
            for(int i = 0; i< primes.size();++i){
                int min_n = primes[i] * res[index[i]];
                min_number = min(min_number, min_n);
            }
            for(int i = 0; i< primes.size();++i){
                int min_n = primes[i] * res[index[i]];
                if(min_number == min_n)
                    ++index[i];
            }
            res.push_back(min_number);
            --n;
        }
        return res.back();
    }
};