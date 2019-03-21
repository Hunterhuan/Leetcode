


// 跟two sum 的方法一样
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> comp;
        vector<int> result;
        for(int i = 0; i < numbers.size(); ++i){
            unordered_map<int,int>::const_iterator got = comp.find(numbers[i]);
            if(got != comp.end()){
                result.push_back(got->second+1);
                result.push_back(i+1);
                return result;
            }
            comp.insert({target-numbers[i],i});
        }
        return result;
    }
};

// 方法two O(n)
// 用两个指针从两段检测

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size()-1;
        while(left < right){
            int sum = numbers[left] + numbers[right];
            if(sum == target)
                return {left+1,right+1};
            else if(sum < target){
                left++;
            }
            else{
                right--;
            }
        }
        return {0,0};
    }
};

//相关
// 1-Two Sum
// 653. Two Sum IV - Input is a BST