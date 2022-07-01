class MyStack
{
public:
    int sz;
    queue<int> q;
    MyStack()
    {
        sz = 0;
    }

    void push(int x)
    {
        sz++;
        q.push(x);
    }

    int pop()
    {
        int ct = 0;
        while (ct < sz - 1)
        {
            ct++;
            int x = q.front();
            q.pop();
            q.push(x);
        }
        sz--;
        int x = q.front();
        q.pop();
        return x;
    }

    int top()
    {
        int ct = 0;
        int x;
        while (ct < sz)
        {
            ct++;
            x = q.front();
            q.pop();
            q.push(x);
        }
        return x;
    }

    bool empty()
    {
        return sz == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */