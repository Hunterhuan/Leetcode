// 这个需要多投。
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0,cnt2=0,ans1=0,ans2=1;
        for(auto n:nums){
            if(n==ans1){
                cnt1++;
            }
            else if(n==ans2){
                cnt2++;
            }
            else if(cnt1==0){
                ans1=n;
                cnt1++;
            }
            else if(cnt2==0){
                ans2=n;
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=cnt2=0;
        for(auto n:nums){
            if(n==ans1){
                cnt1++;
            }
            else if(n==ans2){
                cnt2++;
            }
        }
        vector<int>ans;
        if(cnt1>nums.size()/3){
            ans.push_back(ans1);
        }
        if(cnt2>nums.size()/3){
            ans.push_back(ans2);
        }
        return ans;
    }
};