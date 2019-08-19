class Solution {
public:
	int maxRotateFunction(vector<int>& A) {
		if(A.empty()) return 0;
		long long cur=0;
		long long res=0;
		long long tol=0;
		for(int i=0;i<A.size();i++){
			tol+=A[i];
			cur+=i*A[i];
		}
		res=cur;
		reverse(A.begin(),A.end());
		for(int i=0;i<A.size();i++){
			cur=cur+tol-A.size()*A[i];            
			res=max(res,cur);
		}
		return res;

	}
};