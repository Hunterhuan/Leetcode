class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        bool dic[33];
        dic[2] = dic[3] = dic[5] = dic[7] = dic[11] = dic[13] = dic[17] = dic[19] = true;
        int ans = 0;
        for(int i = L; i<=R;++i){
            bitset<32> b(i);
            int count = b.count();
            if(dic[count])
                ++ans;
        }
        return ans;
    }
};


// 用bitset<32> 这个类是真的快。快太多了