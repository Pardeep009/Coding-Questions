/*

*/
// C++ program for cutting rods(profit) problem. 
#include<bits/stdc++.h> 

using namespace std; 

int maxprofit( int S[],int n )
{ 
	int i, j; 

	// We need n+1 rows as the table 
	// is constructed in bottom up 
	// manner using the base case 0 
	// value case (n = 0) 
	int table[100][100]={0};
	memset(table,0,sizeof(table));
	
	// Fill the enteries for 0 
	// value case (n = 0) 
	for (i=1;i<=n;i++) 
		table[i][0] = S[i-1]; 

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

// Driver Code 
int main() 
{ 
	int arr[] = {1,5,8,9,10,17,17,20}; 
// 	int m = sizeof(arr)/sizeof(arr[0]); 
	int n = 8; 
	cout << maxprofit(arr,n);
	return 0; 
} 
