// trapping rain water problem
//https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& a) 
    {
        int n=a.size();
        if(n==0)
            return 0;
        int j,i,k=0;
        int water=0;
        for(i=0;i<n;i++)
        {
            if(a[k]<a[i])
            {
                k=i;         // find index of max height bar
            }
        }
        j=0;
        for(i=1;i<k;i++)
        {
            if(a[i]<a[j])
            {
                water+=a[j]-a[i];     // water stored on left of k
            }
            else
            {
                j=i;
            }
        }
        j=n-1;
        for(i=n-2;i>k;i--)
        {
            if(a[i]<a[j])
            {
                water+=a[j]-a[i];    // water stored on right of k
            }
            else
            {
                j=i;
            }
        }
        return water;
    }
};