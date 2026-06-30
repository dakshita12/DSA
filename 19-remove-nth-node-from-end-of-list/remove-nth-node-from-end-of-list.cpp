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

        ListNode* slow = head;
        ListNode* fast = head;

        // Move the fast pointer n steps ahead
        for(int i=0; i<n; i++){
            fast = fast->next;
        }

        // If fast becomes NULL, it means we need to remove the head node
        if(fast==NULL){
            return head->next;
        }

        // Move both pointers until fast reaches the last node
        // Slow will then point to the node just before the one to be deleted
        while(fast->next!=NULL){
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete(delNode);
        return head;

    }
};