/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool cmp(Interval &a, Interval &b)
    {
        return a.start < b.start;
    }

    bool canAttendMeetings(vector<Interval>& intervals) 
    {

        if(intervals.empty()) return true;

        sort(intervals.begin(), intervals.end(), cmp);

        int maxi = intervals[0].end;

        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i].start >= maxi)
            {
                maxi = intervals[i].end;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};