// 自己使用了二分法，但是效率并不是很高。
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int l = 1 , r = INT_MIN;
        for(int i=0;i<piles.size();++i)
            r = max(r, piles[i]);
        while(l < r){
            int mid = l + (r-l)/2;
            int cur_H = 0;
            for(int i=0; i<piles.size();++i){
                cur_H += (piles[i]/mid);
                if(piles[i]%mid)
                    cur_H++;
            }
            if(cur_H > H)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};


// 别人的方法，主要是用了 ceil函数，比我的取整要效率高一些的。
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int right = *max_element(piles.begin(), piles.end());
        int left = 1;
        while(left < right){
            int mid = left + (right - left) / 2, cnt = 0;
            for(auto m: piles){
                cnt += ceil(double(m) / double(mid));
            }
            if(cnt > H){
                left = mid+1;
            }
            else{
                right = mid;
            }
        }
        return right;
    }
};