class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int n = nums.size();
        unordered_map<int, int> mp;
        
        int prefixSum = 0;
        int count = 0;

        mp[0] = 1;

        for(int i=0; i<n; i++){

            prefixSum += nums[i];
            int remove = prefixSum - k;

            if(mp.find(remove) != mp.end()){
                count += mp[remove];
            }
            mp[prefixSum]++;

        }

        return count;
    }
};