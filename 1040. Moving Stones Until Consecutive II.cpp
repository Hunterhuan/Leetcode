class Solution {
public:
	vector<int> numMovesStonesII(vector<int>& stones) {
        int mx=INT_MAX, ct=0, size=stones.size(), pre=0;
        sort(stones.begin(), stones.end());
        for(int i=0;i<stones.size();i++) {
            while(stones[i]-stones[pre]>size-1) pre++;
            ct=max(ct, i-pre+1);
        }
        mx=max(stones[size-2]-stones[0]-size+2, stones.back()-stones[1]-size+2);
        if(stones.back()-stones[0]>size&&(stones[size-2]-stones[0]==size-2||stones[size-1]-stones[1]==size-2)) ct--;
        return {size-ct, mx};
    }
};