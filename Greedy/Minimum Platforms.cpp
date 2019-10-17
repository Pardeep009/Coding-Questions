/*

  Given arrival and departure times of all trains that reach a railway station. 
  Your task is to find the minimum number of platforms required for the railway station so that no train waits.
  
  Example:
  Input:
  2
  6 
  0900  0940 0950  1100 1500 1800
  0910 1200 1120 1130 1900 2000
  3
  0900 1100 1235
  1000 1200 1240 

  Output:
  3
  1

  Explanation:
  Testcase 1: Minimum 3 platforms are required to safely arrive and depart all trains.
  
*/
/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		//code
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		int n;
		int i,j;
		while(t!=0)
		{
		    t--;
		    n = sc.nextInt();
		    int arr[] = new int[n];
		    int dept[] = new int[n];
		    for(i=0;i<n;i++)
		    {
		        arr[i] = sc.nextInt();
		    }
		    for(i=0;i<n;i++)
		    {
		        dept[i] = sc.nextInt();
		    }
		    Arrays.sort(arr);
		    Arrays.sort(dept);
		    int trains = 0;
		    int max_trains = 0;
		    j=0;
		    i=0;
		    while(i<n)
		    {
		        if(arr[i]<=dept[j])
		        {
		            trains++;
		            max_trains = Math.max(max_trains,trains);
		          //  System.out.print(arr[i] + " ");
		            i++;
		        }
		        else
		        {
		            trains--;
		            j++;
		        }
		    }
		    System.out.println(max_trains);
		}
	}
}
