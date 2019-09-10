// 统计奇偶就可以了，可以用到位运算去统计

class Solution {
public:
    int numOfOnes(unsigned int n) {
        n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
        n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
        n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
        n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
        n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
        return n;
    }
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<bool> res;
        vector<unsigned int> record;
        record.push_back(0);
        for (int i = 0; i < s.size(); i++) {
            record.push_back(record[i] ^ (1 << (s[i] - 'a')));
        }
        for (int i = 0; i < queries.size(); i++) {
            int oddN = numOfOnes(record[queries[i][0]] ^ record[queries[i][1] + 1]);
            if (queries[i][2] >= (oddN / 2)) {
                res.push_back(true);
            } else {
                res.push_back(false);
            }
        }
        return res;
    }
};