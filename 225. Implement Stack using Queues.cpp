class MyStack
{
  private:
    queue<int> q;

  public:
    /** Initialize your data structure here. */
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        q.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        return poptopHelper(1);
    }

    int poptopHelper(int step)
    {
        int ret;
        if (q.size() == step)
        {
            ret = q.front();
            q.pop();
            return ret;
        }
        int data = q.front();
        q.pop();
        q.push(data);
        ret = poptopHelper(step + 1);
        return ret;
    }

    /** Get the top element. */
    int top()
    {
        int ret = poptopHelper(1);
        q.push(ret);
        return ret;
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return q.empty();
    }
};
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */