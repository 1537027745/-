#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode;
struct ListNode* removeElements(struct ListNode* head, int val) {
    ListNode* newhead = NULL;
    ListNode* newtail = NULL;
    ListNode* pruc = head;
    while (pruc) {
        if (pruc->val != val) {
            if (newhead == NULL) {
                newhead = newtail = pruc;
            }
            else {
                newtail->next = pruc;
                newtail = newtail->next;
            }
        }
        pruc = pruc->next;
    }
    if (newtail) {
        newtail->next = NULL;
    }
    return newhead;
}