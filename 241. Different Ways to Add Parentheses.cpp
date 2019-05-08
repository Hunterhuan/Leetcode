// dynamic programming dp思路，但也是把各种分割开的思想。
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> nums;
        vector<char> ops;
        int len = input.size();
        int idx = 0;
        // 处理，把式子处理成数字和符号的vector
        while (idx < len)
        {
            if (input[idx] == '+' || input[idx] == '-' || input[idx] == '*')
                ops.push_back(input[idx++]);
            else if (isdigit(input[idx]))
            {
                int end = idx + 1;
                while (end < len && isdigit(input[end]))
                    end++;
                nums.push_back(stoi(input.substr(idx, end - idx)));
                idx = end;
            }
            else
                idx++;
        }
        int numsize = nums.size();
        vector<vector<vector<int>>> dp(numsize);
        // dp的前二维都是 numsize长，最后一维放有多少值
        for_each(dp.begin(), dp.end(), [numsize](vector<vector<int>> &vec){
            vec.resize(numsize);
        });
        // 对每个i遍历
        for (int i = 0; i < numsize; ++i)
        {
            dp[i][i].push_back(nums[i]);
            // 对 [j,i], j不断减少
            for (int j = i - 1; j >= 0; --j)
            {
                // 对[j,i]范围内遍历
                for (int k = j; k < i; ++k)
                {
                    for (int n1 : dp[j][k])
                        for (int n2 : dp[k + 1][i])
                            switch (ops[k])
                            {
                                case '+':
                                    dp[j][i].push_back(n1 + n2);
                                    break;
                                case '-':
                                    dp[j][i].push_back(n1 - n2);
                                    break;
                                case '*':
                                    dp[j][i].push_back(n1 * n2);
                                    break;
                            }
                }
            }
        }
        return dp[0][numsize - 1];
    }
};