#include <stdbool.h>
#include <stddef.h>
#include <limits.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int checkAVL(struct TreeNode* node, long min, long max) {
    if (node == NULL)
        return 0;

    // Check strict BST property
    if (node->val <= min || node->val >= max)
        return -1;

    int leftHeight = checkAVL(node->left, min, node->val);
    if (leftHeight == -1)
        return -1;

    int rightHeight = checkAVL(node->right, node->val, max);
    if (rightHeight == -1)
        return -1;

    // Check AVL balance
    if (abs(leftHeight - rightHeight) > 1)
        return -1;

    // Return height
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

bool isAVL(struct TreeNode* root) {
    return checkAVL(root, LONG_MIN, LONG_MAX) != -1;
}