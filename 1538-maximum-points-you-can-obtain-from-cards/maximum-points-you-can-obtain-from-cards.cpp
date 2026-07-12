class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n = cardPoints.size();
        int maxSum = 0;

        // Sum of cards taken from the left and right
        int lsum = 0;
        int rsum = 0;

        // Initially, take all k cards from the left.
        for(int i=0; i<k; i++){
            lsum += cardPoints[i];
        }

        // Current maximum score is the sum of first k cards.
        maxSum = lsum;

        // Pointer to the last element of the array
        int rightidx = n-1;

        // Gradually replace one left card with one right card.
        for(int i=k-1; i>=0; i--){
            lsum -= cardPoints[i];
            rsum += cardPoints[rightidx];
            rightidx--;
            maxSum = max(maxSum, lsum + rsum);
        }

        return maxSum;
    }
};