// 自己的solution
// 效率还挺高
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //gas = {5,8,2,8};
        //cost = {6,5,6,6};
        int n = gas.size();
        vector<int> need(n,0);
        for(int i=0;i<n;++i)
            need[i] = gas[i]-cost[i];
        int i=0;
        int j;
        while(i<n){
            if(need[i]>=0){
                int sum = 0;
                for(j=0;j<n && sum>=0;++j){
                    sum += need[(i+j)%n];
                }
                if(j==n && sum>=0)
                    return i;
                else{
                    if(j+i<n)
                        i += j;
                    else
                        return -1;
                }
            }
            else
                i++;
        }
        return -1;
    }
};