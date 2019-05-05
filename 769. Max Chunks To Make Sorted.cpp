class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        //arr = {1,0,2,3,4};
        if(arr.size()==0)
            return 0;
        if(arr.size()==1)
            return 1;
        int max_index = -1;
        int count = 0;
        for(int i=0;i<arr.size();++i){
            max_index = max(max_index, arr[i]);
            if(i==max_index)
                ++count;
        }
        return count;
    }
};