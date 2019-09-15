class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b = 0,a = 0,l = 0,o = 0,n = 0;
        for(int i=0;i<text.size();++i){
            switch(text[i]){
                case 'b':
                    b++;
                    break;
                case 'a':
                    a++;
                    break;
                case 'l':
                    l++;
                    break;
                case 'o':
                    o++;
                    break;
                case 'n':
                    n++;
                    break;
            }
        }
        int res = b;
        res = min(res, a);
        res = min(res, l/2);
        res = min(res, o/2);
        res = min(res, n);
        return res;
    }
};