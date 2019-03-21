
//merge, 只不过这个是链表，挺妙的
// 这个是最常规的思路，每次找到最小的，然后再merge进去
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(0);
        ListNode* min_node = head;
        vector<ListNode*> ptrs(lists.size());
        for(int i=0; i < lists.size(); ++i){
            ptrs[i] = lists[i];
        }
        
        bool do_while = true;
        while(do_while){
            int min_val = INT_MAX, min_id = -1;
            for(int i = 0; i < ptrs.size(); ++i){
                if(ptrs[i] != NULL && ptrs[i]->val < min_val){
                    min_val = ptrs[i]->val;
                    min_id = i;
                }
            }
            if(min_id != -1){
                min_node ->next = ptrs[min_id];
                min_node = min_node -> next;
                ptrs[min_id] = ptrs[min_id] -> next;
            }
            else 
                do_while = false;
            
        }
        return head->next;
            
    }
};

//另外一种是分治法，每次合并两个，最终合并在一起
// 每次对折数组，合并对应的，直到所有的都在lists[0]
// 这个效率高得多
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0) return NULL;
        int n = lists.size();
        while (n > 1) {
            int k = (n + 1) / 2;
            for (int i = 0; i < n / 2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[i + k]);
            }
            n = k;
        }
        return lists[0];
    }
    
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(-1);
        ListNode *cur = head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1) cur->next = l1;
        if (l2) cur->next = l2;
        return head->next;
    }
};