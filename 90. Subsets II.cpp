/*再次考虑S={1,2,2}，先排序。

首先加入空集{}

对于元素1，需要加入{}，成为新的集合{1}

对于元素2，需要加入{}和{1}，成为新的集合{2}和{1,2}。考虑重复，再产生新集合{2,2}和{1,2,2}。*/


// 不断的叠加，这种思路很不错。
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        res.push_back({});
        if(nums.size()==0)
            return res;
        int cur_len = 1;
        for(int i=0;i<nums.size();++i){
            int res_len = res.size();
            for(int j=res_len-1;j>res_len-1-cur_len;--j){
                vector<int> v = res[j];
                //cout<<"lalala"<<endl;
                v.push_back(nums[i]);
                res.push_back(v);
            }
            if(i<nums.size()-1 && nums[i]==nums[i+1]){
                continue;
            }else{
                cur_len = res.size();
            }
        }
        return res;
    }
};