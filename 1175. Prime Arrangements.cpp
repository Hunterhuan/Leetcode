class Solution {
public:
    int MOD = 1e9+7;
    int numPrimeArrangements(int n, int primes=1, long long ans=1) { // 2 is the first prime
        for (auto i=3; i <= n; ++i) {
            if (isPrime(i)) {
                ++primes;
            }
        }
        for (auto i=1; i <= primes; ++i) { // all permutations of primes == factorial of primes
            ans = ans * i % MOD;
        }
        for (auto i=1; i <= n - primes; ++i) { // all permutations of non-primes == factorial of non-primes
            ans = ans * i % MOD;
        }
        return ans;
    }
private:
    bool isPrime(int n) {
        for (auto i=2; i*i <= n; ++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
};