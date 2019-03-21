// 函数的抢占时间。
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
	vector<int> res(n, 0);
	stack<int> s;
	int preTime = 0;
	for (string log:logs) {
		// 处理字符串
		int found1 = log.find_first_of(":");
		int found2 = log.find_last_of(":");
		int idx = stoi(log.substr(0,found1));
		string type = log.substr(found1 + 1, found2 - found1 - 1);
		int time = stoi(log.substr(found2+1));
		// 如果不是empty，那么就给top，也就是现在在运行的加上到现在运行的时间
		if (!s.empty()) {
			res[s.top()] += time - preTime;
		}
		// 记录下来push进去的时候的时间
		preTime = time;
		// 如果是start，那么就push进去
		if (type == "start") s.push(idx);
		else {
			// 如果是end,那么就pop出来
			int tmp = s.top(); s.pop();
			++res[tmp];
			preTime++;
		}
	}
	return res;        
    }
};