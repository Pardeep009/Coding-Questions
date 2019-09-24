/*

   Given a set of numbers, check whether it can be partitioned into two subsets such that the sum of elements
   in both subsets is same or not.
   
	Example:
	Input:
	2
	4
	1 5 11 5
	3
	1 3 5 

	Output:
	YES
	NO

	Explanation:
	Testcase 1: There exists two subsets such that {1, 5, 5} and {11}.
  Testcase 2: No combinatioin is possible.
*/

#include <bits/stdc++.h>
using namespace std;

bool count( int S[], int m, int n )
{ 
	int i, j; 
	
	bool table[n + 1][m]; 
	
	for (i = 0; i < m; i++) 
		table[0][i] = true; 

	// Fill rest of the table entries 
	// in bottom up manner 
	bool x,y;
	for (i = 1; i < n + 1; i++) 
	{ 
		for (j = 0; j < m; j++) 
		{ 
			// solution possible by including S[j] 
			x = (i-S[j] >= 0 && j>=1) ? table[i - S[j]][j-1] : false; 

			// solution possible by excluding S[j] 
			y = (j >= 1) ? table[i][j - 1] : false; 

			// total count 
			table[i][j] = x == true ? true : y; 
		} 
	} 
	return table[n][m - 1]; 
} 

int main() {
	//code
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int a[n];
	    int sum = 0;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	        sum+=a[i];
	    }
	    if(sum%2)
	    {
	        cout<<"NO"<<endl;
	        continue;
	    }
	    sort(a,a+n);
	    if(count(a,n,sum/2))
	    cout<<"YES"<<endl;
	    else
	    cout<<"NO"<<endl;
	}
	return 0;
}
