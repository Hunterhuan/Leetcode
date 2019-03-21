// 内部实现用vector，以后再oj里面也要善于用vector才能快速做题
class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {

    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index < 0 || index >= myList.size())
            return -1;
        return myList[index];
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        myList.insert(myList.begin(), val);
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        myList.push_back(val);
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
       if(index > myList.size())
           return ;
       else if(index == myList.size())
           myList.push_back(val);
       else
           myList.insert(myList.begin()+index, val);
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index >= myList.size())
            return ;
        myList.erase(myList.begin()+index);
    }
private:
    vector<int> myList;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */