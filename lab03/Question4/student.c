#include <stddef.h>

// Define the ListNode structure
struct ListNode {
    int value;
    struct ListNode *next;
};

int middleNodeValue(struct ListNode *head) {
    if (head == NULL) {
        return -1; // Return -1 or an appropriate error value if the list is empty
    }

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // Move fast pointer two steps and slow pointer one step at a time
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // When fast reaches the end, slow is at the middle
    return slow->value;
}
