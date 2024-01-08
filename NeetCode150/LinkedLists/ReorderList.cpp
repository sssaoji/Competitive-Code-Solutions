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
    void reorderList(ListNode* head) {
        ListNode* slow; ListNode* fast;
        slow = head;
        fast = head->next;
        while(fast!=NULL&&fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *bkp;
        bkp = slow->next;
        slow->next=NULL;
        ListNode* prev, *curr;
        curr = bkp;
        prev=NULL;
        while(curr!=NULL)
        {
            ListNode*temp;
            temp = curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        curr=head;
        while(prev!=NULL)
        {
            ListNode *temp, *temp1;
            temp = curr->next;
            temp1=prev->next;
            curr->next=prev;
            prev->next=temp;
            curr=curr->next->next;
            prev=temp1;
        }
    }
};