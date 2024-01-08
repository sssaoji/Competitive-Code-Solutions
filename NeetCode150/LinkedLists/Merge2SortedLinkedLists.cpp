/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* p = list1;
        ListNode *q = list2;
        ListNode* curr = new ListNode();
        ListNode* ans = curr;
        while(q!=NULL&&p!=NULL)
        {
            if(p->val<q->val)
            {
                curr->next=p;
                curr=curr->next;
                p=p->next;
            }
            else
            {
                curr->next=q;
                curr=curr->next;
                q=q->next;
            }
        }
        if(q)
        {
            curr->next=q;
        }
        else
        {
            curr->next=p;
        }
        return ans->next;
    }
};