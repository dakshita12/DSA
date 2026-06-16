class Solution{
public:
    int findMin(vector<int>& nums) {

        int n = nums.size();
        int s = 0;
        int e = n-1;
        int min = INT_MAX;

        while(s<e){

            int mid = s + (e-s)/2;

            if(nums[mid]>nums[e]){
                s = mid+1;
            }
            else{
                e = mid;
            }
        }

        return nums[s];
    }
};