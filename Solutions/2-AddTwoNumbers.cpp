/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// WARNING - OVERLY VERBOSE AND UNNECESSARY CODE - WROTE IN 2 MINUTES
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = 0, len2 = 0, carry = 0;
        ListNode *temp = l1, *root;
        while(temp != NULL){
            temp = temp->next;
            len1++;
        }
        temp = l2;
        while(temp != NULL){
            temp = temp->next;
            len2++;
        }

        if(len1 >= len2) temp = l1;
        else temp = l2;
        root = temp;

        while(l1 != NULL && l2 != NULL){
            int value = (l1->val+l2->val+carry)%10;
            carry = (l1->val+l2->val+carry)/10;
            temp->val = value;

            cout << temp->val;
            l1 = l1->next;
            if(temp->next != NULL)
            temp = temp->next;
            l2 = l2->next;
        }

        while(l1 != NULL){
            int value = (l1->val+carry)%10;
            carry = (l1->val+carry)/10;
            temp->val = value;
            l1 = l1->next;
            if(temp->next != NULL)
            temp = temp->next;
        }

        while(l2 != NULL){
            int value = (l2->val+carry)%10;
            carry = (l2->val+carry)/10;
            temp->val = value;
            if(temp->next != NULL)
            temp = temp->next;
            l2 = l2->next;
        }

        if(carry != 0) temp->next = new ListNode(carry);

        return root;
    }
};
