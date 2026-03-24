#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Tree Node */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/* Create Node */
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* Mirror Check */
bool isMirror(struct TreeNode* a, struct TreeNode* b) {
    if (a == NULL && b == NULL) return true;
    if (a == NULL || b == NULL) return false;

    return (a->val == b->val) &&
           isMirror(a->left, b->right) &&
           isMirror(a->right, b->left);
}

/* Symmetric Check */
bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) return true;
    return isMirror(root->left, root->right);
}

int main() {
    /*
        1
       / \
      2   2
     / \ / \
    3  4 4  3
    */

    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(2);

    root->left->left = createNode(3);
    root->left->right = createNode(4);
    root->right->left = createNode(4);
    root->right->right = createNode(3);

    printf("Is Symmetric: %s\n", isSymmetric(root) ? "true" : "false");

    return 0;
}