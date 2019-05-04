class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unsigned short min[50000],max[50000],Fre[50000]={0},max_Fre=0;
        int l=nums.size(),r,Distance= -1;
        vector<int> showup;
        for(int i=0;i<l;i++){
            r=nums[i];
            Fre[r]++;
            if (Fre[r]==1) min[r]=i;
            else max[r]=i;
            if (Fre[r]>max_Fre) {
                max_Fre++;
                Distance=max[r]-min[r];
            }
            else if(Fre[r]==max_Fre){
                if(max[r]-min[r]<Distance){
                    Distance=max[r]-min[r];
                }
            }
        }
        if(max_Fre<2) return max_Fre;
        return Distance+1;
    }
};