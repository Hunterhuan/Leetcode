// 放进vector里面，然后遍历一遍，连接起来就可以了。

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        vector<ListNode*> all;
        ListNode *tmp = head;
        while(tmp){
            all.push_back(tmp);
            tmp = tmp->next;
        }
        for(int i=0;i<all.size()-2;++i){
            all[i]->next = all[i+2];
        }
        int length = all.size();
        if(length%2==0){
            all[length-1]->next = NULL;
            all[length-2]->next = all[1];
        }
        else{
            all[length-2]->next = NULL;
            all[length-1]->next = all[1];
        }
        return all[0];
    }
};