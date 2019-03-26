// random的题，挺有意思的，可以看看别人是怎么做的。

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int tmp;
        while(true){
            tmp = rand7();
            if(tmp!=4){
                break;
            }
        }
        int base = 0;
        if(tmp>3)
            base = 5;
        while(true){
            tmp = rand7();
            if(tmp!=6 && tmp!=7){
                break;
            }
        }
        return base+tmp;
    }
};