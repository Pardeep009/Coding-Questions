/*
  Given an array of integers where each element represents the max number of steps that can be made forward from that element.
  The task is to find the minimum number of jumps to reach the end of the array (starting from the first element).
  If an element is 0, then cannot move through that element.
  
  Example:
  Input:
  2
  11
  1 3 5 8 9 2 6 7 6 8 9
  6
  1 4 3 2 6 7
  Output:
  3
  2

  Explanation:
  Testcase 1: First jump from 1st element, and we jump to 2nd element with value 3. Now, from here we jump to 5h element 
  with value 9. and from here we will jump to last.
*/
#include <iostream>
using namespace std;

int main() {
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int *a = new int[n];
	    int *b = new int[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    a[n-1]=0;
	    for(int i=n-2;i>=0;i--)
	    {
	        if(a[i]==0)           // if current element is zero,means no chance of reaching end from that element.
	        {
	            a[i] = INT_MAX;
	        }
	        else if(a[i]>=n-i-1)            // if a elements is greater than steps needed to move to last elmenet,then no of jumps from that element to reach end will be 1
	        {
	            a[i] = 1;
	        }
	        else          // find minimum jumps from the elements which are visitible from this element.
	        {
	            int mins = a[i+1];
	            for(int j=i+2;j<=i+a[i];j++)
	            {
	                mins = min(mins,a[j]);
	            }
	            if(mins==INT_MAX)
	            a[i] = INT_MAX;
	            else
	            a[i] = mins+1;
	        }
	    }
	    if(a[0]==INT_MAX)            // not able to reach end
	    cout<<"-1"<<endl;          
	    else
	    cout<<a[0]<<endl;          // minimum jumps needed
	}
	return 0;
}
