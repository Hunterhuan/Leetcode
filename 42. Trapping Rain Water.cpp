// solution1 : Two pointers
// 在当前两指针确定的范围内，先比较两头找出较小值，
//如果较小值是left指向的值，则从左向右扫描，
//如果较小值是right指向的值，则从右向左扫描，
//若遇到的值比当较小值小，则将差值存入结果，
//如遇到的值大，则重新确定新的窗口范围，
//以此类推直至left和right指针重合

class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0, l = 0, r = height.size() - 1;
        while (l < r) {
            int mn = min(height[l], height[r]);
            if (mn == height[l]) {
                ++l;
                while (l < r && height[l] < mn) {
                    res += mn - height[l++];
                }
            } else {
                --r;
                while (l < r && height[r] < mn) {
                    res += mn - height[r--];
                }
            }
        }
        return res;
    }
};

// 简洁版的Two pointers
class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1, level = 0, water = 0;
        while (l < r) {
            int lower = height[height[l] < height[r] ? l++ : r--];
            level = max(level, lower);
            water += level - lower;
        }
        return water;
    }
};


// solution2 : dynamic progress
// 遍历两遍数组，一次记录最大的，一次记录最小的。那么就能知道该点能存多少水了。
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0, mx = 0, n = height.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            dp[i] = mx;
            mx = max(mx, height[i]);
        }
        mx = 0;
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = min(dp[i], mx);
            mx = max(mx, height[i]);
            if (dp[i] > height[i]) res += dp[i] - height[i];
        }
        return res;
    }
};


// solution3 : stack 来解。根本不知道还能用stack来解
// stack的solution更容易理解
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int i = 0, res = 0, n = height.size();
        while (i < n) {
        	// 如果遍历到的高度比stack顶部的低 或 stack是空的
        	// 那么就push进去
            if (st.empty() || height[i] <= height[st.top()]) {
                st.push(i++);
            } else {
            	// 否则的话，如果比stack的top高。
            	// 就pop掉top的
                int t = st.top(); st.pop();
                if (st.empty()) continue;
                res += (min(height[i], height[st.top()]) - height[t]) * (i - st.top() - 1);
            }
        }
        return res;
    }
};


//https://www.cnblogs.com/grandyang/p/4402392.html