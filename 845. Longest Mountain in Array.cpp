// 为什么别人的代码都写的这么简洁 清晰。
// 自己的思路是每次找到一个山。却总是搞错边界问题。
class Solution {
public:
    int longestMountain(vector<int>& A) {
        int up = 0, down = 0;
        int res = 0;
        for (int i = 1; i < A.size(); i++) {
        	// 这个边界很难
            if (down > 0 && A[i] > A[i - 1] || A[i] == A[i - 1])
                up = down = 0;
            up += A[i] > A[i - 1];
            down += A[i] < A[i - 1];
            if(up && down)
                res=max(res,up+down+1);
        }
	return res;
    }
};


// solution2
class Solution {
public:
    int longestMountain(vector<int>& A) {
		vector<int> up(A.size(), 0);
		vector<int> down(A.size(), 0);
		int res = 0;
		for (int i = A.size() - 2; i >= 0; i--) if (A[i] > A[i + 1]) down[i] = down[i + 1] + 1;
		for (int i = 1; i < A.size(); i++) {
			if (A[i] > A[i - 1]) up[i] = up[i - 1] + 1;
			if(up[i] && down[i]) res = max(res, up[i] + down[i] + 1);
		}
		return res;
    }
};