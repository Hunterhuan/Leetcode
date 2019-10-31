class Solution {
public:
    int ans = 0;
    void bt(vector<bitset<26>>& words, int index, bitset<26> mask1){
        if(index>=words.size()) return;
        bt(words, index+1, mask1);
        bitset<26> mask2 = words[index];
        if((mask1 & mask2).none()){
            ans = max<int>(ans, mask1.count() + mask2.count());
            bt(words, index+1, mask1 | mask2);
        }        
    }
    int maxLength(vector<string>& arr) {
        vector<bitset<26>> words;
        for(string &s: arr){
            bitset<26> bs;
            for(char c:s) bs.set(c - 'a');
            if(bs.count()==s.size()) words.push_back(bs);
        }
        bt(words, 0, bitset<26>());
        return ans;
    }
};