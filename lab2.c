// Binary Search Tree. Implement a function to search in it.
// Yogesh Kumar Bhatt_H_20011189
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left, *right;
};
struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d -> ", root->key);
        inorder(root->right);
    }
}
struct node *insert(struct node *node, int key)
{
    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    return node;
}
int search(struct node *root, int key)
{
    if (root == NULL)
        return 0;
    else if (root->key == key)
    {
        return 1;
    }
    else
    {
        if (key > root->key)
            search(root->right, key);
        else
            search(root->left, key);
    }
}
void fparent(struct node *root, int key, int parent)
{
    if (root == NULL)
        return;
    else if (root->key == key)
    {
        if (parent == -1 || root->key == -1)
            printf("NO Parent !\n");
        else
            printf("Parent : %d\n", parent);
    }
    else
    {
        fparent(root->left, key, root->key);
        fparent(root->right, key, root->key);
    }
}

int main()
{
    struct node *root = NULL;
    int val;
    int ch;
    int key;
    int parent = -1;
    do
    {
        printf("\nMenu:\n1. Add node in tree\t2. Display tree\t3. Search\n");
        printf("Enter the Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 0:
            break;
        case 1:
            printf("Enter the key: ");
            scanf("%d", &val);
            root = insert(root, val);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            printf("\nEnter the key to search in tree : ");
            scanf("%d", &key);
            if (search(root, key))
            {
                printf("Key found !\n");
                fparent(root, key, parent);
            }
            else
                printf("Key not found!\n");
            break;
        default:
            printf("Invalid Choice!\n");
        }
    } while (ch);
    free(root);
    return 0;
}