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
struct node *in(struct node *root,int data)
{
    struct node temp;
    if(root==NULL){
        return new(data);
    }
    else{
        if(data > root->val){
            root->right=in(root->right,data);
        }
        else{
            root->left=in(root->left,data);
        }
        
    }
    return root;
}
void dis_in(struct node *root)
{
  if (root != NULL) {
    dis_in(root->left);

    printf("%d  ", root->val);

    dis_in(root->right);
    }
}

/*void dis_pos(struct node *root)
{
  if (root != NULL) {
    inorder(root->left);

    printf("%d  ", root->val);

    inorder(root->right);
    }
}

void dis_pre(struct node *root)
{
  if (root != NULL) {
    inorder(root->left);

    printf("%d  ", root->val);

    inorder(root->right);
    }
}
*/

int main()
{
    struct  node *root=NULL;
    int n,data;
    while (1)
    {
        printf("\n1.in\n2.de\n3.dis\n");
        scanf("%d",&n);
        switch(n)
        {
        case 1: printf("\nenter a val:");
                scanf("%d",&data);
                root=in(root,data);
            break;
        case 2: 
            break;
        case 3: dis_in(root);
                //dis_pos(root);
                //dis_pre(root);
                break;
        default:printf("\ninvalid choice\n");
            break;
        }
    }
    return 0;
}