#include <bits/stdc++.h>
class Queue
{
public:
    vector<int> v;
    int f, b, sz;
    Queue()
    {
        // Implement the Constructor
        f = b = 0;
        sz = 1;
        v.resize(10000, 0);
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty()
    {
        // Implement the isEmpty() function
        return f == b;
    }

    void enqueue(int data)
    {
        // Implement the enqueue() function
        v[++b] = data;
        sz++;
    }

    int dequeue()
    {
        // Implement the dequeue() function
        if (isEmpty())
            return -1;
        return v[++f];
    }

    int front()
    {
        // Implement the front() function
        if (isEmpty())
            return -1;
        return v[f + 1];
    }
};