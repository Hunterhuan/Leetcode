class Solution {
public:
    int countDigitOne(int n) {
        int cnt = 0;
        long long int base = 1;
        int numberLower = 0;
        while(n>0){
            int curr = n % 10;
            if(curr > 1)
                cnt += base;
            else if(curr == 1)
                cnt += (numberLower + 1);
            n /= 10;
            cnt += n*base;
            numberLower += curr*base;
            base *= 10;
        }
        return cnt;
    }
};
