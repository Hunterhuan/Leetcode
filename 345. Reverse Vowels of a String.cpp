// 麻烦一点儿，但不难
class Solution {
public:
    string reverseVowels(string s) {
        int i=0,j=s.length()-1;
        while(i<j)
        {
            while((isVowel(s[i])==false)&&(i<j))
            {
                i++;
            }
            while((isVowel(s[j])==false)&&(i<j))
            {
                j--;
            }
            swap(s[i],s[j]);
            i++;
            j--;
        }
        return s;
    }
    bool isVowel(char c)
    {
        if((c=='a')||(c=='e')||(c=='i')||(c=='o')||(c=='u')||(c=='A')||(c=='E')||(c=='I')||(c=='O')||(c=='U'))
            return true;
        return false;
    }
};