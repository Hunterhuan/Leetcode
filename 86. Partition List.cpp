// create 了两个linklist，一个是大的，一个是小的，最后拼接在一起。

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode * large = new ListNode(-1);
        ListNode * small = new ListNode(-1);
        ListNode * large_rear = large;
        ListNode * small_rear = small;
        ListNode * cur = head;
        while(cur){
            if(cur->val < x){
                small_rear->next = cur;
                small_rear = small_rear->next;
            }
            else{
                large_rear->next = cur;
                large_rear = large_rear->next;
            }
            cur = cur->next;
        }
        small_rear->next = large->next;
        large_rear->next = NULL;
        return small->next;
    }
};