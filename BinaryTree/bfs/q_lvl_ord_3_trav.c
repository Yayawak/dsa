// Main steps
// 1. craete empty q && push root in q
// 2. run while loop until q is not empty
//

#include <stdio.h>
#include <stdlib.h>
# define MAX_Q_SIZE 500

struct node
{
    int             data;
    struct node*    left;
    struct node*    right;
};

struct node**   create_queue(int  *, int *);
void            enqueue(struct node**, int*, struct node*);
struct node*    dequeue(struct node**, int *);

void            print_level_order(struct node* root)
{
    int rear, front;
    struct node** queue = create_queue(&front, &rear);
    struct node* tmp_node = root;

    while (tmp_node)
    {
        printf("%d\n", tmp_node->data);

        if (tmp_node->left)
            enqueue(queue, &rear, tmp_node->left);
        if (tmp_node->right)
            enqueue(queue, &rear, tmp_node->right);

        tmp_node = dequeue(queue, &front);
    }
}


struct node**   create_queue(int *front, int *rear)
{
    struct node**   queue = (struct node**)malloc(
            sizeof(struct node*) * MAX_Q_SIZE);
    // reset front & rear to zero
    *front = *rear = 0;
    return (queue);
}

void            enqueue(struct node** queue, int *rear,
        struct node* new_node)
{
    queue[*rear] = new_node;
    // *rear = *rear + 1
    (*rear)++; // shift pointer and assign to it
}

struct  node*   dequeue(struct node** queue, int *front)
{
    (*front)++;
    return (queue[*front - 1]);
}

struct  node*   new_node(int data)
{
    struct node*    node
        = (struct node*)malloc(sizeof(struct node));
    node->data= data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

int             main(void)
{
    printf("Size of node is : $%lu$\n", sizeof(struct node));
    printf("Size of node* is : $%lu$\n", sizeof(struct node*));
    struct node*    root = new_node(1);

    root->left = new_node(2);
    root->right = new_node(3);

    root->left->left = new_node(4);
    root->left->right = new_node(5);

    root->right->right = new_node(0);

    root->right->right->left = new_node(9);
    root->right->right->right = new_node(10);

    root->right->right->left->left = new_node(100);
    root->right->right->left->right = new_node(101);

    root->right->right->right->left = new_node(50);
    root->right->right->right->right = new_node(51);

    printf("Level order traversal of binary tree is \n");

    print_level_order(root);
    return (0);
}
