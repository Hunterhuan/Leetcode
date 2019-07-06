class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        if(citations.size()==0 || citations.back()==0)
            return 0;
        int n=citations.size();
        int i;
        for(i=1; i<=n; ++i){
            if(citations[n-i]<i){
                break;
            }
        }
        return i-1;
    }
};