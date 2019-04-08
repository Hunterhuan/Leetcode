// 这个题本来是可以直接通过递归不断向下的，但是发现只要物品数量大于需要的数量就算满足条件了。
// 难点就在这儿
// 但是可不可以进行dfs，然后只要满足条件就停。（这样好像有的path就不会停止了)
class Solution {
public:
	// 使用map来优化计算，但还是存在问题，不直接命中的就很难受，但大量应该还是不直接命中吧
    unordered_map<string, int> map;
    
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        string key;
        for (int i = 0; i < needs.size(); ++i) {
            key += to_string(needs[i]) + "#";
        }
        
        auto it = map.find(key);
        if (it != map.end()) return it->second;
        
        int m = 0;
        for (int i = 0; i < needs.size(); ++i) {
            m += price[i]*needs[i];
        }
        
        for (int i = 0; i < special.size(); ++i) {
            int s = special[i][needs.size()];
            if (m > s) {
                bool found = true;
                for (int j = 0; j < needs.size(); ++j) {
                    needs[j] = needs[j] - special[i][j];
                    if (needs[j] < 0) found = false;
                }

                if (found) {
                    int n = shoppingOffers(price, special, needs) + s;
                    m = min(m, n);
                }

                for (int j = 0; j < needs.size(); ++j) {
                    needs[j] = needs[j] + special[i][j];
                }
            }
        }
        
        map[key] = m;
        return m;
    }
};