// 不会
// 别人用map去维护一个前缀分组。很棒。这种方法要记住

class Solution {
    map<int, int>count;
    map<int, int> m;
    bool check() const{
        
        if(m.size() == 1){//只出现一个数字
            return true;
        }
        
        //出现很多数字，但是都次数都是1
        if(count.size() == 1 && count.begin()->first == 1){
            return true;
        }
        
        if(count.size() != 2){
            return false;
        }
        
        auto one = count.begin();
        auto two = one;
        two++;
        
        //只有一个数字出现一次，其他都出现多次，且次数相等
        if(one->second == 1 && one->first ==1){
            return true;
        }
        if(two->second == 1 && two->first ==1){
            return true;
        }
        
        //所有数字都出现多次，但是大多数次数都相等，只有一个特殊多了一次
        if(one->second == 1 && one->first - 1 == two->first){
            return true;
        }
        if(two->second == 1 && two->first - 1 == one->first){
            return true;
        }
        
        return false;
    }
public:
    int maxEqualFreq(vector<int>& nums) {
        int ans = 1;
        for(int i=0;i<nums.size();i++){
            int old = m[nums[i]];
            m[nums[i]]++;
            
            //维护前缀
            if(count.find(old) != count.end()){
                count[old]--;
                if(count[old] == 0){
                    count.erase(old);
                }
            }
            count[m[nums[i]]]++;
            
            if(check()){
                ans = i + 1;
            }
        }
        
        return ans;
    }
};