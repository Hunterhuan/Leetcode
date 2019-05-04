//brute force ，但效率好像也很高
class Solution {
public:
    int maximumSwap(int num) {
    string ori = to_string(num);
    string changed = ori;
    string ans = ori;
    for(int i=0;i<ori.size();i++){
        for(int j=i+1;j<ori.size();j++){
            swap(changed[i], changed[j]);
            ans = max(ans,changed);
            swap(changed[i], changed[j]);
        }
    }
    return stoi(ans); 
    }
};