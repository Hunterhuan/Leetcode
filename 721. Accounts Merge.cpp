class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> res;
        vector<int> root(accounts.size());
        for(int i = 0; i < accounts.size(); i++) root[i] = i;
        
        unordered_map<string, int> r_map;
        
        for(int i = 0; i < accounts.size(); i++) {
            vector<string> a = accounts[i];
            for(int j = 1; j < a.size(); j++) {
                if(r_map.find(a[j]) != r_map.end()) {
                    int p = r_map[a[j]];
                    int p1 = findParent(root, i);
                    int p2 = findParent(root, p);
                    if(p1 != p2) root[p1] = p2;
                } else {
                    r_map[a[j]] = i;
                }
            }
        }
        
        unordered_map<int, vector<string>> res_map;
        for(auto& e : r_map) {
            string email = e.first;
            int parent = e.second;
            int r = findParent(root, parent);
            res_map[r].push_back(email);
        }
        
         for(auto& e : res_map) {
             int idx = e.first;
             vector<string> emails = e.second;
             sort(emails.begin(), emails.end());
             emails.insert(emails.begin(), accounts[idx][0]);
             res.push_back(emails);
        }
        return res;
    }
    
private:
    int findParent(vector<int> & root, int p) {
        while(p != root[p]) {
            root[p] = root[root[p]];
            p = root[p];
        }
        return p;
    }
};