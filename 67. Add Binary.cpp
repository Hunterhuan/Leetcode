// 简单，就是实现大数类似的
class Solution {
public:
    string addBinary(string a, string b) {
        //Find the shorter string 
        string longstr = (a.length() >= b.length()) ? a : b;
        string shortstr = (a.length() < b.length()) ? a : b;
        int len = longstr.length() - shortstr.length();
        bool flag = false;
        //Fill it with "0" to make two strings' length equal
        for (int i = 0; i < len; i++) {
            shortstr = "0" + shortstr;
        }
        //Use "flag" to show whether we will carry
        for (int j = longstr.length() - 1; j >= 0; j--) {
            int sum = int(longstr[j]) + int(shortstr[j]) - 96;
            if (flag == true) sum++;
            if (sum == 2) { longstr[j] = '0'; flag = true; }
            else if (sum == 3) { longstr[j] = '1'; flag = true; }
            else { longstr[j] = char(sum + 48); flag = false; }
        }
        //If we carried finally,we have to add a "1" at the beginning
        if (flag == true) longstr = "1" + longstr;
        return longstr;
    }
};