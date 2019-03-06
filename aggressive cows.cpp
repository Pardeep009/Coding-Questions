// problem statement->   https://www.spoj.com/problems/AGGRCOW/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,cows,k;
	int t;
	cin>>t;                 // test cases
	while(t--)
	{
		cin>>n;            // number of stalls
		cin>>cows;         // number of cows
		vector<int> v(n);
		for(i=0;i<n;i++)
		{
			cin>>k;        // position of stalls
			v[i]=k;
		}
		sort(v.begin(),v.end());
		int l=0;
		int r=2*v[n-1]-2;
		int mid,c,max=v[1]-v[0];
		vector<int>::iterator ub;
		while(l<=r)
		{
			mid=(l+r)/2;
			ub=v.begin();
			c=cows-1;
			while(c)
			{
				int value=mid+v[ub-v.begin()];
				ub=lower_bound(v.begin(),v.end(),value);
				if(ub-v.begin()<n)
				c--;
				else
				break;
			}
			if(c==0)
			{
				max=max>mid?max:mid;
				l=mid+1;
			}
			else
			{
				r=mid-1;
			}
		}
		cout<<max<<endl;      // the largest minimum distance 
		v.clear();
	}
}