// 对字母的个数进行排序。
// 对于sort的题目，就要想好对什么排序。我之前对字母排序是不对的。
// 然后他的排序实现很厉害。可以采用。
class Solution {
public:
    string reorganizeString(string S) {
        int N = S.size();
        vector<int> counts(26,0);
        for(auto tmp : S)
            counts[tmp-'a'] += 100;
        for(int i=0;i<26;++i)
            counts[i] += i;
        sort(counts.begin(), counts.end());
        string res = S;
        int t = 1;
        for(auto code : counts){
            int ct = code/100;
            char ch = ('a'+(code%100));
            if(ct > (N + 1)/2)
                return "";
            for(int i=0;i<ct;++i){
                if(t>=N)
                    t = 0;
                res[t] = ch;
                t += 2;
            }
        }
        return res;
    }
};