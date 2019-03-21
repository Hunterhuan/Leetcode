// 日了狗了。退出循环的条件都没搞清楚。提交了多次都不符合提议。
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
    	// 记录哪些元素被查找过，已查找过的不再查找
    	vector<int> visited(nums.size(), 0);
		for(int i=0;i<nums.size();i++) {
			if(visited[i]) continue;
			vector<int> vs(nums.size(), 0);
			// 对每个元素判断是否有环
			if(has_circular(nums, vs, i)) {
				return true;
			} else {
				// 将本次查找过的元素加入无需找找的列表
				for(int i=0;i<nums.size();i++)
					if(vs[i]) visited[i] = vs[i];
			}
		}        
		return false;
    }
    // 取下一个元素的下标
    int get_index(vector<int>& nums, int i) {
    	int res = i+nums[i];
    	while(res<0) res+= nums.size();
    	return res%nums.size();
    }
    
    bool has_circular(vector<int>& nums, vector<int>& visited, int i) {
    	int next = get_index(nums, i);
    	// 先判定下一个元素是否是自己
    	if(next==i) {
    		visited[i] = true;
    		return false;
    	}
    	// 下一个元素出现在当次遍历，则成功找到环
    	if(visited[next]) return true;
    	// 符号相反不可能有环
    	if(nums[next]>0 != nums[i]>0) return false;
    	visited[next] = true;
    	// 继续查找
    	return has_circular(nums, visited, next);
    }
};