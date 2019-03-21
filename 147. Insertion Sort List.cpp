// 链表的操作现在还是已经挺熟练的了。
// 链表的插入排序

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
    ListNode* search(ListNode * newhead, int target){
        ListNode * tmp = newhead;
        while(tmp->next){
            if(tmp->next->val >= target)
                return tmp;
            tmp = tmp->next;
        }
        return tmp;
    }
    ListNode* insertionSortList(ListNode* head) {
        ListNode * newhead = new ListNode(0);
        while(head){
            ListNode * tmp = search(newhead, head->val);
            ListNode * node = head;
            head = head->next;
            node->next = tmp->next;
            tmp->next = node;
        }
        return newhead->next;
    }
};