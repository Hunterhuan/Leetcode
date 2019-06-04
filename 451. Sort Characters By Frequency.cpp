class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> hmap;
        priority_queue<pair<int, char>> pq;
        string str = "";

        for (auto& c : s)
            hmap[c]++;

        for (auto& [first, last] : hmap) {
            pq.push(make_pair(last, first));
        }

        while (!pq.empty()) {
            str.insert(str.end(), pq.top().first, pq.top().second);
            pq.pop();
        }

        return move(str);
    } 
};