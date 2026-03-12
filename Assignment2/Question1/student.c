#include <stddef.h> // For NULL

// Definition of TreeNode structure
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* bstSearch(struct TreeNode* root, int target) {
    // Base case: if root is NULL or the target is found
    if (root == NULL || root->val == target) {
        return root;
    }

    // If target is smaller than root's value, search in the left subtree
    if (target < root->val) {
        return bstSearch(root->left, target);
    }

    // If target is greater than root's value, search in the right subtree
    return bstSearch(root->right, target);
}
