/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        
        ListNode* head;
        if (l1->val < l2->val) {
            head = l1;
            head->next = mergeTwoLists(l1->next,l2);
        }
        else {
            head = l2;
            head->next = mergeTwoLists(l1,l2->next);
        }
        
        return head;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        
        if (!k)
            return NULL;
        while (lists.size() > 1) {
            int i = 0;
            while (i < lists.size()-1) {
                lists[i] = mergeTwoLists(lists[i],lists[i+1]);
                lists.erase(lists.begin()+i+1);
                ++i;
            }
        }
        
        return lists[0];
    }
};
