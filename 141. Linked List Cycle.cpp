// 这道题很简单
//后来找到了复杂度O(n)的方法，使用两个指针slow,fast。两个指针都从表头开始走，slow每次走一步，fast每次走两步，如果fast遇到null，则说明没有环，返回false；如果slow==fast，说明有环，并且此时fast超了slow一圈，返回true。

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode * quick = head;
        ListNode * slow = head;
        while(quick){
            if(quick->next==NULL)
                return false;
            else{
                quick = quick->next->next;
                slow = slow->next;
                if(quick==NULL)
                    return false;
                else{
                    if(quick==slow)
                        return true;
                }
            }
        }
        return false;
    }
};