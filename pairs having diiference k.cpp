/*
You will be given an array of integers and a target value. Determine the number of pairs of array elements that have a difference equal
to a target value.

Function Description

Complete the pairs function below. It must return an integer representing the number of element pairs having the required difference.

pairs has the following parameter(s):

k: an integer, the target difference
arr: an array of integers

For example, given an array of [1, 2, 3, 4] and a target value of 1, we have three values meeting the condition: 2-1=1 , 3-2=1 , and 4-3=1.

Sample Input
5 2  
1 5 3 4 2  

Sample Output
3

Explanation
There are 3 pairs of integers in the set with a difference of 2: [5,3], [4,2] and [3,1].
*/
int pairs(int k, vector<int> v) 
{
    sort(v.begin(),v.end());
    int c=0,find,l,r,mid,i=0,size=v.size();
    while(i<size)
    {
        find=k+v[i];
        l=i+1;
        r=size-1;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(v[mid]==find)
            {
                c++;
                break;
            }
            else if(v[mid]>find)
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        i++;
    }
    return c;
}
