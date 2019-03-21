
class Solution {
public:
    int findindex(vector<int>& arr, int x){
        int r = arr.size() - 1, l = 0;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(arr[mid] == x)
                return mid;
            else if(arr[mid] < x)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        int index = findindex(arr, x);
        int l = index - 1, r = index;
        while(k>0){
            if(l==-1){
                r++;
            }
            else if(r==arr.size()){
                l--;
            }
            else{
                if(abs(arr[l]-x) <= abs(arr[r]-x)){
                    --l;
                }
                else{
                    ++r;
                }
            }
            --k;
        }
        for(int i= l+1; i<r;++i)
            res.push_back(arr[i]);
        return res;
    }
};