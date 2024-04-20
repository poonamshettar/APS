#include <stdio.h>
#include <stdlib.h>
struct Tree
{
    int value;
    struct Tree *left, *right;
};
struct Tree *create_node(int value)
{
    struct Tree *newnode = (struct Tree *)malloc(sizeof(struct Tree));
    newnode->value = value;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct Tree *insert_node(struct Tree *root, int value)
{
    if (root == NULL)
    {
        return create_node(value);
    }
    if (value < root->value)
    {
        root->left = insert_node(root->left, value);
    }
    else if (value > root->value)
    {
        root->right = insert_node(root->right, value);
    }
    return root;
}

void inorder(struct Tree *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->value);
        inorder(root->right);
    }
}

void preorder(struct Tree *root)
{
    if (root != NULL)
    {
        printf("%d ", root->value);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Tree *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->value);
    }
}

int main()
{
    struct Tree *root = NULL;
    for (int i = 0; i < 5; i++)
    {
        int x = rand() % 100;
        root = insert_node(root, x);
    }
    printf("Preorder Traversal : ");
    preorder(root);
    printf("\nInorder Traversal : ");
    inorder(root);
    printf("\nPostorder Traversal : ");
    postorder(root);
    return 0;
}
