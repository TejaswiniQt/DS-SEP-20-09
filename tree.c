// Implementation of tree 
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}tree;

tree* Insert(tree **);
void Preorder(tree **);
void Postorder(tree *);
void Inorder(tree *);


int main()
{
    tree *root = NULL;
    int option;
    while(1)
    {
    printf("Enter the option : \n");
    printf("1.Insert()\n2.Preorder\n3.Postorder\n4.Inorder\n5.exit\n");
    scanf("%d",&option);
    switch(option)
    {
        case 1: root = Insert(&root);
        break;
        case 2: Preorder(&root);
        printf("\n");
        break;
        case 3: Postorder(root);
        printf("\n");
        break;
        case 4: Inorder(root);
        printf("\n");
        break;
        case 5:exit(0);
    }
    }
    return 0;
}

tree* Insert(tree **root)
{
    int data;
    tree *newnode = (tree *)malloc(sizeof(tree));
    printf("Enter data(-1 for no node):");
    scanf("%d",&data);
    if(data == -1)
    {
        return NULL;
    }
    //tree *newnode = (tree *)malloc(sizeof(tree));
    newnode->data = data;
    printf("Enter the left node of %d: ",data);
    newnode->left = Insert(&newnode);
    printf("Enter the right node of %d: ",data);
    newnode->right = Insert(&newnode);
    return newnode;
}

void Postorder(tree *root)
{
    if(root == NULL)
    {
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    printf("%d ",root->data);
}

void Preorder(tree **root)
{
    if(*root == NULL)
    {
        return;
    }
    printf("%d ",(*root)->data);
    Preorder(&(*root)->left);
    Preorder(&(*root)->right);
}

void Inorder(tree *root)
{
    if(root == NULL)
    {
        return;
    }
    Inorder(root->left);
    printf("%d ",root->data);
    Inorder(root->right);
}