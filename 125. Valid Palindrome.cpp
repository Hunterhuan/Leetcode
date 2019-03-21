// 一个easy的题，自己就搞了好久。贼气。
// isalnum 字母，数字
// isupper 大写
// isgraph 可打印
// isdigit 数字
// isspace 空格
// ispunct 看看是不是标点特殊符号
class Solution {
public:
    bool isPalindrome(string s) {
	int start=0, end=s.length()-1;
	while(start<end) {
		if (!isalnum(s[start])) start++;
		else if (!isalnum(s[end])) end--;
		else {
			if (tolower(s[start++])!=tolower(s[end--])) 
                return false;
		}
	}
	return true;
    }
};