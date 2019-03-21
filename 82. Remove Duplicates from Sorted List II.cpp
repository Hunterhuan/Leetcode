//也挺简单的，注意新建一个点作为head，
//因为旧的head也可能被删掉

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* res = new ListNode(-1);
        res->next = head;
        ListNode * cur = head;
        ListNode * pre = res;
        while(cur){
            while(cur->next){
                if(cur->next->val == cur->val){
                    cur = cur->next;
                }
                else{
                    break;
                }
            }
            if(cur!=pre->next){
                pre->next = cur->next;
                cur = cur->next;
                continue;
            }
            cur = cur->next;
            pre = pre->next;
        }
        return res->next;
        
    }
};