class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> min_cost(int(cost.size()+1),0);
        if(cost.size()==0)
            return 0;
        if(cost.size()==1)
            return cost[0];
        for(int i=2;i<min_cost.size();++i){
            min_cost[i] = min(min_cost[i-1]+cost[i-1], min_cost[i-2]+cost[i-2]);
        }
        return min_cost.back();
    }
};