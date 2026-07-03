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

        // Create a dummy node and a pointer to it
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;

        int carry = 0;

        while(l1!=NULL || l2!=NULL || carry){

            int sum = 0;

            // Add digit from first list if available
            if(l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }
 
            // Add digit from second list if available
            if(l2 != NULL){
                sum += l2->val;
                l2 = l2->next;               
            }

            sum += carry;
            carry = sum/10;
            
            // Create a new node with the current digit
            ListNode* node = new ListNode(sum%10);
 
            // Attach the new node to the answer list and move pointer to next
            temp->next = node;
            temp = temp->next;
        }

        return dummy->next;
    }
};