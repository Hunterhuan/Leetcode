// 想到用map去存个数，然后用排列组合去做。
// 但是不知道如何去处理重复的。怎么确定某一个组合已经利用排列组合排列过了。
class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
		int one[101] = {0};
        map<int, int> m;
        int count = 0;
        // 统计每个元素 出现多少个
		for (int i = 0; i < A.size(); i++) {
			one[A[i]]++;
        }
        for (int i = 0; i < A.size(); i++) {
            // 遍历每一个数
            one[A[i]]--;
            // 剩余两个数的和需要 == left
            int left = target - A[i];
            // 剪枝
            if (left < 0 || left > 200) continue;
            // j表示第二个数，第三个数是要大于等于第二个数的。
            for (int j = left > 100 ? left-100:0; j <= left/2; j++) {
                if (one[j] == 0) continue;
                if (2*j == left) {
                    count += one[j]*(one[j]-1)/2;
                } else {
                    count += one[j]*one[left-j];
                }
                count %=1000000007;
            }
        }
		return count;
	}
};

// 他没使用排列组合去count，而是使用减去本身，再/2
// 妙啊 