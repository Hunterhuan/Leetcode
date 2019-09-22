class Solution {
    typedef long long ll;
    ll ab,ac,bc,abc;
    ll gcd(ll a, ll b) {
        if(b == 0) return a;
        else return gcd(b, a % b);
    }
    ll gcb(ll a, ll b){
        return a*b/gcd(a, b);
    }
    ll rongchi(ll N, ll a, ll b, ll c){
        return N/a + N/b + N/c - N/ab - N/ac - N/bc + N/abc;
    }
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        ab = gcb(a, b);
        ac = gcb(a, c);
        bc = gcb(b, c);
        abc = gcb(ab, c);
        
        ll left = 1;
        ll right = 2000000001;
        
        while(left < right){
            ll mid = (left + right)/2;
            ll num = rongchi(mid, a, b, c);
            if(num >= n){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }
};