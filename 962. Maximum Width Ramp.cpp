// 没想到。应该再做一次的。
class Solution {
public:
 int maxWidthRamp(vector<int>& A) {
        if (A.empty()) return 0;
        
        int n = A.size();
        vector<int> leftMin(n), rightMax(n);
        
        leftMin[0] = A[0];
        for (int i = 1; i < n; i++)
            leftMin[i] = min(A[i], leftMin[i-1]);
        
        rightMax[n-1] = A[n-1];
        for (int i = n-2; i >= 0; i--)
            rightMax[i] = max(A[i], rightMax[i+1]);
        
        int i = 0, j = 1, ans = 0;
        while (i < n && j < n) {
            if (leftMin[i] <= rightMax[j]) {
                ans = max(ans, j-i);
                j++;  // there can be more elements on right satisfying the constraint, thus move to right
            }
            else i++;  // all elements on left of A[i] are bigger, thus move to right 
        }
        return ans;
    }
};