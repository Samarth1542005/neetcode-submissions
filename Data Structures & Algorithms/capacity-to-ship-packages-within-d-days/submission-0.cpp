class Solution {
public:
    int NoOfD(vector <int> &arr, int cap)
    {
        int day=1,load=0;
        for(int i=0 ; i<arr.size() ; i++)
        {
            if(load+arr[i]>cap)
            {
                day+=1;
                load=arr[i];
            }
            else
            {
                load+=arr[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        int ans=0;
        while(low<=high)
        {
            int mid = (low+high)/2;
            int day=NoOfD(weights,mid);
            if(day<=days)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};