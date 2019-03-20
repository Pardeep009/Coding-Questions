/*
https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

A conveyor belt has packages that must be shipped from one port to another within D days.

The i-th package on the conveyor belt has a weight of weights[i].  Each day, we load the ship with packages 
on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight 
capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being
 shipped within D days.

Example 1:

Input: weights = [1,2,3,4,5,6,7,8,9,10], D = 5
Output: 15
Explanation: 
A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed. 
Example 2:

Input: weights = [3,2,2,4,1,4], D = 3
Output: 6
Explanation: 
A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4
Example 3:

Input: weights = [1,2,3,1,1], D = 4
Output: 3
Explanation: 
1st day: 1
2nd day: 2
3rd day: 3
4th day: 1, 1
*/

class Solution {
public:
    int fulfilled(int D,int cap,vector<int>& w,int size)
    {
        int i,c=0,sum=0;
        for(i=0;i<size;i++)
        {
            if(w[i]>cap)
                return 1;
            if(sum+w[i]>cap)
            {
                c++;
                sum=0;
                i--;
                if(c>D)
                {
                    return 1;
                }
            }
            else
            {
                sum+=w[i];
            }
        }
        c++;
        if(c>D)
        {
            return 1;
        }
        else
            return 0;
    }
    int shipWithinDays(vector<int>& w, int D) 
    {
        int mid,r=0,size=w.size(),i,l=1,value;
        for(i=0;i<size;i++)
        {
            l=max(l,w[i]);
            r+=w[i];
        }
        
        while(l<r)
        {
            mid=(l+r)/2;
            value=fulfilled(D,mid,w,size);
            if(value)
            {
                l=mid+1;
            }
            else
            {
                r=mid;
            }
        }
        return l;
    }
};