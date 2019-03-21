// 联系map，简简单
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> m;
        for(int i=0;i<nums1.size();++i)
            m[nums1[i]]++;
        vector<int> res;
        for(int i=0;i<nums2.size();++i){
            if(m[nums2[i]]){
                res.push_back(nums2[i]);
                m[nums2[i]] = 0;
            }
        }
        return res;
    }
};


// 利用内置函数
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s(nums1.begin(),nums1.end());
        set<int> s1(nums2.begin(),nums2.end());
        vector<int> ret;
        set_intersection(s.begin(),s.end(),s1.begin(),s1.end(),inserter(ret,ret.begin()));
        return ret;
    }
};