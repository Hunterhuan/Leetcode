class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(auto num:nums)
            m[num]++;
        vector<pair<int,int>> p;
        for(auto it = m.begin(); it!=m.end(); ++it){
            p.push_back(make_pair(it->first, it->second));
        }
        sort(p.begin(), p.end(), [](auto a, auto b){return a.second > b.second;});
        vector<int> res;
        for(int i=0;i<k;++i){
            res.push_back(p[i].first);
        }
        return res;
    }
};