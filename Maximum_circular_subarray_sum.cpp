#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int kadane(int a[], int n) 
{ 
    int max_so_far = 0, max_ending_here = 0; 
    int i; 
    for (i = 0; i < n; i++) 
    { 
        max_ending_here = max_ending_here + a[i]; 
        if (max_ending_here < 0) 
            max_ending_here = 0; 
        if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here; 
    } 
    return max_so_far; 
} 
int main() {
	//code
	int i,t,n,*a,back_sum,back_max,still_max,sum,max,f;
	cin>>t;
	while(t--)
	{
	    f=0;
	    max=INT_MIN;
	    back_sum=0;
	    back_max=INT_MIN;
	    still_max=INT_MIN;
	    sum=0;
	    cin>>n;
	    a=new int[n];
	    for(i=0;i<n;i++)
	    {
	        cin>>a[i];
	        sum+=a[i];
	        max=max>a[i]?max:a[i];
	        if(a[i]>=0&&f==0)
	        {
	            f=1;
	        }
	    }
	    if(f==0)          // if all elments are negative 
	    {
	        cout<<max<<endl;
	        continue;
	    }
        still_max=kadane(a,n);
	    for(i=0;i<n;i++)
	    {
	        back_sum+=a[i];
	        back_max=back_max>back_sum?back_max:back_sum;
	        sum=sum-a[i];
	        if(sum+back_max>still_max)
	        {
	           still_max=sum+back_max;
	        }
	    
	    }
	    cout<<still_max<<endl;
	    delete[] a;
	}
	return 0;
}
