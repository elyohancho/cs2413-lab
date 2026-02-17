// Question1/Student.c
// ------------------------------------------------------------
// CS Lab - Valid Parentheses (STACK PRACTICE)
//
// Task:
// Implement `isValid(const char *s)`.
// Given a string s containing only: () {} []
// return true if it is a valid parentheses string, else false.
//
// Valid rules:
// 1) Open brackets must be closed by the same type of brackets.
// 2) Open brackets must be closed in the correct order.
// 3) Every close bracket has a corresponding open bracket.
//
// Examples:
//   s = "()"        -> true
//   s = "()[]{}"    -> true
//   s = "(]"        -> false
//   s = "([)]"      -> false
//   s = "{[]}"      -> true
//   s = ""          -> true   (empty string is valid)
//
// How to run tests (from the folder containing the Makefile):
//   make run1
// ------------------------------------------------------------

#include "student.h"
#include <stdbool.h>
#include <stddef.h>  // size_t
#include <string.h>  // strlen

bool isValid(const char *s) {
    if (s == NULL || strlen(s) % 2 != 0) {
        return false; // NULL or odd length strings can't be valid
    }

    char stack[strlen(s)];
    size_t top = 0; // Stack pointer

    for (size_t i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            // Push opening brackets onto the stack
            stack[top++] = c;
        } else {
            // If stack is empty, invalid string
            if (top == 0) {
                return false;
            }
            // Check if the top of the stack matches the closing bracket
            char topChar = stack[top - 1];
            if ((c == ')' && topChar == '(') ||
                (c == ']' && topChar == '[') ||
                (c == '}' && topChar == '{')) {
                top--; // Pop the stack
            } else {
                return false; // Mismatched closing bracket
            }
        }
    }

    // Stack must be empty for a valid string
    return top == 0;
}
