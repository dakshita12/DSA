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

    ListNode* reverseLL(ListNode* head){

        if(head==NULL || head->next==NULL) return head;
        
        ListNode* prev = NULL;
        ListNode* temp = head;
        
        while(temp!=NULL){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }


    bool isPalindrome(ListNode* head){

        if(head==NULL || head->next==NULL) return true;

        // Use Tortoise and Hare Algo to find middle node
        ListNode* slow = head; 
        ListNode* fast = head;

        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the linked list from the node next to the middle.
        ListNode* newHead = reverseLL(slow->next);

        // Pointer to first half and second half
        ListNode* first = head;
        ListNode* second = newHead;

        // Compare data value from both halves and reverse second half back to original 
        while(second!=NULL){
            if(first->val != second->val){
                reverseLL(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverseLL(newHead);
        return true;
    }
};