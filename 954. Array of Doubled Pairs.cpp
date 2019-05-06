class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        auto compare = [](const int& lhs, const int& rhs) { return abs(lhs) < abs(rhs); };
        sort(A.begin(), A.end(), compare);
        unordered_map<int,int> dict;
        for (auto v : A)  dict[v]++;
        for (auto v : A) {
            if (dict[v] == 0)        continue;
            if (dict[2*v] < dict[v]) return false;
            dict[2*v] -= dict[v];
            dict[v]    = 0;
        }
        return true;
    }
};