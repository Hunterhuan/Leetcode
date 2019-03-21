
// 简单，先统计所有的个数，然后在定位，删去就行了
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = head;
        int length = 0;
        while(cur!=NULL){
            cur = cur->next;
            ++length;
        }
        if(length==n){
            return head->next;
        }
        length = length -n;
        cur = head;
        for(int i=0;i<length-1;++i){
            cur = cur->next;
        }
        ListNode * delet = cur->next;
        cur->next = cur->next->next;
        return head;
    }
};