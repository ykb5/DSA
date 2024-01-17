#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node* insert(struct node *root,int d)
{
    if(root==NULL)
    {
        struct node *temp;
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=d;
        temp->left=temp->right=NULL;
        root=temp;
        return root;
    }
    if(root->data > d)
        root->left=insert(root->left,d);
    else
        root->right=insert(root->right,d);
    return root;
}

void display(struct node *root)
{
    if(root==NULL)
        return;
    display(root->left);
    printf("%d ",root->data);
    display(root->right);
    return;
}
int main()
{
    struct node *root=NULL;
    root=insert(root,4);
    root=insert(root,7);
    root=insert(root,8);
    root=insert(root,11);
    root=insert(root,2);
    root=insert(root,0);
    root=insert(root,1);
    root=insert(root,12);
    display(root);
    return 0;
}