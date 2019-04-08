// 思路一样，自己就不写了。采用双for循环。O(N^2)
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<pair<int,int> >lis(nums.size(),{0,0});
        int maxLis = 0;
        for(int i = 0; i < nums.size(); ++i){
            lis[i].first = 1;
            lis[i].second = 1;
            
            for(int j = i - 1; j >= 0; j--){
                if(nums[j] < nums[i] && lis[i].first < lis[j].first + 1){
                    lis[i].first = lis[j].first + 1;
                    lis[i].second = lis[j].second;
                }else if(nums[j] < nums[i] && lis[i].first == lis[j].first + 1){
                    lis[i].second += lis[j].second;
                }
            }
            
            maxLis= max(maxLis,lis[i].first);
        }
        
        int numberOfLis = 0;
        for(int i = lis.size() - 1; i >=0 ; i--){
            if(lis[i].first == maxLis){
                numberOfLis += lis[i].second;
            }
        }
        
        return numberOfLis;
    }
};