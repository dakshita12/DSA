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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        if(headA==NULL || headB==NULL) return NULL;

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        // Traverse until both pointers meet
        while(temp1 != temp2){

            // Move both pointers
            temp1 = temp1->next;
            temp2 = temp2->next;

            // If they meet after moving, return the intersection node
            if(temp1 == temp2) return temp1;

            // When temp1 reaches the end of List A, redirect it to the head of List B
            if(temp1 == NULL){
                temp1 = headB;
            }

            // When temp2 reaches the end of List B, redirect it to the head of List A
            if(temp2 == NULL){
                temp2 = headA;
            }
        }
        return temp1;
    }
};