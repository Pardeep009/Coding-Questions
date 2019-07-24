#include<iostream>
using namespace std;

int main() {
	//code
	int t,n,m,m1,i;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int a[n];
	    for(i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    cin>>m;
	    m1=m;
	    for(i=0;i<n&&m1;i++)
	    {
	        if(a[i] == 0)
	        {
	            m1--;
	        }
	    }
	    if(i==n)
	    {
	        cout<<n<<endl;
	        continue;
	    }
	    int start = 0;
	    int curr = i;
	    int max = -1;
	    while(curr<n)
	    {
	        if(a[curr] == 0)
	        {
	            max = max > (curr-start) ? max : (curr-start);
	            for(;a[start]!=0;start++){}
	            start++;
	        }
	        else if(curr == n-1)
	        {
	            max = max > (curr-start+1) ? max : (curr-start+1);
	        }
	        curr++;
	    }
	    cout<<max<<endl;
	   // max = max > curr-start ? max : curr-start;
	}   
	return 0;
}
