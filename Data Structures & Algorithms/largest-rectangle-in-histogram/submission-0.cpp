class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        int maxi = 0;

        for (int i = 0; i < n; i++) 
        {
            while (!st.empty() && nums[i] < nums[st.top()]) 
            {
                int topInd = st.top();
                st.pop();

                int right = i;
                int left = st.empty() ? -1 : st.top();

                int height = nums[topInd];
                int width = right - left - 1;

                maxi = max(maxi, height * width);
            }
            st.push(i);
        }

        while (!st.empty()) 
        {
            int topInd = st.top();
            st.pop();

            int right = n;
            int left = st.empty() ? -1 : st.top();

            int height = nums[topInd];
            int width = right - left - 1;

            maxi = max(maxi, height * width);
        }

        return maxi;
    }
};
