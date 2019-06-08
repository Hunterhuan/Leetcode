/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        stack<pair<ListNode*, int>> s;
        ListNode* tmp = head;
        int count = 0;
        while(tmp){
            res.push_back(0);
            while(!s.empty()){
                if(s.top().first->val < tmp->val){
                    res[s.top().second] = tmp->val;
                    s.pop();
                }
                else
                    break;
            }
            s.push(make_pair(tmp, count));
            ++count;
            tmp = tmp->next;
        }
        return res;
    }
};