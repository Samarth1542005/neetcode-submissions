class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;
        map <int,int> mpp;
        for(auto it : hand)
        {
            mpp[it]++;
        }
        while(!mpp.empty())
        {
            int first = mpp.begin()->first;
            for(int i=0 ; i<groupSize ; i++)
            {
                int val = first+i;
                if(mpp.find(val) == mpp.end())
                {
                    return false;
                }
                mpp[val]--;
                if(mpp[val] == 0) mpp.erase(val);
            }
        }
        return true;
    }
};
