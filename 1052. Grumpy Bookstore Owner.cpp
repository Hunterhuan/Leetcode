class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        //customers = {4,10,10};
        //grumpy = {1,1,0};
        //X = 2;
        int res = 0;
        for(int i=0;i<customers.size();++i){
            if(grumpy[i]==0){
                res += customers[i];
            }
        }
        for(int i=0;i<X;++i){
            res += grumpy[i]*customers[i];
        }
        int resmax = res;
        for(int i=1;i<customers.size()-X+1;++i){
            res -= grumpy[i-1]*customers[i-1];
            res += grumpy[i-1+X]*customers[i-1+X];
            resmax = max(res, resmax);
        }
        return resmax;
    }
};
