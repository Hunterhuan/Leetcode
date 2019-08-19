class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> re;
        for(int i=left; i<=right;i++){
            int temp=i;
            while(temp !=0 && temp %10 != 0){
                if(i % (temp % 10) != 0) break;
                temp = temp / 10;
            }
            if(temp == 0) re.push_back(i);
        }
        return re;
    }
};