#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{

	return 0;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode;
struct ListNode* middleNode(struct ListNode* head) {
    if (head == NULL) {
        return head;
    }
    ListNode* n1 = head;
    ListNode* n2 = head;
    while (n2 && n2->next) {
        n1 = n1->next;
        n2 = n2->next->next;
    }
    return n1;
}

//--------------------------------------------------------------------------------------------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode;
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }
    ListNode* n1 = list1;
    ListNode* n2 = list2;
    ListNode* newhead = NULL;
    ListNode* newtail = NULL;
    while (n1 && n2) {
        if (n1->val < n2->val) {
            if (newhead == NULL) {
                newhead = newtail = n1;
            }
            else {
                newtail->next = n1;
                newtail = newtail->next;
            }
            n1 = n1->next;
        }
        else {
            if (newhead == NULL) {
                newhead = newtail = n2;
            }
            else {
                newtail->next = n2;
                newtail = newtail->next;
            }
            n2 = n2->next;
        }
    }
    if (n1) {
        newtail->next = n1;
    }
    if (n2) {
        newtail->next = n2;
    }
    return newhead;
}


//--------------------------------------------------------------------------------------------------------------


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode;
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }
    ListNode* n1 = list1, * n2 = list2;
    ListNode* newhead, * newtail;
    newhead = newtail = (ListNode*)malloc(sizeof(ListNode));
    while (n1 && n2) {
        if (n1->val < n2->val) {
            newtail->next = n1;
            newtail = newtail->next;
            n1 = n1->next;
        }
        else {
            newtail->next = n2;
            newtail = newtail->next;
            n2 = n2->next;
        }
    }
    if (n1)
        newtail->next = n1;
    if (n2)
        newtail->next = n2;
    return newhead->next;
}


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;
struct ListNode* partition(struct ListNode* head, int x) {
    ListNode* lesshead, * lesstail;
    lesshead = lesstail = (ListNode*)malloc(sizeof(ListNode));
    ListNode* greathead, * greattail;
    greathead = greattail = (ListNode*)malloc(sizeof(ListNode));
    ListNode* pcur = head;
    while (pcur) {
        if (pcur->val < x) {
            lesstail->next = pcur;
            lesstail = lesstail->next;
            pcur = pcur->next;
        }
        else {
            greattail->next = pcur;
            greattail = greattail->next;
            pcur = pcur->next;
        }
    }
    greattail->next = NULL;
    lesstail->next = greathead->next;
    ListNode* ret = lesshead->next;
    //lesstail->next = greathead->next;
    free(lesshead);
    free(greathead);
    lesshead = greathead = NULL;
    return ret;
    // return greathead->next;
}
