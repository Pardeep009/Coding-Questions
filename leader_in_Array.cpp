/*
https://practice.geeksforgeeks.org/problems/leaders-in-an-array/

Given an array of positive integers. Your task is to find the leaders in the array.
Note: An element of array is leader if it is greater than or equal to all the elements to its right side.
 Also, the rightmost element is always a leader. 

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases
 follows.
The first line of each test case contains a single integer N denoting the size of array.
The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
Print all the leaders.

Example:
Input:
3
6
16 17 4 3 5 2
5
1 2 3 4 0
5
7 4 5 7 3
Output:
17 5 2
4 0
7 7 3

Explanation:
Testcase 3: All elements on the right of 7 (at index 0) are smaller than or equal to 7. Also, all the elements 
of right side of 7 (at index 3) are smaller than 7. And, the last element 3 is itself a leader since no elements
 are on its right.

*/
using namespace std;
int main() {
	//code
	int t,n,i,j,k;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    k=-1;
	    int a[n],b[n];
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    for(i=0;i<n;i++)
	    {
	        for(j=i+1;j<n;j++)
	        if(a[j]>a[i])
	        break;
	        if(j==n)
	        {
	            for(j=0;j<=k;j++)
	            if(b[j]==a[i])
	            break;
	            if(j>k)
	            b[++k]=a[i];
	        }
	    }
	    for(i=0;i<=k;i++)
	    cout<<b[i]<<" ";
	    cout<<endl;
	}
	return 0;
}