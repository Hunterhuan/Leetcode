// 服气，关于位运算的一个都做不出。难受

// solution1: Moore voting algorithm
// 每找出一对不同的，就删去count--
// 最终剩下的就是最终的结果
class Solution {
public:
    int majorityElement(vector<int> &num) {

        int elem = 0;
        int count = 0;
        
        for(int i = 0; i < num.size(); i++)  {
            
            if(count == 0)  {
                elem = num[i];
                count = 1;
            }
            else{
                if(elem == num[i])
                    count++;
                else
                    count--;
            }
            
        }
        return elem;
    }
};

// solution2: sort
// sort后取中间的值就可以了
class Solution {
public:
    int majorityElement(vector<int> &num) {
        sort(num.begin(), num.end());
        return num[num.size()/2];
    }
};

// solution3: hashtable
// 最常规的方法。就是count，找到适合的
class Solution {
public:
    int majorityElement(vector<int> &num) {
        int n = num.size();
        map<int,int> m;
        for(int i=0;i<n;++i)
        {
            m[num[i]]++;
            if(m[num[i]]>=n/2+1)
                return num[i];
        }
        return 0;
    }
};