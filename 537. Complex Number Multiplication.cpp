class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int j;
        for(int i=0;i<a.length();i++){
            if(a[i]=='+'){
                j=i;
                break;
            }}
            int x1=stoi(a.substr(0,j));
            int x2=stoi(a.substr(j+1,a.length()-2-j));
             for(int i=0;i<a.length();i++){
            if(b[i]=='+'){
                j=i;
                break;
            }
        }
        int y1=stoi(b.substr(0,j));
        int y2=stoi(b.substr(j+1,b.length()-2-j));
        int a1=x1*y1-x2*y2;
        int b1=x2*y1+y2*x1;
        return (to_string(a1)+"+"+to_string(b1)+"i");
    }
};