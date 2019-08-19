class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        //因为有最小时间的存在,因此一只猪可以用多次（即重复使用,只要不死）,这样可以减少猪的使用数量
        int pigs = 0;
        while(pow(minutesToTest/minutesToDie+1, pigs) < buckets)
            pigs++;
        return pigs;
    }
};