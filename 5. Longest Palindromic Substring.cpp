// solution1: LCS 不行，但是自己也会写出来LCS了。
// 反转后找最长的公共子串
// "aacmbcaa"
// 会找到aac""
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<=1)
            return s;
        int n = s.size();
        string rs = s;
        reverse(rs.begin(),rs.end());
        vector<vector<int>> dp(n,vector<int>(n,0));
        int largest = -1, index = -1;
        for(int i=0;i<n;++i){
            if(s[i]==rs[0])
                dp[i][0] = 1;
            if(rs[i]==s[0])
                dp[0][i] = 1;
            if(dp[i][0]>largest){
                largest = dp[i][0];
                index = i;
            }
            if(dp[0][i]>largest){
                largest = dp[0][i];
                index = 0;
            }
        }

        for(int i=1;i<n;++i){
            for(int j=1;j<n;++j){
                if(s[i]==rs[j]){
                    dp[i][j] = dp[i-1][j-1]+1;
                    if(dp[i][j] > largest){
                        largest = dp[i][j];
                        index = i;
                    }
                }
            }
        }
        if(largest <=0)
            return "";
        return s.substr(index-largest+1,largest);
    }
};


// solution2 : brute force 会超时
// 错误方法


// solution3: 扩散
// 设某一个为中心，然后向左右扩散。
// 这是对brute force的改进
// 以为会超时，但没事儿
class Solution {
public:
    string longestPalindrome(string s) 
    {
        string res="";
        int len=s.size();
        if(len<=1)  return s;
        int maxLen=0,curLen=0,sbegin;

        for(int i=0;i<len;++i)
        {
            //奇数
            int left=i-1,right=i+1;
            while(left>=0&&right<len&&s[left]==s[right])
            {
                curLen=right-left;
                if(curLen>maxLen)
                {
                    maxLen=curLen;
                    sbegin=left;
                }
                left--,right++;
            }

            //偶数
            left=i,right=i+1;
            while(left>=0&&right<len&&s[left]==s[right])
            {
                curLen=right-left;
                if(curLen>maxLen)
                {
                    maxLen=curLen;
                    sbegin=left;
                }
                left--,right++;
            }
        }
        res=s.substr(sbegin,maxLen+1);  //substring()为前闭后开
        return res;
    }
};

// solution4: Manacher's algorithm 马车拉算法
// 这是对以每个字符为中心扩张的算法的优化
// 因为aaaaa，就会有很多重复计算
// http://www.cnblogs.com/love-yh/p/7072161.html
class Solution {
public:
    string longestPalindrome(string s) 
    {
        //重新构造新的字符串t，这样新的字符串的字符个数始终为奇数个
        string t="&#";  //加&是为了防止越界，后面自带'\0'
        for(int i=0;i<s.size();++i)
        {
            t+=s[i];
            t+="#";
        }
        //新建P[i]用来存放以t[i]字符为中心的回文子串的半径
        vector<int> P(t.size(),0);
        int mx=0;   //是回文串能延伸到的最右端位置
        int iD=0;   //每个回文串的中间点
        int resLen=0,resCenter=0;
        for(int i=1;i<t.size();++i)
        {   
            /*当i<mx时，能对称取值得下标，当半径小于mx-i时，就是本身，
             *大于则只能取mx-iD，超过的部分只能++的比较。当i>mx时，只能++的比较。*/
            P[i]=mx>i?min(P[2*iD-i],mx-i):1;    

            while(t[i+P[i]]==t[i-P[i]])
                ++P[i];           //以i点为中心的P[i]的最大值

            if(mx<i+P[i])           //重新选择中心点并改变mx
            {
                mx=i+P[i];
                iD=i;
            }
            if(resLen<P[i])         //记录最大的半径和对应的中间点的值
            {
                resLen=P[i];
                resCenter=i;
            }

        }
        return s.substr((resCenter-resLen)/2,resLen-1);
    }
 };

 // solution5: 动态规划
 // dp[i][j] 表示i->j是一个回文串
 class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if(len <= 1) return s;
        int maxlen = 1 ,begin;
        bool dp[len][len]; // dp[i][j] == true -> s[i..j] is palindrome
        memset(dp,0,sizeof(dp));
        for(int i = 0; i<len ;i++){
            dp[i][i] = true; 
        }
        for(int i =0 ; i< len -1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1] = true;
                maxlen = 2;
                begin = i;
            }
        }
        for(int substr_len = 3; substr_len <= len ;substr_len ++){
            for(int i =0; i <= len -substr_len; i++){
                int j = i + substr_len -1 ;
                if(s[i] == s[j] && dp[i+1][j-1] == true){ 
                    dp[i][j] = true ;
                    begin = i;
                    maxlen = substr_len;
                }
            }
        }
        return s.substr(begin,maxlen);
    }
};