class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int total = 0;
        int sum = 0;
        int n = nums.size();
        for(int i=0 ; i<n ; i++)
        {
            total += i+1;
            sum += nums[i];
        }
        return total-sum; 
    }
};
