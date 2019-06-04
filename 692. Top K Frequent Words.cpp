class Solution {
public:
    struct cmp{
        bool operator()(pair<string, int> &a, pair<string, int>& b){
            if(a.second<b.second)
                return true;
            if(a.second == b.second)
                return a.first>b.first;
            return false;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> m;
        for(auto w:words)
            m[w]++;
        priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;
        for(auto it = m.begin(); it!=m.end();++it){
            pq.push(make_pair(it->first, it->second));
        }
        vector<string> res;
        for(int i=0;i<k;++i){
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};