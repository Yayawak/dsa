#include "bits.h"
using namespace std;

class Queue
{
    public:
        int front, rear, size;
        unsigned cap; // capacity
        int *arr;
    bool    isEmpty()
    {
        return (front == -1) ? true : false;
    }

    bool    isFull()
    {
        return (front == 0 && rear == MAX_SIZE - 1) ? true : false;
    }

};

Queue*  createQueue(unsigned cap)
{
    Queue* queue = new Queue;
    queue->cap = cap;
    queue->front = queue->size = 0;

    queue->rear = cap - 1;
    queue->arr = new int[(queue->cap * sizeof(int))];
    return (queue);
}


int front(Queue* queue)
{
    if (isempty(queue))
        return INT_MIN;
    return queue->arr[queue->front];
}

int rear(Queue* queue)
{
    if (isempty(queue))
        return INT_MIN;
    return queue->arr[queue->rear];
}
