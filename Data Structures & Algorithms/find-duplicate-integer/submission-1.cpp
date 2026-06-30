class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // Move once before entering the loop
        slow = nums[slow];
        fast = nums[nums[fast]];

        // Step 1: Find the meeting point
        while (slow != fast) 
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        // Step 2: Find the entrance of the cycle
        slow = nums[0];

        while (slow != fast) 
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
