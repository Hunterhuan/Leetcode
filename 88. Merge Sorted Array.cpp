// 自己撒比，倒着从大向小排不就行了。开始一直在纠结空间的问题。
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m + n;
        while (m > 0 && n > 0) {
            if (nums1[m - 1] > nums2[n - 1]) {
                nums1[i - 1] = nums1[m - 1];
                --m;
            } else {
                nums1[i - 1] = nums2[n - 1];
                --n;
            }
            --i;
        }
 
        while (n > 0) {
            nums1[i - 1] = nums2[n - 1];
            --n;
            --i;
        }
    }
};



// 方法一样。
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index=m+n-1;
        int pos1=m-1;
        int pos2=n-1;
        while(pos2>=0 || pos1>=0)
        {
            if(pos2<0)
            {
                nums1[index]=nums1[pos1];
                --pos1;
            }
            else if(pos1<0)
            {
                nums1[index]=nums2[pos2];
                --pos2;
            }
            else
            {
                if(nums1[pos1]>=nums2[pos2])
                {
                    nums1[index]=nums1[pos1];
                    --pos1;
                }
                else
                {
                    nums1[index]=nums2[pos2];
                    --pos2;
                }
            }
            --index;
        }
    }
};