// debug de了这么久，才发现是i和j写错了。
#include <bitset>
class Solution {
public:
    int maxProduct(vector<string>& words) {
        //words = {"a","ab","abc","d","cd","bcd","abcd"};
        vector<int> to_int(words.size(),0);
        for(int i=0;i<words.size();++i){
            for(int j=0;j<words[i].size();++j){
                to_int[i] |= (1<<(words[i][j]-'a'));
            }
        }
        //for(auto i : to_int)
        //    cout<<bitset<sizeof(int)*8>(i)<<endl;
        int res = 0;
        //cout<<int(to_int[2]&to_int[5])<<endl;
        for(int i=0;i<to_int.size();++i){
            for(int j=i+1;j<to_int.size();++j){
                if(int(to_int[i]&to_int[j])==0){
                    res = max(int(words[i].size()*words[j].size()), res);
                }
                    
            }
        }
        return res;
    }
};