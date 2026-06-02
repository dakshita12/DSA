class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        vector<pair<int,int>> numsWithIndex;

        // To store original indices 
        for(int i=0; i<n; i++){
            numsWithIndex.push_back({nums[i],i});
        }

        sort(numsWithIndex.begin(), numsWithIndex.end());

        int left = 0;
        int right = n-1;

        while(left<right){

            int sum = numsWithIndex[left].first + numsWithIndex[right].first;

            if(sum < target){
                left++;
            }
            else if(sum == target){
                return {numsWithIndex[left].second, numsWithIndex[right].second};
            }
            else{
                right--;
            }
        }

        return {-1,-1};

    }
};