/*
  Given an integer N denoting the Length of a line segment. you need to cut the line segment in such a way that the cut
  length of a line segment each time is integer either x , y or z. and after performing all cutting operation the total 
  number of cutted segments must be maximum. 
  
  Example
  Input

  2
  4
  2 1 1
  5
  5 3 2


  Output
  4
  2

  In first test case, total length is 4, and cut lengths are 2, 1 and 1.  We can make maximum 4 segments each of length 1.
  In secon test case, we can make two segments of lengths 3 and 2.
*/
#include <bits/stdc++.h>
using namespace std;

int maxCuttedSegments(int b[],int n)
{
    int a[n+1][3];
    memset(a,0,sizeof(a));
    int x,y;
    for(int i=1;i<=n;i++)
    {
        if(i<b[0])                       // if length is less than min of avialable piece length,then no segment is possible
        continue;
        for(int j=0;j<3;j++)
        {
            x=0;
            if(i-b[j]>=0)                
            {
                if(i-b[j]==0)
                {
                    x = 1;
                }
                else if(a[i-b[j]][j])
                {
                    x = 1 + a[i-b[j]][j];
                }
            }
            y = j>=1 ? a[i][j-1] : 0;
            a[i][j] = max(x,y);
        }
    }
    return a[n][2];
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int b[3];
	    cin>>b[0]>>b[1]>>b[2];
	    sort(b,b+3);
	    cout<<maxCuttedSegments(b,n)<<endl;
	}
	return 0;
}
