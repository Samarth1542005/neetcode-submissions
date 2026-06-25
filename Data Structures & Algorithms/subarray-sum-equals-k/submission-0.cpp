class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int total = 0;
        unordered_map <int,int> mpp;
        mpp[0] = 1;
        int preSum = 0;
        for(int i=0 ; i<nums.size() ; i++)
        {
            preSum += nums[i];
            int rem = preSum - k;
            total += mpp[rem];
            mpp[preSum] += 1;
        }
        return total;
    }
};