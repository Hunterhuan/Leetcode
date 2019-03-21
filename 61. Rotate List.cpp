
// 旋转k个，可以先连成环，然后再断开。return 出来就是结果
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
            return head;
        ListNode* cur = head;
        int sum = 1;
        while(cur->next){
            cur = cur->next;
            ++sum;
        }
        k = k%sum;
        if(k==0)
            return head;
        cur->next = head;
        int tmp = sum - k;
        for(int i=0;i<tmp;++i){
            cur = cur->next;
        }
        ListNode* res = cur->next;
        cur->next = NULL;
        return res;
    }
};