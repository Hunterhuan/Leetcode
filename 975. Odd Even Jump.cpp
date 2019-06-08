// 从后向前遍历，看看哪个能到N-1， 然后依次，有dp的思想在里面

class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        const int N = A.size();
        vector<bool> higher(N), lower(N);
        // higher[i] means if we jump higher, can we get N - 1?
        higher[N - 1] = lower[N - 1] = true;
        int res = 1;
        // map[i] means the pos of number i
        map<int, int> m;
        m[A[N - 1]] = N - 1;
        for (int i = N - 2; i >= 0; --i) {
            auto hi = m.lower_bound(A[i]);
            auto lo = m.upper_bound(A[i]);
            if (hi != m.end()) higher[i] = lower[hi->second];
            if (lo != m.begin()) lower[i] = higher[(--lo)->second];
            if (higher[i])
                ++res;
            m[A[i]] = i;
        }
        return res;
    }
};