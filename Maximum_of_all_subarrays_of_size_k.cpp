#include <iostream>
using namespace std;

int main() 
{
	int t,n,*a,k,i,j,index;
	cin>>t;          // enter test cases
	while(t--)
	{
	    cin>>n;     // enter number of elements 
	    cin>>k;     //  enter subaaray size
	    a=new int[n];
	    for(i=0;i<n;i++)
	    {
	        cin>>a[i];       // enter elements of array
	    }
	    index=0;
	    for(i=1;i<k;i++)
	    {
	        if(a[i]>a[index])
	        {
	            index=i;
	        }
	    }
	    cout<<a[index]<<" ";
	    for(i=1;i<=n-k;i++)
	    {
	        if(index>=i)
	        {
	            if(a[i+k-1]>a[index])
	            {
	                index=i+k-1;
	            }
	            cout<<a[index]<<" ";
	            continue;
	        }
	        index=i;
	        for(j=i+1;j<i+k;j++)
	        {
	            if(a[j]>a[index])
	            {
	                index=j;
	            }
	        }
	        cout<<a[index]<<" ";     
	    }
	    cout<<endl;
  	    delete []a;
	}
	return 0;
 }
