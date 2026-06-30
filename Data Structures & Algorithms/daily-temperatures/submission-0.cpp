class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n = arr.size();
        vector <int> ans(n);
        stack <int> st;
        for(int i=n-1 ; i>=0 ; i--)
        {
            while(!st.empty() && arr[st.top()] <= arr[i])
            {
                st.pop();
            }
            ans[i] = st.empty() ? 0 : st.top()-i;
            st.push(i);
        }
        return ans;
    }
};
