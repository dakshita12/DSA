class Solution{

    private:
    int findFirst(vector<int> &nums, int target){

        int n = nums.size();
        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;
        int first = -1;
        
        while(s<=e){

            if(nums[mid]==target){
                first = mid;
                e = mid - 1;
            }
            else if(nums[mid]>target){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
            mid = s + (e-s)/2;
        }
        return first;
    }

    int findLast(vector<int> &nums, int target){

        int n = nums.size();
        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;
        int last = -1;
        
        while(s<=e){

            if(nums[mid]==target){
                last = mid;
                s = mid + 1;
            }
            else if(nums[mid]>target){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
            mid = s + (e-s)/2;
        }
        return last;
    }


    public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int first = findFirst(nums, target);
        int last = findLast(nums, target);

        return {first, last};
    }

};

