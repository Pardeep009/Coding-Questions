/*
N number of books are given. 
The ith book has Pi number of pages. 
You have to allocate books to M number of students so that maximum number of pages alloted to a student is minimum. A book will be allocated to exactly one student. Each student has to be allocated at least one book. Allotment should be in contiguous order, for example: A student cannot be allocated book 1 and book 3, skipping book 2.

NOTE: Return -1 if a valid assignment is not possible

Input:

List of Books
M number of students
Your function should return an integer corresponding to the minimum number.

Example:

P : [12, 34, 67, 90]
M : 2

Output : 113

There are 2 number of students. Books can be distributed in following fashion : 
  1) [12] and [34, 67, 90]
      Max number of pages is allocated to student 2 with 34 + 67 + 90 = 191 pages
  2) [12, 34] and [67, 90]
      Max number of pages is allocated to student 2 with 67 + 90 = 157 pages 
  3) [12, 34, 67] and [90]
      Max number of pages is allocated to student 1 with 12 + 34 + 67 = 113 pages

Of the 3 cases, Option 3 has the minimum pages = 113. 
*/
#include<bits/stdc++.h>
bool check(vector<int> v,int mid,int m)
{
    int c=1,l=v.size(),sum=mid,i;
    for(i=0;i<l;)
    {
        if(sum-v[i]<0)
        {
            c++;
            sum=mid;
            if(c>m)
            {
                return false;
            }
        }
        else
        {
            sum-=v[i];
            i++;
        }
    }
    return true;
}
int Solution::books(vector<int> &v, int m) 
{
    if(m>v.size())
    return -1;
    int mid,r=0,l,ans=-1,i;
    l=v.size();
    for(i=0;i<l;i++)
    {
        r+=v[i];
    }
    l=0;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(check(v,mid,m))
        {
            ans=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return ans;
}
