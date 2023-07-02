#include <stdio.h>
#include <stdlib.h>

struct BST

{

    int data;

    struct BST *left;

    struct BST *right;
};

typedef struct BST NODE;

NODE *node;

NODE *create(NODE *node, int data)

{

    if (node == NULL)

    {

        NODE *temp;

        temp = (NODE *)malloc(sizeof(NODE));

        temp->data = data;

        temp->left = temp->right = NULL;

        return temp;
    }

    if (data < (node->data))

    {

        node->left = create(node->left, data);
    }

    else if (data > node->data)

    {

        node->right = create(node->right, data);
    }

    return node;
}

void inorder(NODE *node)

{

    if (node != NULL)

    {

        inorder(node->left);

        printf("%d ", node->data);

        inorder(node->right);
    }
}

void preorder(NODE *node)

{

    if (node != NULL)

    {

        printf("%d ", node->data);

        preorder(node->left);

        preorder(node->right);
    }
}

void postorder(NODE *node)

{

    if (node != NULL)

    {

        postorder(node->left);

        postorder(node->right);

        printf("%d ", node->data);
    }
}

NODE *FindMin(NODE *node)

{

    if (node == NULL)

    {

        return NULL;
    }

    if (node->left)

        return FindMin(node->left);

    else

        return node;
}

void main()

{

    int data, i, n;
    char ch;

    NODE *root = NULL;
    scanf("%d", &n);

    for (i = 0; i < n; i++)

    {

        scanf("%d ", &data);

        root = create(root, data);
    }
    scanf("%c", &ch);

    switch (ch)

    {
    case 'a':
printf("\nThe Inorder Traversal is: ");
        inorder(root);

        break;

    case 'c':
        printf("\nThe preorder Traversal is: ");

        preorder(root);

        break;

    case 'b':
printf("\nThe postorder Traversal is: ");
        postorder(root);

        break;
    }
}