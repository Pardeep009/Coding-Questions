/*
Given an array A and an integer K. Find the maximum for each and every contiguous subarray of size K.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case contains 
\a single integer N denoting the size of array and the size of subarray K. The second line contains N space-separated 
integers A1, A2, ..., AN denoting the elements of the array.

Output:
Print the maximum for every subarray of size k.

Example:
Input:
2
9 3
1 2 3 1 4 5 2 3 6
10 4
8 5 10 7 9 4 15 12 90 13

Output:
3 3 4 5 5 5 6
10 10 10 15 15 90 90

Explanation:
Testcase 1: Starting from first subarray of size k = 3, we have 3 as maximum. Moving the window forward, maximum element 
are as 3, 4, 5, 5, 5 and 6.
*/
using namespace std;
int main() {
	//code
	int t,n,*a,k,i,max,j,index;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    cin>>k;
	    max=-1;
	    a=new int[n];
	    for(i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    max=a[0];
	    index=0;
	    for(i=1;i<k;i++)
	    {
	        if(a[i]>max)
	        {
	            max=a[i];
	            index=i;
	        }
	    }
	    cout<<max<<" ";
	    for(i=1;i<=n-k;i++)
	    {
	        if(index>=i)
	        {
	            if(a[i+k-1]>max)
	            {
	                max=a[i+k-1];
	                index=i+k-1;
	            }
	            cout<<max<<" ";
	            continue;
	        }
	        max=a[i];
	        index=i;
	        for(j=i+1;j<i+k;j++)
	        {
	            if(a[j]>max)
	            {
	                max=a[j];
	                index=j;
	            }
	        }
	        cout<<max<<" ";
	    }
	    cout<<endl;
	    
	    delete []a;
	}
	return 0;
}