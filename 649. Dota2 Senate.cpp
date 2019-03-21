// 每次一个参议院都禁止他后面的另外一个的参议院
// solution很巧妙，用到了queue来达到循环的目的
class Solution {
public:
    string predictPartyVictory(string senate) {
	queue<int> q1, q2;
	int n = senate.size();
	for (int i = 0; i < senate.size();i++) {
		if (senate[i] == 'R') q1.push(i);
		else q2.push(i);
	}
	while (q1.size() && q2.size()) {
		int r_index = q1.front(); q1.pop();
		int d_index = q2.front(); q2.pop();
		if (r_index < d_index) q1.push(r_index + n);
		else q2.push(d_index + n);
	}
	return q1.size() > q2.size() ? "Radiant" : "Dire";        
    }
};