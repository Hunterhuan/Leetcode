// 这个是反向的，那么就用stack 先存下来，然后再输出结果
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> s1,s2,s3;
        ListNode * cur = l1;
        while(cur){
            s1.push(cur);
            cur = cur->next;
        }
        cur = l2;
        while(cur){
            s2.push(cur);
            cur = cur->next;
        }
        int m = 0,a = 0,b = 0;
        ListNode * laji;
        while(!s1.empty() || !s2.empty()){
            if(s1.empty())
                a=0;
            else{
                a = s1.top()->val;
                s1.pop();
            }
            if(s2.empty())
                b=0;
            else{
                b = s2.top()->val;
                s2.pop();
            }
            int tmp = a+b;
            if(m==1)
                tmp++;
            s3.push(new ListNode(tmp%10));
            m = tmp/10;
        }
        if(m==1)
            s3.push(new ListNode(1));
        ListNode * res = s3.top();
        laji = s3.top();
        s3.pop();
        while(!s3.empty()){
            laji->next = s3.top();
            s3.pop();
            laji = laji->next;
        }
        return res;
    }
};