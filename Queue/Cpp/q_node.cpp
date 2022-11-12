#include <stddef.h>

struct QNode
{
    int     data;
    QNode*  next;
    QNode (int d)
    {
        data = d;
        next = NULL;
    }

    struct Queue
    {
        QNode *front, *rear;
        Queue()
        {
            front = rear = NULL;
        }
    };
};
