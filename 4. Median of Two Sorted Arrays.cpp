// 用的很傻逼的算法，就是一个一个count，很好奇别人用binary search会怎么去搞
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size(),l2 = nums2.size();
        int cnt1 = 0, cnt2 = 0;
        vector<int> list;
        int l = (l1+l2)/2+1;
        int cnt = 0;
        while((cnt1<l1 || cnt2<l2) && cnt<l){
            if(cnt1==l1){
                list.push_back(nums2[cnt2]);
                ++cnt2;
            }
            else if(cnt2==l2){
                list.push_back(nums1[cnt1]);
                ++cnt1;
            }
            else{
                if(nums1[cnt1]<nums2[cnt2]){
                    list.push_back(nums1[cnt1]);
                    ++cnt1;
                }
                else
                {
                    list.push_back(nums2[cnt2]);
                    ++cnt2;
                }
            }
            ++cnt;
        }
        if((l1+l2)%2==1)
            return float(list[cnt-1]);
        else
            return float(list[cnt-1]+list[cnt-2])/2;
    }
};


// 别人的想法。应该是先比较中间的数，然后不断的搜搜。还是挺厉害的。自己能想到思路，但自己仍然实现不了。牵涉了很多边界的知识。
class Solution {
public:
//方法二：二分法：O(lg(m+n)),满足题目要求
//get the kth number of two sorted array
    double findkth(vector<int>::iterator a,int m,
                   vector<int>::iterator b,int n,
                   int k)
    {   
        // 确保a是最短的那个array
        if(m >  n)
            return findkth(b,n,a,m,k);
        // a中已经什么都没有了，所以就是b中的第k个数
        if(m == 0)
            return b[k-1];
        // 如果k=1，那么就是a、b中的最小值
        if(k == 1)
            return min(*a,*b);
        // 在a中占pa个，b中占pb个
        int pa = min(k/2,m),pb = k - pa;
        // 如果a小于，那么就把pa个先排除，再找第k-pa 大的数字
        if(*(a + pa - 1) < *(b + pb -1))
            return findkth(a+pa,m-pa,b,n,k-pa);
        else if(*(a + pa -1) > *(b + pb -1))
            return findkth(a,m,b+pb,n-pb,k-pb);
        // 如果相等，则说明找好找到分界情况，就可以return了。
        else
            return *(a+pa-1);
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>::iterator a = nums1.begin();
        vector<int>::iterator b = nums2.begin();
        int total = nums1.size() + nums2.size();

        // judge the total num of two arrays is odd or even
        if(total & 0x1)
            return findkth(a,nums1.size(),b,nums2.size(),total/2+1);
        else
            return (findkth(a,nums1.size(),b,nums2.size(),total/2) + findkth(a,nums1.size(),b,nums2.size(),total/2 + 1))/2;
    }
};