// 想到了用滑动窗口，但做错了。solution1 竟然还看不懂。为什么end-start就是答案

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) 
    {
        int start=0,end=0,sum=0;
        while(end<s.length())
        {
            sum+=abs(s[end]-t[end++]);
            if(sum>maxCost)
                sum-=abs(s[start]-t[start++]);
        }
        return end-start;
    }
};


// 这个是与我的思路完全一样的。
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> diff(s.length());
        for (int i = 0; i < s.length(); i++) diff[i] = abs(s[i] - t[i]);
        int maxSubstring = 0, left = 0, right = 0, curCost = maxCost;
        for (right = 0; right < s.length(); right++) {
            curCost -= diff[right];
            if (curCost< 0) {
                curCost += diff[left++];
            }
            maxSubstring = max(right + 1 - left, maxSubstring);
        }
        return maxSubstring;
    }
};