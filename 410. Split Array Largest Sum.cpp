// 很难，这道题开始一点思路都没有。
// 下面的solution是别人写的。关于二分法。对结果进行二分。不断逼近逼到最终结果。尤其要注意边界问题

//1.我们可以这样对待数组，我们将数组分成每段小于或等于target_num的小组，那么每个小组的和肯定小于或等于target_sum，如果此时我们得到的分段数目小于或等于m，那么确定最大子段和小于或等于target_sum,否则，最大子段和的最小值一定大于target_sum；

//2. 在设计的时候一定要注意: 如果写成high=mid和low=mid的模式，则有可能陷入死循环的可能，因为我们最后low，mid和high的指针的转态如下图所示：

class Solution {
public:
	bool is_reach(vector<int>& arr, int m, long target_sum){
		long cur_sum = arr[0];
		int sections = 1;
		for (int i = 1; i < arr.size(); ++i){
			cur_sum += arr[i];
			if (cur_sum > target_sum){
				++sections;
				cur_sum = arr[i];
			}
		}
		if (sections > m)
            return false;//如果段计数器值大于m，假设题目要求m=3，而我们求得的段的大小为4,
		return true;
	}
 
	int splitArray(vector<int>& arr, int m) {
		int n = arr.size();
		long low = arr[0], high = arr[0];
		for (int i = 1; i < n; ++i){
			low = max(low, long(arr[i]));//数组的单个最大元素
			high += arr[i];//数组的所有元素
		}
		int res = 0;
		while (low < high){
			long mid = (low + high) / 2;
			if (is_reach(arr, m, mid)){
				high = mid; // 注意边界
			}
			else
				low = mid + 1; // 注意边界
		}
		return low;
	}
};



// 别人还有用dp去做的
// 时间复杂度会比二分法高。还行吧
class Solution {
public:
int splitArray(vector<int>nums, int m){
	int L = nums.size();
	long *S = new long[L + 1];
	S[0] = 0;
	for (int i = 0; i<L; i++)
		S[i + 1] = S[i] + nums[i];
 
	int *dp = new int[L];
	for (int i = 0; i<L; i++)
		dp[i] = S[L] - S[i];
 
	for (int s = 1; s<m; s++){
		for (int i = 0; i<L - s; i++){
			dp[i] = INT_MAX;
			for (int j = i + 1; j <= L - s; j++){
				int t = max(dp[j], int(S[j] - S[i]));
				if (t <= dp[i])dp[i] = t;
				else break;
			}
		}
	}
	int re = dp[0];
	delete [] S;
	delete [] dp;
	return re;
}
};