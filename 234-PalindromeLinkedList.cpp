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
    bool isPalindrome(ListNode* head) {
        ListNode *temp = head;
        int count = 0;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }

        if(count <= 1) return true;

        int half = count/2;
        ListNode *prevNode = NULL, *curNode = head, *nextNode = NULL;

        while(half > 0){
            nextNode = curNode->next;
            curNode->next = prevNode;
            prevNode = curNode;
            curNode = nextNode;
            half--;
        }

        if(count%2 != 0) nextNode = nextNode->next;

        while(nextNode != NULL && prevNode != NULL){
            if(nextNode->val != prevNode->val) return false;

            nextNode = nextNode->next;
            prevNode = prevNode->next;
        }

        return true;
    }
};
