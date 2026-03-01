#include <stdbool.h>
#include <stddef.h> // For NULL

// Definition of struct ListNode
struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return false; // No cycle if the list is empty or has only one node
    }

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // Move slow pointer one step
        fast = fast->next->next;    // Move fast pointer two steps

        if (slow == fast) {
            return true; // Cycle detected
        }
    }

    return false; // No cycle found
}