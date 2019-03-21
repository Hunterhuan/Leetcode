// 别人很牛逼。
// 直接拓展到K，太厉害了。
// 自己只能想到用dic去存index，他直接存个数
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        unordered_map<int,int> fruit;
        int total = 0;
        int K = 2;
        for (int i = 0, l = 0; i < tree.size(); ++i) {
            ++fruit[tree[i]];
            if (fruit.size() > K) {
                while (--fruit[tree[l++]]);
                fruit.erase(tree[l-1]);
            }
            total = max(total, i-l+1);
        }
        return total;
    }
};