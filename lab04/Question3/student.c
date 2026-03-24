#include <stdio.h>
#include <stdlib.h>

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

/* Helper */
int helper(struct TreeNode* root, int current) {
    if (root == NULL) return 0;

    current = current * 10 + root->val;

    if (root->left == NULL && root->right == NULL) {
        return current;
    }

    return helper(root->left, current) +
           helper(root->right, current);
}

/* Main Function */
int sumNumbers(struct TreeNode* root) {
    return helper(root, 0);
}

int main() {
    /*
          4
         / \
        9   0
       / \
      5   1
    */

    struct TreeNode* root = createNode(4);
    root->left = createNode(9);
    root->right = createNode(0);

    root->left->left = createNode(5);
    root->left->right = createNode(1);

    printf("Sum: %d\n", sumNumbers(root)); // 1026

    return 0;
}