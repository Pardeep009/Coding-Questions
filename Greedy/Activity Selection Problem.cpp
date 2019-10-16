/*
  
  You are given n activities with their start and finish times.
  Select the maximum number of activities that can be performed by a single person,
  assuming that a person can only work on a single activity at a time.
  
  Example:
  Example 1 : Consider the following 3 activities sorted by
  by finish time.
       start[]  =  {10, 12, 20};
       finish[] =  {20, 25, 30};
  A person can perform at most two activities. The 
  maximum set of activities that can be executed 
  is {0, 2} [ These are indexes in start[] and 
  finish[] ]

  Example 2 : Consider the following 6 activities 
  sorted by by finish time.
       start[]  =  {1, 3, 0, 5, 8, 5};
       finish[] =  {2, 4, 6, 7, 9, 9};
  A person can perform at most four activities. The 
  maximum set of activities that can be executed 
  is {0, 1, 3, 4} [ These are indexes in start[] and 
  finish[] ]
  
*/
#include <bits/stdc++.h> 
using namespace std; 

struct Activitiy 
{ 
    int start, finish; 
}; 
  
bool comparator(Activitiy s1, Activitiy s2) 
{ 
    return (s1.finish < s2.finish); 
} 

void MaxActivities(Activitiy arr[], int n) 
{ 
    sort(arr, arr+n, comparator);
    
    int c=1;
    int i = 0;  
    
    for (int j = 1; j < n; j++) 
    { 
      if (arr[j].start >= arr[i].finish) 
      { 
          c++;
          i = j; 
      } 
    } 
    
    cout<<c << " Activities are selected"<<endl;
} 
  
int main() 
{ 
    Activitiy arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, 
                                       {5, 7}, {8, 9}}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    MaxActivities(arr, n); 
    return 0; 
} 
