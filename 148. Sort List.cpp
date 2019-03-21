//merge sort 链表

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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode * slow = head;
        ListNode * fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;
        return mergesort(sortList(head), sortList(fast));
    }
    ListNode * mergesort(ListNode* slow, ListNode* fast){
        ListNode * newhead = new ListNode(0);
        ListNode * tail = newhead;
        while(slow || fast){
            if(slow && fast){
                if(slow->val < fast->val){
                    tail->next = slow;
                    slow = slow->next;
                }
                else{
                    tail->next = fast;
                    fast = fast->next;
                }
            }
            else{
                if(slow){
                    tail->next = slow;
                    slow = slow->next;
                }
                else{
                    tail->next = fast;
                    fast = fast->next;
                }
            }
            tail = tail->next;
            tail->next = NULL;
        }
        return newhead->next;
    }
};
