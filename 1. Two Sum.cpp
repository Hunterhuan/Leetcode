

// 暴力法。直接遍历
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0 ; i<nums.size();++i)
        {
            for(int j = i+1 ; j<nums.size();++j)
            {
                if(nums[i]+nums[j] == target)
                    return {i,j};
            }
        }
        return {0,0};
        
    }
};


// for循环，建立一个词典，如果没找到，就把需要的放里面
//（保证词典里面的都是如果能hit到，就说明已经完成配对）
// 循环一遍就可以了
class Solution {
public:
vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> comp;
        vector<int> result;
        for(int i = 0; i < nums.size(); ++i){
            unordered_map<int,int>::const_iterator got = comp.find(nums[i]);
            if(got != comp.end()){
                result.push_back(got->second);
                result.push_back(i);
                return result;
            }
            comp.insert({target-nums[i],i});
        }
        return result;
    }
};


// 用hash table也可以，但没有尝试




// 相关
// 167-two sum ||
// 170-Two Sum III - Data structure design
// 653- Two Sum IV - Input is a BST 
// 15-3sum
// 18-4sum