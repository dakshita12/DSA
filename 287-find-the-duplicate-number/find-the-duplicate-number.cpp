class Solution {
public:

    // Using slow and fast pointers
    int findDuplicate(vector<int>& nums) {

        // Initialize both pointers at index 0.
        int slow = 0;
        int fast = 0;

        // Find the meeting point inside the cycle by moving slow by one step and fast by two steps
        while(true){

            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
  
            // Cycle detected.
            if(slow==fast){

                slow = 0;

                // Move both pointers one step at a time. They meet at start of the cycle, which represents the duplicate number.
                while(slow!=fast){
                    slow = nums[slow];
                    fast = nums[fast];
                }
                return slow;
            }
        }
    }
};