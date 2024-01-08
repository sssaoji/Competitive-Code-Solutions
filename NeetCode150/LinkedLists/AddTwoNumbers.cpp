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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* ans = new ListNode();
        ListNode* curr;
        curr=ans;
        while(l1!=NULL && l2!=NULL)
        {
            int sum = (carry+l1->val+l2->val)%10;
            carry = (carry+l1->val+l2->val)/10;
            ListNode *temp = new ListNode(sum);
            curr->next=temp;
            l1=l1->next;
            l2=l2->next;
            curr=curr->next;
        }
        if(l1!=NULL)
        {
            while(l1!=NULL)
            {
                int sum = (carry+l1->val)%10;
                carry = (carry+l1->val)/10;
                ListNode *temp = new ListNode(sum);
                curr->next=temp;
                l1=l1->next;
                curr=curr->next;
            }
        }
        else if(l2!=NULL)
        {
            while(l2!=NULL)
            {
                int sum = (carry+l2->val)%10;
                carry = (carry+l2->val)/10;
                ListNode *temp = new ListNode(sum);
                curr->next=temp;
                l2=l2->next;
                curr=curr->next;
            }
        }
        if(carry>0)
        {
            ListNode *temp = new ListNode(carry);
            curr->next=temp;
        }
        return ans->next;
    }
};