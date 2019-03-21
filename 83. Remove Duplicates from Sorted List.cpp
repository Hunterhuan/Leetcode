// 确实很简单，删掉重复的就可以了
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)
            return head;
        ListNode* cur = head;
        while(cur->next){
            if(cur->val == cur->next->val){
                cur->next = cur->next->next;
            }
            else
                cur = cur->next;
        }
        return head;
    }
};