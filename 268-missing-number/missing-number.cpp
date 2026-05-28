class Solution{
    public:
    int missingNumber(vector<int> &nums){

        int n = nums.size();
        int xor1 = 0;
        int xor2 = 0;

        //Xor all the elements from 1 to n
        for(int i=0; i<=n; i++){
            xor1 = xor1^i;
        }

        //Xor all the elements present in the array
        for(int i=0; i<n; i++){
            xor2 = xor2^nums[i];
        }

        return xor1^xor2;
    }
};