#include "bst.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

Node *createNewNode(int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (NULL == new_node)
    {
        fprintf(stderr, "malloc failure.\n");
        exit(1);
    }
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

Node *insert(Node *node, int value)
{
    // check if this is the very first entry into the tree.
    if (NULL == node)
    {
        Node *root = createNewNode(value);
        return root;
    }

    // check if we should go down the left sub-tree
    if (value < node->data)
    {
        // no left child? place new value here
        if (NULL == node->left)
        {
            Node *new_node = createNewNode(value);
            node->left = new_node;
        }
        else
        {
            // try inserting into the left sub-tree
            insert(node->left, value);
        }
    }
    else // value >= node->data
    {
        // no right child? place new value here
        if (NULL == node->right)
        {
            Node *new_node = createNewNode(value);
            node->right = new_node;
        }
        else
        {
            // try inserting into the right sub-tree
            insert(node->right, value);
        }
    }
}

bool contains(Node *node, int value)
{
    // check if the current node has the value
    if (node->data == value)
        return true;

    // smaller value? check the left sub-tree for the value
    if (value < node->data)
    {
        // left sub-tree doesnt exists? tree doesn't contain value
        if (NULL == node->left)
            return false;

        contains(node->left, value);
    }
    else // (value >= node->data)->larger value? check the right sub-tree for the value
    {
        // right sub-tree doesnt exists? tree doesn't contain value
        if (NULL == node->right)
            return false;

        contains(node->right, value);
    }
}

void printInOrder(Node *node)
{
    // check if node has left child
    if (node->left)
    {
        // print-in-order left subtree first
        printInOrder(node->left);
    }

    // print current node's (root of tree/sub-tree) value now
    printf("%d, ", node->data);

    // check if node has right child
    if (node->right)
    {
        // print-in-order right subtree last.
        printInOrder(node->right);
    }
}

void printPreOrder(Node *node)
{
    // print current node's (root of tree/sub-tree) value now
    printf("%d, ", node->data);

    // check if node has left child
    if (node->left)
    {
        // print-in-order left subtree first
        printInOrder(node->left);
    }

    // check if node has right child
    if (node->right)
    {
        // print-in-order right subtree last.
        printInOrder(node->right);
    }
}

void printPostOrder(Node *node)
{
    // check if node has left child
    if (node->left)
    {
        // print-in-order left subtree first
        printInOrder(node->left);
    }

    // check if node has right child
    if (node->right)
    {
        // print-in-order right subtree last.
        printInOrder(node->right);
    }

    // print current node's (root of tree/sub-tree) value now
    printf("%d, ", node->data);
}

int getHeight(Node *node)
{
    int leftTreeHeight = 0;
    int rightTreeHeight = 0;

    // no left/right child-> hit a leaf node
    if ((NULL == node->left) && (NULL == node->right))
        return 0;

    if (node->left)
    {
        // compute the maximum height of the left sub-tree
        leftTreeHeight += (1 + getHeight(node->left));
    }
    if (node->right)
    {
        // compute the maximum height of the right sub-tree
        rightTreeHeight += (1 + getHeight(node->right));
    }
    if (leftTreeHeight > rightTreeHeight)
        return leftTreeHeight;
    else
        return rightTreeHeight;
}

int main(void)
{
    Node *root = NULL;
    root = insert(NULL, 10);
    printInOrder(root);
    printf("\n");
    insert(root, 20);
    insert(root, 9);
    printInOrder(root);
    printf("\n");
    assert((true == contains(root, 9)));
    assert((true == contains(root, 10)));
    assert((true == contains(root, 20)));
    assert((false == contains(root, 25)));
    insert(root, 25);
    assert((true == contains(root, 25)));

    printPreOrder(root);
    printf("\n");

    printPostOrder(root);
    printf("\n");

    printf("Height of Tree= %d\n", getHeight(root));
    insert(root, 30);
    printf("Height of Tree= %d\n", getHeight(root));

    return 0;
}