#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int max_cost=INT_MIN;
int find(int a[],int l,int b[])
{
    if(l==0)
    return 0;
    if(b[l])
        return b[l];
    int max_cost=INT_MIN;
        int i;
        for(i=1;i<=l;i++)
            max_cost=max(a[i]+find(a,l-i,b),max_cost);
	b[l]=max_cost;
    return max_cost;
}
int main() 
{
    int n;
    cin>>n;       // enter the length of rod
    int a[n+1];
    int *b=new int[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];       // cost of cutting of rod for each length
    }
    cout<<find(a,n,b);       // max profit
	return 0;
}
