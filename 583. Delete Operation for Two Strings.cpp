class Solution {
public:
    int minDistance(string word1, string word2) {
        int wordOneSize = word1.size(), wordTwoSize = word2.size();
        //dp[i][j]表示的word1的前i个字符与word2的前j个字符达到相同所需的最小步数
        vector<vector<int>> dp(wordOneSize + 1, vector<int>(wordTwoSize + 1, INT_MAX / 2));
        //word1的前i个字符转换为word2的前0个字符需要i步删除操作
        for (int i = 0; i <= wordOneSize; ++i){
            dp[i][0] = i;
        }
        //word2的前j个字符转换为word1的前0个字符需要j步删除操作
        for (int j = 0; j <= wordTwoSize; ++j){
            dp[0][j] = j;
        }
        //下面开始动态规划
        for (int i = 1; i <= wordOneSize; ++i){//穷举word1的前i个字符
            for (int j = 1; j <= wordTwoSize; ++j){//穷举word2的前j个字符
                //要使word1的前i个字符与word2的前j个字符，可以有三种方法：
                if (word1[i - 1] == word2[j - 1]){
                    //第一种：dp[i - 1][j - 1] 
                    //如果word1[i - 1] == word2[j - 1]相等，则先使word1的前i - 1个字符与word2的前j - 1个字符，然后无需删除操作，直接匹配
                    dp[i][j] = dp[i - 1][j - 1];
                }
                //第二种：dp[i - 1][j] + 1代表将word1的前i - 1个字符转换为word2的前j个字符，然后删除word1中的第i个字符
                //第三种：dp[i][j - 1] + 1代表将word1的前i个字符转换为word2的前j - 1个字符，然后删除word2中的第j个字符
                dp[i][j] = min(dp[i][j], min(dp[i - 1][j], dp[i][j - 1]) + 1);
            }
        }
        return dp[wordOneSize][wordTwoSize];//word1的前wordOneSize个字符与word2的前wordTwoSize个字符达到相同所需的最小步数
    }
};