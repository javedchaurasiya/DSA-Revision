class MedianFinder
{
public:
    priority_queue<int> a;
    priority_queue<int, vector<int>, greater<int>> b;
    MedianFinder()
    {
    }

    void addNum(int t)
    {
        int x = a.size(), y = b.size();
        if (x == y)
        {

            if (x == 0)
                a.push(t);
            else
            {
                if (t < b.top())
                    a.push(t);
                else
                {
                    int m = b.top();
                    b.pop();
                    a.push(m);
                    b.push(t);
                }
            }
        }
        else
        {
            if (t > a.top())
                b.push(t);
            else
            {
                int m = a.top();
                a.pop();
                b.push(m);
                a.push(t);
            }
        }
    }

    double findMedian()
    {
        int x = a.size(), y = b.size();
        if (x > y)
            return (double)a.top();
        return ((double)a.top() + (double)b.top()) / (double)2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */