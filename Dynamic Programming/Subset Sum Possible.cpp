// C++ program for coin change problem. 
#include<bits/stdc++.h> 

using namespace std; 

bool count( int S[], int m, int n )
{ 
	int i, j; 
  
	bool table[n + 1][m]; 
	
	// Fill the enteries for 0 
	// value case (n = 0) 
	for (i = 0; i < m; i++) 
		table[0][i] = true; 

	// Fill rest of the table entries 
	// in bottom up manner 
	bool x,y;
	for (i = 1; i < n + 1; i++) 
	{ 
		for (j = 0; j < m; j++) 
		{ 
			// Count of solutions including S[j] 
			x = (i-S[j] >= 0 && j>=1) ? table[i - S[j]][j-1] : false; 

			// Count of solutions excluding S[j] 
			y = (j >= 1) ? table[i][j - 1] : false; 

			// total count 
			table[i][j] = x == true ? true : y; 
		} 
	} 
	return table[n][m - 1]; 
} 

// Driver Code 
int main() 
{ 
	int arr[] = {1,2,3,9}; 
	int m = sizeof(arr)/sizeof(arr[0]); 
	int n = 5; 
	cout << count(arr, m, n);
	return 0; 
}  
