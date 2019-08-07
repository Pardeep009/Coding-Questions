#include<bits/stdc++.h>
using namespace std;
int findpivot(int arr[],int length)
{
    int l=0,r=length-1;
    int mid;
    int ans;
    while(l<r)
    {
        mid = (l+r)/2;
        if(arr[mid]>arr[mid+1])
        {
            return mid;
        }
        else
        {
            if(arr[mid]>=arr[r])
            {
                l=mid+1;
            }
            else
            {
                r=mid;
            }
        }
        
    }
    return l;
}
int main()
{
    int arr[]={700,700,7,96};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"pivot is at index "<<findpivot(arr,size);
}
