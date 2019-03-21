// 先存下来成两个list，然后再合并成一个

class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> temp;
        while(head) {
            temp.push_back(head);
            head = head->next;
        }
        int i = 0, j = temp.size()-1;
        while(i <= j) {
            temp[i]->next = temp[j];
            temp[j]->next = i+1 <= j-1 ? temp[i+1] : nullptr;
            ++i; --j;
        }
    }
};