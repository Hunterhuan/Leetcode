// 因为只能+， 所以用一个token表示现在需要向上加的个数。
// 然后不断对ans累加就行了。
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        vector<int> count(50000,0);
        for(auto x:A)
            count[x]++;
        int ans = 0, taken = 0;
        for(int i=0;i<50000;++i){
            if(count[i]>=2){
                taken += count[i]-1;
                ans -= i*(count[i]-1);
            }
            else if(taken >0 && count[i]==0){
                taken--;
                ans +=i;
            }
        }
        return ans;
    }
};