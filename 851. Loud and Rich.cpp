// 利用后续遍历，左右中的顺序，每个中间取的是左右的最小值

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> f;
    vector<vector<int>> e;
    
    pair<int, int> calc(int x, vector<int>& quiet){
        if (f[x].first != -1) return f[x];
        int q = quiet[x]; 
        int who = x; 
        for (auto& y: e[x]){
            auto tmp = calc(y, quiet);
            if (tmp.first < q) {
                q = tmp.first;
                who = tmp.second;
            }
        }
        f[x] = make_pair(q, who);
        return f[x];
    }
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        e.resize(n);
        for (auto& r: richer){
            e[r[1]].push_back(r[0]);
        }
        
        f.resize(n);
        for (int i = 0; i < n; i++) f[i] = make_pair(-1, -1);
        
        vector<int> ans;
        for (int i = 0; i < n; i++){
            ans.push_back(calc(i, quiet).second);
        }
        return ans;
    }
};