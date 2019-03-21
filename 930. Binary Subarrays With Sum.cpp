// 我的方法。但是被[0,0,0,0,0] 0 的数据给卡住了。
// solution，记录下所有1的位置。然后。看两端1前后多少个0能组成排列组合。

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        vector<int> index;
        index.push_back(-1);
        for(int i=0;i<A.size();++i){
            if(A[i])
                index.push_back(i);
        }
        index.push_back(A.size());
        int res = 0;
        for(int i=1; i<index.size()-S;++i){
            res += ((index[i]-index[i-1]) * (index[i+S] - index[i+S-1]));
        }
        return res;
    }
};

// 别人存的不是index，别人存的是0的个数
// 然后特判一下S=0 的时候如何解
class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        vector<int> zeros;
        int cnt = 0;
        for (int x: A) {
            if (x == 1) {
                zeros.push_back(cnt);
                cnt = 0;
            }
            else
                cnt++;
        }
        zeros.push_back(cnt);

        int ans = 0;
        if (S == 0) {
            for (int x: zeros)
                ans += x * (x + 1) / 2;
            return ans;
        }
        for (int i = 0; i + S < zeros.size(); i++)
            ans += (zeros[i] + 1) * (zeros[i + S] + 1);
        return ans;
    }
};


// 看来只能使用滑动窗口法了
// 但搜到的并没有使用滑动窗口的。很难受了

// 使用的是前缀和的方法
// 真简洁
// 但提交来看，前缀和的解法speed稍慢。
class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        unordered_map<int, int> prefixSum;
        int sum = 0;
        int ans = 0;
        prefixSum[0]++;
        for (int x: A) {
            sum += x;
            ans += prefixSum[sum - S];
            prefixSum[sum]++;
        }
        return ans;
    }
};