#include "student.h"

struct ListNode* swapPairs(struct ListNode* head) {
      if (head == NULL || head->next == NULL) {
            return head; // Base case: if the list is empty or has only one node, no swap needed
      }

      struct ListNode* newHead = head->next; // The second node will become the new head
      struct ListNode* prev = NULL;
      struct ListNode* current = head;

      while (current != NULL && current->next != NULL) {
            struct ListNode* nextPair = current->next->next; // Save the next pair
            struct ListNode* second = current->next;         // The second node in the current pair

            // Swap the current pair
            second->next = current;
            current->next = nextPair;

            // Connect the previous pair to the current swapped pair
            if (prev != NULL) {
                  prev->next = second;
            }

            // Update the previous node and move to the next pair
            prev = current;
            current = nextPair;
      }

      return newHead; // Return the new head list
}