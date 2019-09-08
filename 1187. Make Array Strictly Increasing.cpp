class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int len1 = arr1.size();
        sort(arr2.begin(), arr2.end());
        arr2.push_back(-1);
        vector<int> ar;
        for (int i = 0; i < arr2.size() - 1; i ++) {
            if (arr2[i] != arr2[i + 1])
                ar.push_back(arr2[i]);
        }
        arr2 = ar;
        int len2 = arr2.size();
        int f[2002][2002];
        for (int i = 0; i < len1; i ++) {
            for (int j = 0; j <= len2; j ++) {
                f[i][j] = 10000000;
                f[i][j] = 10000000;
            }
        }
        for (int j = 0; j <= len2; j ++) {
            f[0][j] = 1;
        }
        f[0][0] = 0;
        for (int i = 1; i < len1; i ++) {
            if (arr1[i] > arr1[i - 1])
                f[i][0] = min(f[i][0], f[i - 1][0]);
            int l = 0;
            int r = len2 - 1;
            int ind = -1;
            while(l <= r) {
                int mid = (l + r) / 2;
                if (arr2[mid] < arr1[i]) {
                    l = mid + 1;
                    ind = mid;
                }
                else
                    r = mid - 1;
            }
            if (ind != -1) {
                f[i][0] = min(f[i][0], f[i - 1][ind + 1]);
            }
            for (int j = 1; j <= len2; j ++) {
                if (arr2[j - 1] > arr1[i - 1])
                    f[i][j] = min(f[i][j], f[i - 1][0] + 1);
                if (j > 1)
                    f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
            }
        }
        int ans = f[len1 - 1][0];
        for (int j = 1; j <= len2; j ++)
            ans = min(ans, f[len1 - 1][j]);

        return ans == 10000000?-1 : ans;
    }
};

//太难，没看懂