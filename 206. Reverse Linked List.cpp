// reverse link list 很简单


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode * pre = NULL;
        ListNode * cur = head;
        while(cur){
            ListNode * n = cur->next;
            cur->next = pre;
            pre = cur;
            cur = n;
        }
        return pre;
    }
};