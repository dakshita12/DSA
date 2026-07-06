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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // Min heap to always get the smallest node among all current list heads.
        // Pair stores {node value, node address}.
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode* >>> pq;

        // Push the first node of every non-empty linked list into the heap.
        for(int i=0; i<lists.size(); i++){
            if(lists[i]){
                pq.push({lists[i]->val, lists[i]});
            }
        }
 
        // Dummy node to simplify result list construction.
        ListNode* dummy = new ListNode(-1);
        ListNode* temp =dummy;

        // Process nodes until the heap becomes empty.
        while(!pq.empty()){

            // Extract the smallest node.
            auto it = pq.top();
            pq.pop();

            // If the extracted node has a next node, push it into the heap.
            if(it.second->next){
                pq.push({it.second->next->val, it.second->next});
            }

            // Append the smallest node to the merged list.
            temp->next = it.second;
            temp = temp->next;
        }

        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};