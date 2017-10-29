/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head = l1;
    int flag = 0;
    
    l1->val += l2->val;
    if (l1->val > 9) {
        l1->val -= 10;
        flag++;
        }
    
    while (l1->next || l2->next) {
        if (!l2->next) {
            break;
        }
        if (!l1->next) {
            l1->next = l2->next;
            break;
        }
        
        l1 = l1->next;
        l2 = l2->next;
        
        l1->val += l2->val+flag;
        flag = 0;
        
        if (l1->val > 9) {
            l1->val -= 10;
            flag++;
            }
    }
    
    while (l1->next && flag == 1) {
        l1 = l1->next;
        
        l1->val += flag;
        flag = 0;
        
        if (l1->val > 9) {
            l1->val -= 10;
            flag++;
            }
    }
    
    if (!l1->next && flag == 1){
        struct ListNode* temp = malloc(sizeof(struct ListNode));
        temp->val = 1;
        temp->next = NULL;
        
        l1->next = temp;
    }
    
    return head;
}
