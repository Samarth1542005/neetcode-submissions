class Solution {
public:
    static bool comparator(const vector<int> val1 , const vector<int> val2)
    {
        return val1[1] < val2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),comparator);
        int cnt = 1;
        int LastEnd = intervals[0][1];
        for(int i=1 ; i<n ; i++)
        {
            if(intervals[i][0] >= LastEnd)
            {
                cnt++;
                LastEnd = intervals[i][1];
            }
        }
        return n - cnt;
    }
};
