/*
Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp = new ListNode(0);
        temp->next = head;
        head = temp;
        
        while (temp->next && temp->next->next) {
            ListNode* p = temp->next;
            temp->next = temp->next->next;
            p->next = p->next->next;
            temp->next->next = p;
            
            temp = temp->next->next;
        }
        
        return head->next;
    }
};
