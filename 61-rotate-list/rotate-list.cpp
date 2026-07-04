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
    ListNode* findNthNode(ListNode* temp, int k){
        int cnt = 1;
        while(temp!=NULL){
            if(cnt==k) return temp;
            cnt++;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL || head->next == NULL) return head;

        int len = 1;
        ListNode* tail = head;
        
        while(tail->next != NULL){
            len++;
            tail = tail->next;
        }

        // If k is a multiple of length, no rotation is needed
        if(k % len == 0){
            return head;
        }

        // Reduce unnecessary full rotations
        k = k % len;

        // Connect the last node to the head to form a circular linked list
        tail->next = head;

        // Find the new last node after rotation
        ListNode* newHead = findNthNode(head, len-k);

        // The next node becomes the new head
        head = newHead->next;

        // Break the circular linked list
        newHead->next = NULL;

        return head;
    }
};