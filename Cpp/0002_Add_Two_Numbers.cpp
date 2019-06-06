/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        int carry = 0;
        
        while (l1 || l2) {
            int a = (l1) ? l1->val : 0;
            int b = (l2) ? l2->val : 0;
            
            int c = a + b + carry;
            
            if (c > 9) {
                carry = 1;
                c -= 10;
            }
            else
                carry = 0;
            
            curr->next = new ListNode(c);
            
            curr = curr->next;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        
        if (carry)
            curr->next = new ListNode(carry);
        
        return head->next;
    }
};
