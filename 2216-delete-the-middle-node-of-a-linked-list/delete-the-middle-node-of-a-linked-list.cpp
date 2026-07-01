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
    ListNode* deleteMiddle(ListNode* head) {
        
        if(head==NULL || head->next==NULL){
            return NULL;
        }

        // Tortoise and Hare Algo

        ListNode* slow = head;
        ListNode* fast = head;
        
        // Initialize fast pointer two steps ahead so that slow stops at the node just before the middle node.
        fast = fast->next->next;

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* middleNode = slow->next;
        slow->next = slow->next->next;
        delete middleNode;
        return head;
    }
};