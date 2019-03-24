// 用list 来count
class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> v(26,0);
        for(auto c:s)
            v[int(c-'a')]++;
        for(auto c:t)
            v[int(c-'a')]++;
        for(int i=0;i<26;++i)
            if(v[i]%2)
                return char(i+'a');
        return 'a';
    }
};



// 用 xor
class Solution {
public:
    char findTheDifference(string s, string t) {
        int res = 0;
        for(auto c:s)
            res ^= c;
        for(auto c:t)
            res ^= c;
        return char(res);
    }
};