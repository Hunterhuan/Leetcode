// 找list中间的，用一个fast和一个slow就可以了。
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode * fast = head, *slow = head;
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};