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
    bool hasCycle(ListNode *head) {
        ListNode *slw, *fst;
        slw = head;
        fst = head;
        while(fst!=NULL&&fst->next!=NULL)
        {
            fst=fst->next->next;
            slw=slw->next;
            if(fst==slw)
            {
                return true;
            }
        }
        return false;
    }
};