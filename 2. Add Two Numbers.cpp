// 这道题其实就是考察一下链表的操作

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * cur_1 = l1, *cur_2 = l2;
        ListNode * res = new ListNode(-1);
        int m = 0;
        ListNode * cur = res;
        while(cur_1 || cur_2){
            int a,b;
            if(cur_1==NULL)
                a = 0;
            else{
                a = cur_1->val;
                cur_1 = cur_1->next;
            }
                
            if(cur_2==NULL)
                b = 0;
            else{
                b = cur_2->val;
                cur_2 = cur_2->next;
            }
            int tmp = a + b ;
            if(m==1)
                tmp++;
            cur->next = new ListNode(tmp%10);
            m = tmp/10;
            cur = cur->next;
        }
        if(m==1)
            cur->next = new ListNode(1);
        return res->next;
    }
};