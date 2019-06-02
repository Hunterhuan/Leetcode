class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        //arr1 = {1};
        //arr2 = {1,1};
        int cnt1 = arr1.size(), cnt2 = arr2.size();
        vector<int> nb;
        int bit = 0;
        int a = 0;
        int b = 0;
        while(true){
            if(cnt1==0)
                a = 0;
            else{
                a = arr1[--cnt1];
            }
            if(cnt2==0)
                b = 0;
            else{
                b = arr2[--cnt2];
            }
            int res = a + b + bit;
            if(res == 2){
                res = 0;
                bit = -1;
            }
            else if(res == -1){
                res = 1;
                bit = 1;
            }
            else if(res == 3){
                res = 1;
                bit = -1;
            }
            else{
                bit = 0;
            }
            nb.push_back(res);
            if(cnt1 == 0 && cnt2==0 && bit ==0)
                break;
        }
        while(true){
            if(nb.size()>1 && nb.back()==0)
                nb.pop_back();
            else
                break;
        }
        reverse(nb.begin(), nb.end());
        return nb;
    }
};