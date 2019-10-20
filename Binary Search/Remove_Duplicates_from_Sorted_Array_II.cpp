/*
  problem -> https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

  Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most
  twice and return the new length.
  Do not allocate extra space for another array, you must do this by modifying the input array
  in-place with O(1) extra memory.

Example 1:
Given nums = [1,1,1,2,2,3],
Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3
respectively.

 Example 2:
 Given nums = [0,0,1,1,1,1,2,3,3],
 Your function should return length = 7, with the first seven elements of nums being modified to 0, 0,
 1, 1, 2, 3 and 3 respectively.

*/

class Solution {
public:
    int removeDuplicates(vector<int>& a)
    {
        int size=a.size();
        if(size==0)
            return 0;
        int i,j,c=1,f=1,k;
        for(i=1;i<size;i++)
        {
            if(a[i]==a[i-1])
            {
                c++;
                if(c>2)
                {
                    if(f)
                    {
                        j=i;
                        f=0;
                    }
                }
            }
            else
            {
                c=1;
                if(!f)
                {
                    c=j;
                    for(k=i;k<size;)
                    {
                        a[j++]=a[k++];
                    }
                    size=size-(k-j);
                    i=c;
                    c=1;
                    f=1;
                }
            }
        }
        if(!f)
        {
            for(k=i;k<size;)
            {
                a[j++]=a[k++];
            }
            size=size-(k-j);
        }
        a.erase(a.begin()+size,a.end());
        return size;
    }
};
