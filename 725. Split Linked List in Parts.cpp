// 这个第一次没做出来，有点意思，要注意
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> res(k, nullptr);
        int len = 0;
        for (auto curr = root; curr != nullptr; curr = curr->next)
            len++;
        int n = len / k, r = len % k;
        ListNode* node = root;
        ListNode* prev = nullptr;
        for (int i = 0; i < k; i++, r--) {
            res[i] = node;
            for (int j = 0; j < n + (r > 0); j++) {
                prev = node;
                node = node->next;
            }
            if (prev != nullptr)
                prev->next = nullptr;
        }
        return res;
    }
};