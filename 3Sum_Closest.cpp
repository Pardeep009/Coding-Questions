/*
  Problem -> https://leetcode.com/problems/3sum-closest/
  Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target.
  Return the sum of the three integers.
  
  Example:
  Given array nums = [-1, 2, 1, -4], and target = 1.
  The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution
{
public:
    int threeSumClosest(vector<int>& v,int target)
    {
        sort(v.begin(),v.end());
        int i,left,right=v.size()-1,sc=v[0]+v[1]+v[2],sum;
        for(i=0;i<v.size();i++)
        {
            left=i+1;
            right=v.size()-1;
            while(left<right)
            {
                sum=v[i]+v[left]+v[right];
                if(abs(sum-target)<abs(sc-target))
                {
                    sc=sum;
                }
                if(sum<target)
                    left++;
                else
                    right--;
            }
        }
        return sc;
    }
};
