/*
Given a MxN matrix where each element can either be 0 or 1. 
We need to find the shortest path between a given source cell 
to a destination cell. The path can only be created out of a cell 
if its value is 1.
*/
#include<iostream>
using namespace std;
int c=INT_MAX;
int min(int **a,int m,int n,int i,int j,int e,int e1,int steps)
{
	if(i==-1||j==-1||i==m||j==n)
	{
		return -1;
	}
	else if(a[i][j]==0)
	{
		return -1;
	}
	else if(i==e&&j==e1)
	{
		c=c>steps?steps:c;
	}
	else
	{
		a[i][j]=0;
		min(a,m,n,i+1,j,e,e1,steps+1);
		min(a,m,n,i-1,j,e,e1,steps+1);
		min(a,m,n,i,j-1,e,e1,steps+1);
		min(a,m,n,i,j+1,e,e1,steps+1);
		a[i][j]=1;
	}
	return c;
}
int main()
{
	int j,m,n,i,s,s1,e,e1;
	cin>>m>>n;                     // enter size of 2d matrix
	int **a;
	a=new int*[m];
	for(i=0;i<m;i++)
	{
		a[i]=new int[n];
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>a[i][j];          // enter elements of 2d array
		}
	}
	cin>>s>>s1>>e>>e1;             // enter starting point and ending pointing point
	cout<<min(a,m,n,s,s1,e,e1,0);  // min steps required to reach ending point from given starting point
}
