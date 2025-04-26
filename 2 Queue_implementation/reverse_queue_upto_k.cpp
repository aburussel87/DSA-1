#include <iostream>
#include "QueueArray.h"

Queue reverse(Queue q, int k)
{
    Queue s;
    int x = k;
    while (k--)
    {
        s.enqueue(q.dequeue());
    }
    // reversing a full queue(considering s as a full queue)
    Queue final;
    while (!s.isEmpty())
    {
        int l = s.length() - 1;
        while (l--)
        {
            s.enqueue(s.dequeue());
        }
        final.enqueue(s.dequeue());
    }
    // adding the rest part of the main queue
    while (!q.isEmpty())
    {
        final.enqueue(q.dequeue());
    }
    return final;
}

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);
    q.enqueue(80);
    q.enqueue(90);
    q.enqueue(100);

    int k = 5;
    q = reverse(q, k);

    // Printing Queue
    while (!q.isEmpty())
    {
        cout << q.dequeue() << " ";
    }
    return 0;
}