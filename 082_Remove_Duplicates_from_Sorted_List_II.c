// Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
//
// For example,
// Given 1->2->3->3->4->4->5, return 1->2->5.
// Given 1->1->1->2->3, return 2->3.

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
    if (head->next==NULL) {
        return head;
    }
    
    v=head->val;
    
    if (head->next->val==v) {
        while (head->val==v) {
            head=head->next;
            
            if (head==NULL) {
                break;
            }
        }
        
        return deleteDuplicates(head);
    }
    else {
        head->next=deleteDuplicates(head->next);
        
        return head;
    }
}
