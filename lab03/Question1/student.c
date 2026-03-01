#include "student.h"
#include <stddef.h>  // For NULL definition

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;  // Initialize previous pointer to NULL
    struct ListNode* current = head;  // Start with the head of the list
    struct ListNode* next = NULL;  // Temporary pointer to store the next node

    while (current != NULL) {
        next = current->next;  // Store the next node
        current->next = prev;  // Reverse the current node's pointer
        prev = current;  // Move the previous pointer forward
        current = next;  // Move the current pointer forward
    }

    return prev;  // New head of the reversed list
}
