class Solution {
public:
    string shortestPalindrome(string s)
    {
        int n = s.size();
        string rev(s);
        reverse(rev.begin(), rev.end());
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (s.substr(0, n - i) == rev.substr(i))
                return rev.substr(0, i) + s;
        }
        return "";
    }
};





class Solution {
public:
    string shortestPalindrome(string s)
    {
        int n = s.size();
        int i = 0;
        for (int j = n - 1; j >= 0; j--) {
            if (s[i] == s[j])
                i++;
        }
        if (i == n)
            return s;
        string remain_rev = s.substr(i, n);
        reverse(remain_rev.begin(), remain_rev.end());
        return remain_rev + shortestPalindrome(s.substr(0, i)) + s.substr(i);
    }
};


// KMP
string shortestPalindrome(string s)
{
    int n = s.size();
    string rev(s);
    reverse(rev.begin(), rev.end());
    string s_new = s + "#" + rev;
    int n_new = s_new.size();
    vector<int> f(n_new, 0);
    for (int i = 1; i < n_new; i++) {
        int t = f[i - 1];
        while (t > 0 && s_new[i] != s_new[t])
            t = f[t - 1];
        if (s_new[i] == s_new[t])
            ++t;
        f[i] = t;
    }
    return rev.substr(0, n - f[n_new - 1]) + s;
}