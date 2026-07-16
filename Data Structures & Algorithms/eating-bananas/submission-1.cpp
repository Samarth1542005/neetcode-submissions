class Solution {
public:
    long long totalHours(vector <int> v , int hourly)
    {
        long long total = 0;
        int n = v.size();
        for(int i=0 ; i<n ; i++)
        {
            total += ceil((double)v[i] / (double)hourly);
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low=1 , high=*max_element(piles.begin(),piles.end());
        while(low<=high)
        {
            long long mid = (low+high) / 2;
            long long total = totalHours(piles,mid);
            if(total <= h)
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return low;
    }
};
