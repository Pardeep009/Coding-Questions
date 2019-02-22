#include<iostream>
using namespace std;
void f(int a[],int i,int j)
{
	static int c=-1;
	if(a[j]==-1)
	{
		c=i;
		return;
	}
	else if(a[j+1]==-1)
	{
		c=i+1;
		return;
	}
	else
	{
		f(a,i+1,j+2);
		a[i]=a[i]+a[c];
		a[c]=a[i];
		c++;
	}
}
int main()
{
	int n,i,j=0;
	int a[100];
	cin>>i;
	while(i!=-1)
	{
		a[j++]=i;
		cin>>i;
	}
	a[j]=-1;
	f(a,0,0);
	for(i=0;i<=j;i++)
	{
		cout<<a[i]<<" ";
	}
}
