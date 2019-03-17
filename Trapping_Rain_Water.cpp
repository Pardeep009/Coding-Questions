/*

https://practice.geeksforgeeks.org/problems/trapping-rain-water/

Given an array arr[] of N non-negative integers representing height of blocks at index i as Ai where the width 
of each block is 1. Compute how much water can be trapped in between blocks after raining.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases 
follows. Each test case contains an integer N denoting the size of the array, followed by N space separated 
numbers to be stored in array.

Output:
Output the total unit of water trapped in between the blocks

Input:
2
4
7 4 0 9
3
6 9 9

Output:
10
0

Explanation:
Testcase 1: Water trapped by block of height 4 is 3 units, block of height 0 is 7 units. So, total unit of
 water trapped is 10 units.

*/
#include<iostream>
using namespace std; 
int main()
{
    int j,n,i,k,max=-1,t;
    int water=0;
    cin>>t;
    while(t--)
    {
        cin>>n;
        max=-1;
        water=0;
        int a[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            if(max<a[i])
            {
                max=a[i];
                k=i;
            }
        }
        j=0;
        for(i=1;i<k;i++)
        {
            if(a[i]<a[j])
            {
                water+=a[j]-a[i];
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
                water+=a[j]-a[i];
            }
            else
            {
                j=i;
            }
        }
        cout<<water<<endl;
    }
    
}