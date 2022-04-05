#ifndef BST_H_
#define BST_H_

#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct Node_t
    {
        struct Node_t *left;
        struct Node_t *right;

        int data;
    } Node;

    /* Insert a node into the tree.
     * Returns the root of the tree
     */
    extern Node *insert(Node *node, int value);

    /* Is the value contained in the tree. */
    extern bool contains(Node *node, int value);

    /*   A
     *  / \
     * B   C
     * print (left, root, right) or B, A, C
     */
    extern void printInOrder(Node *node);

    /*   A
     *  / \
     * B   C
     * print (root, left, right) or A, B, C
     */
    extern void printPreOrder(Node *node);

    /*   A
     *  / \
     * B   C
     * print (left, right, root) or B, C, A
     */
    extern void printPostOrder(Node *node);

    /* Get depth of the tree. */
    extern int getHeight(Node *node);

#ifdef __cplusplus
}
#endif

#endif // BST_H_