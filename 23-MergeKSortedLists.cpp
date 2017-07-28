/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<priority_queue>
class Solution {
public:
    priority_queue<int>  q;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        for(int i = 0; i < len; i++){
            ListNode *temp = lists[i];
            while(temp != NULL){
                q.push(temp->val);
                temp = temp->next;
            }
        }

        ListNode *root = NULL;
        while(!q.empty()){
            cout << q.top();
            ListNode *temp = new ListNode(q.top());
            q.pop();
            temp->next = root;
            root = temp;
        }
        return root;
    }
};
