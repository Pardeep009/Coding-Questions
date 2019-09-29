#include <bits/stdc++.h>
using namespace std;
int maxprofit( int S[],int n )
{ 
	int i, j; 

	// We need n+1 rows as the table 
	// is constructed in bottom up 
	// manner using the base case 0 
	// value case (n = 0) 
	int table[n+1][n+1]={0};
	memset(table,0,sizeof(table));
	
	// Fill the enteries for 0 
	// value case (n = 0) 
	for (i=1;i<=n;i++) 
		table[i][0] = S[i]; 

	// Fill rest of the table entries 
	// in bottom up manner 
	int x,y;
	for (i = 1; i <= n; i++) 
	{ 
		for (j = 1; j <= n; j++) 
		{ 
		    if(j>i)
		    {
		        table[i][j] = table[i][j-1];
		    }
		    else
		    {
		        // maximum price by cutting in length S[j] 
    			x = table[j][j] + table[i-j][j]; 
    
    			// maximum price by not cutting in length S[j] 
    			y = table[i][j - 1];
    
    			// total count 
    			table[i][j] = max(x,y);   
		    }
		} 
	} 
	return table[n][n]; 
}
int main() {
	//code
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int price[n+1];
	    for(int i=1;i<=n;i++)
	    cin>>price[i];
	    cout<<maxprofit(price,n)<<endl;
	}
	return 0;
}
