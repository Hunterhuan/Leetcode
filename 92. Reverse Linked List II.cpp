// 是之前reverse linked list 的升级版，需要几个指针定位m ,n 然后再reverse中间的部分

class Solution {
public:
	 ListNode* reverseBetween(ListNode* head, int m, int n) {
		 ListNode *pre=nullptr,*p_front=nullptr,*now=nullptr,*newhead=nullptr;
		 ListNode dummy(-1);
		 newhead=&dummy;
		 dummy.next=head;
		 pre=newhead;
		 for (int i=1;i<m;i++)
		 {
			 pre=pre->next;
		 }
		 if(pre->next)now=pre->next;
		 else return head;
		 if (now->next)p_front=now->next;
		 else return head;
		 for (int i=m;i<n&&p_front;i++)
		 {
			 now->next=p_front->next;
			 p_front->next=pre->next;
			 pre->next=p_front;
			 p_front=now->next;
			 // now=pre->next;
		 }
		 return newhead->next;
	 }
};