// Solution1 : Comparison Sorting
// 利用了sort，能AC掉。但是要求说不让用sort，让用linear线性的time
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<=1)
            return 0;
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int i=0;i<nums.size()-1;++i){
            res = max(nums[i+1] - nums[i], res);
        }
        return res;
    }
};


//Solution2: Radix sort

class Solution {
public:
    int maximumGap(vector<int>& nums)
    {
        if (nums.empty() || nums.size() < 2)
            return 0;

        int maxVal = *max_element(nums.begin(), nums.end());

        int exp = 1;                                 // 1, 10, 100, 1000 ...
        int radix = 10;                              // base 10 system

        vector<int> aux(nums.size());

        /* LSD Radix Sort */
        while (maxVal / exp > 0) {                   // Go through all digits from LSD to MSD
            vector<int> count(radix, 0);

            for (int i = 0; i < nums.size(); i++)    // Counting sort
                count[(nums[i] / exp) % 10]++;

            for (int i = 1; i < count.size(); i++)   // you could also use partial_sum()
                count[i] += count[i - 1];

            for (int i = nums.size() - 1; i >= 0; i--)
                aux[--count[(nums[i] / exp) % 10]] = nums[i];

            for (int i = 0; i < nums.size(); i++)
                nums[i] = aux[i];

            exp *= 10;
        }

        int maxGap = 0;

        for (int i = 0; i < nums.size() - 1; i++)
            maxGap = max(nums[i + 1] - nums[i], maxGap);

        return maxGap;
    }
};