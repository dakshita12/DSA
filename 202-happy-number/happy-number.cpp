class Solution {
public:
    int squareSum(int n){
        int sum = 0;
        while(n>0){
            int d = n%10;    // Extract the last digit
            sum = sum + d*d; // Add its square to the sum
            n = n/10;        // Remove the last digit
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        while(fast != 1){
            slow = squareSum(slow);
            fast = squareSum(fast);
            fast = squareSum(fast);

            // If both pointers meet at a no other than 1, cycle exists, the number is not happy.
            if(slow==fast && slow!=1){
                return false;
            }
        }
        return true;
    }
};