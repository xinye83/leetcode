// Given a sorted linked list, delete all duplicates such that each element appear only once.
//
// For example,
// Given 1->1->2, return 1->2.
// Given 1->1->2->3->3, return 1->2->3.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    int v;
    struct ListNode *next;
    
    if (head==NULL) {
        return head;
    }
    
    v=head->val;
    next=head->next;
    
    while (next!=NULL && v==next->val) {
        next=next->next;
    }
    
    next=deleteDuplicates(next);
    
    head->next=next;
    
    return head;
}
