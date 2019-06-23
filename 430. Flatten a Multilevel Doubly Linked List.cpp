/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* ret = head;
        f(head);
        return ret;
    }
    Node* f(Node* head)
    {
        Node* curr = head;
        Node* save ;
        while(head)
        {
        save = head->next;
        if(head->child)
        {
        Node* temp = head->next;
        head->next = head->child;
        head->child->prev = head;
        head->child = NULL;
        temp = f(head->next);
        if(temp&&save)
        {
        temp->next = save;
        save->prev = temp;
        }
        }
            if(!save)
                break;
            head = save;
        }
       return head;
    }
};