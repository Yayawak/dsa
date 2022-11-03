//The task is to print the Level order traversal of a tree is breadth first traversal for the tree.
//

// Main Idea
// 1. recurse to traverse all nodes of a level
// 2. find height of tree && run dfs --> print node
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct  node *left, *right;
};

void            print_current_level(struct node* root, int level);
int             height (struct node* node);
struct node*    newNode(int data);

void    print_level_order(struct node* root)
{
    int h = height(root);
    printf("H : %d\n", h);
    int i;
    for (i = 1; i <= h; i++)
    {
        print_current_level(root, i);
        printf("--------------------\n");
    }
}

// The first call : level = 1
void    print_current_level(struct node* root, int level)
{
    printf("Level : %d\n", level);
    if (root == NULL)
        return ;
    if (level == 1)
        printf("value is : %d\n", root->data);
    else if (level > 1)
    {
        print_current_level(root->left, level - 1);
        print_current_level(root->right, level - 1);
    }
}

int     height(struct node* node)
{
    if (node == NULL)
        return (0);
    // if not NULL
    else
    {
        // compute the height of each subtree
        int l_height = height(node->left);
        int r_height = height(node->right);

        if (l_height > r_height)
            return (++l_height);
        else
            return (++r_height);

    }
}

struct node*    new_node(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}


int             main(void)
{
    struct node*    root = new_node(1);
    root->left = new_node(2);
    root->right = new_node(3);
    printf("Height of root->right is \t %d\n", height(root->right));

    root->right->right = new_node(99);
    root->right->right->right = new_node(999);
    root->right->right->right->right = new_node(9999);
    int h1 = height(root->right->right->right->right);
    printf("Height of root->right->right->right->right is \t %d\n", h1);

    root->left->left = new_node(4);
    root->left->right = new_node(5);


    root->left->right->left = new_node(8);
    root->left->right->left->left = new_node(81);
    root->left->right->left->right = new_node(82);

    printf("Level Order traversal of binary tree is \n");
    print_level_order(root);

    return (0);
}
