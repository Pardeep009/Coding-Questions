Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should 
also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

Example 1:
Input: [1,2,3,4,5], k=4, x=3
Output: [1,2,3,4]
Example 2:
Input: [1,2,3,4,5], k=4, x=-1
Output: [1,2,3,4]

class Solution {
public:
    vector<int> findClosestElements(vector<int>& a, int k, int x) 
    {
        int size=a.size();
        if(x<=a[0])                // if first element is less than or euqal to x then first k element are answer
        {
            return vector<int>(a.begin(),a.begin()+k);
        }
        else if(x>=a[size-1])      // if last element is less than or euqal to x then last k element are answer   
        {
            return vector<int>(a.end()-k,a.end());
        }
        vector<int> res;
        int l=0,r=size-1,mid;
        while(l<=r)                      // find position of x if present otherwise first element greater than x
        {
            mid=(l+r)/2;
            if(a[mid]==x)
            {
                l=mid;
                break;
            }
            else if(a[mid]>x)
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        if(a[l]==x)
        {
            res.push_back(a[l]);
            l=l-1;
            r=l+2;
            k--;
        }
        else
        {
            r=l;
            l=l-1;
        }
        while(k>0&&l>=0&&r<=size-1)       // putting closer values to x in res vector
        {
            if(x-a[l]>a[r]-x)
            {
                res.push_back(a[r]);
                k--;
                r++;
            }
            else
            {
                res.push_back(a[l]);
                k--;
                l--;
            }
        }
        if(l==-1&&k>0)
        {
            while(k>0)
            {
                res.push_back(a[r]);
                k--;
                r++;
            }
        }
        else if(r==size&&k>0)
        {
            while(k>0)
            {
                res.push_back(a[l]);
                k--;
                l--;
            }
        }
       sort(res.begin(),res.end());     // required answer is in ascending form so sort it
        return res;
    }
};