/*
  Subarray Product Less Than K
  problem -> https://leetcode.com/problems/subarray-product-less-than-k/
  Your are given an array of positive integers nums.

  Count and print the number of (contiguous) subarrays where the product of all the elements in the subarray
  is less than k.

  Example 1:
  Input: nums = [10, 5, 2, 6], k = 100
  Output: 8
  Explanation: The 8 subarrays that have product less than 100 are: [10], [5], [2], [6], [10, 5], [5, 2],
  [2, 6], [5, 2, 6].
  Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.

*/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& a, int k)
    {
        int size=a.size();
        long int c=0;
        if(k<=1)
        {
            return 0;
        }
        long int p=1,s=0,e1=-1,e,no,f=0;
        for(int i=0;i<size;)
        {
            if(p*a[i]<k)
            {
                e=i;
                p=p*a[i];
                f=1;
                i++;
            }
            else if(f)
            {
                if(s>e1)
                {
                    no=e-s+1;
                    c=c+((no)*(no+1))/2;
                }
                else
                {
                    no=e1-s+1;
                    c=c+no*(e-e1);
                    no=e-e1;
                    c=c+((no)*(no+1))/2;
                }
                e1=e;
                f=0;
            }
            else if(s<=e)
            {
                p=p/a[s];
                s++;
            }
            else
            {
                i++;
                s=i;
                e=i;
            }
        }
        if(f)
        {
            if(s>e1)
            {
                no=e-s+1;
                c=c+((no)*(no+1))/2;
            }
            else
            {
                no=e1-s+1;
                c=c+no*(e-e1);
                no=e-e1;
                c=c+((no)*(no+1))/2;
            }
        }
        return c;
    }
};
/*
  Java Soln :->
  class Solution 
  {
    public int numSubarrayProductLessThanK(int[] nums, int k) 
    {
        if (k <= 1) 
          return 0;
        int prod = 1, ans = 0, left = 0;
        for (int right = 0; right < nums.length; right++) 
        {
            prod *= nums[right];
            while (prod >= k) 
              prod /= nums[left++];
            ans += right - left + 1;
        }
        return ans;
    }
  }
*/
