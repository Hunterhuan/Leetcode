class KthLargest {
private:
    vector<int> arr;
    int th;
public:
    KthLargest(int k, vector<int>& nums) {
        th = k;
        arr = nums;
        sort(arr.begin(), arr.end(), [](int a, int b){return a>b;});
    }
    
    int add(int val) {
        int i=0;
        for(i=0;i<arr.size();++i){
            if(val>= arr[i]){
                break;
            }
        }
        arr.insert(arr.begin()+i, val);
        return arr[th-1];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */