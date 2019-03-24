// 感觉跟之前的那个 给a和b，看怎么操作能相等的题有点像。
class Solution {
public:
    int integerReplacement(long n) {
        int count = 0;
        while(n != 1){
            if(n % 2 == 0) n = n / 2;
            else if((n / 2) % 2 == 0 || n / 2 == 1)
                n = n - 1;
            else
                n = n + 1;
            count++;
        }
        return count;
    }
};
