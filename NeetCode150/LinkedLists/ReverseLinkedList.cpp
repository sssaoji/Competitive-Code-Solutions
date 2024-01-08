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
    ListNode* soln(ListNode* curr, ListNode* prev)
    {
        if(curr==NULL)
        {
            return prev;
        }
        ListNode* temp;
        temp = curr->next;
        curr->next=prev;
        return soln(temp, curr);
    }
    ListNode* reverseList(ListNode* head) {
        return soln(head, NULL);
//        if(head==NULL||head->next==NULL)
//        {
//            return head;
//        }
//        ListNode* ans = reverseList(head->next);
//        ListNode* temp;
//        temp = head->next;
//        temp->next=head;
//        head->next=NULL;
//        return ans;
    }
};