class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> visited;
        sort(words.begin(), words.end());
        string longest;
        for (auto& w: words){
            if (w.length()<2 || visited.find(w.substr(0, w.length()-1)) != visited.end()){
                if (longest.length()<w.length())
                    longest = w;                
                visited.insert(w);
            }
        }
        return longest;
    }
};