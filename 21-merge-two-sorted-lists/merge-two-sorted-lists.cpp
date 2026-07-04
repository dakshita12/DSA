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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // Pointers to traverse both linked lists
        ListNode* t1 =  list1;
        ListNode* t2 = list2;

        // Dummy node to simplify the merge process and a temp pointer
        ListNode* dNode = new ListNode(-1);
        ListNode* temp = dNode;

        // Traverse both lists until one of them becomes empty
        while(t1!=NULL && t2!=NULL){

            // Attach the smaller node to the merged list
            if(t1->val < t2->val){
                temp->next = t1;
                temp = t1;
                t1 = t1->next;
            }
            else{
                temp->next = t2;
                temp = t2;
                t2 = t2->next;
            }
        }

        // Attach the remaining nodes of the non-empty list
        if(t1){
            temp->next = t1;
        }
        else{
            temp->next = t2;
        }

        // Store the head of the merged linked list and return
        ListNode* ans = dNode->next; 
        delete dNode;
        return ans;
    }
};