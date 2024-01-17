#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *left, *right;
};

struct node *new(int n)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->val=n;
    temp->left=NULL;
    temp->right=NULL;

    return temp;
}

int main()
{
    struct node *root = new(1);
    root->left = new(2);
    root->right = new(3);
    
    printf("%d ", root->val);
    printf("%d ", root->left->val);
    printf("%d ", root->right->val);

    return 0;
}