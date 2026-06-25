class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector <int> temp(n);
        for(int i=0 ; i<n ; i++)
        {
            int left = 0 , high = n-1;
            int ans = 1;
            while(left < i || high>i)
            {
                if(left < i)
                {
                    ans *= nums[left];
                    left++;
                }
                if(high > i)
                {
                    ans*= nums[high];
                    high--;
                }
            }
            temp[i] = ans;
        }

        return temp;
    }
};
