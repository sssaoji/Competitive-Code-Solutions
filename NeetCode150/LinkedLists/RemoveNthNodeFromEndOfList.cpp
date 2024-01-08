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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr, *ini;
        ListNode* temp = new ListNode();
        temp->next=head;
        head = temp;
        curr=head;
        ini=head;
        int diff=0;
        while(ini!=NULL && diff!=n)
        {
            ini=ini->next;
            diff++;
        }
        while(ini->next!=NULL)
        {
            curr=curr->next;
            ini=ini->next;
        }
        temp = curr->next->next;
        curr->next=temp;
        return head->next;
    }
};