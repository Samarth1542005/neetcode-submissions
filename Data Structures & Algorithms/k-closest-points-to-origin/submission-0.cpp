class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& nums, int k) {
        priority_queue<
            pair<int, vector<int>>,
            vector<pair<int, vector<int>>>,
            greater<pair<int, vector<int>>>
        > pq;

        int n = nums.size();

        for (int i = 0; i < n; i++) 
        {
            int x = nums[i][0];
            int y = nums[i][1];

            int dist = x * x + y * y;

            pq.push({dist, {x, y}});
        }

        vector<vector<int>> ans;

        while (!pq.empty() && k > 0) 
        {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return ans;

    }
};
