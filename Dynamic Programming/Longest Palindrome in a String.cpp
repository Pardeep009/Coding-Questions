/*
  Given a string S, find the longest palindromic substring in S. 
  Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). 
  Palindrome string: A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S. 
  Incase of conflict, return the substring which occurs first ( with the least starting index ).
  
  Example:
  Input:
  1
  aaaabbaa

  Output:
  aabbaa

  Explanation:
  Testcase 1: The longest palindrome string present in the given string is "aabbaa".
  
*/

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		//code
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t!=0)
		{
		    t--;
		    String s = sc.next();
		    boolean [][]table = new boolean[s.length()][s.length()];
		    
		    int begin = 0;
		    int max_length = 1;
		    
		    for(int i=0;i<s.length();i++)
		    {
		        table[i][i] = true;                   // all one length substring will be palindrome.
		    }
		    
		    int f = 1;
		    
		    for(int i=0;i<s.length()-1;i++)           // finding two length palindrome substring.
		    {
		        if(s.charAt(i)==s.charAt(i+1))
		        {
		            if(f==1)          // to get least starting index substring
		            {
		                begin = i;
		                max_length = 2;
		                f=0;
		            }
		            table[i][i+1] = true;
		        }
		    }
		    
		    
		    
		    for(int curr_length = 3;curr_length<=s.length();curr_length++)
		    {
		        for(int i=0;i<s.length()-curr_length+1;i++)
		        {
		            int j = i + curr_length - 1;
		            if(s.charAt(i)==s.charAt(j) && table[i+1][j-1])         // if current subtring's first and last character are same and substring within that substring is also a palindrome
		            {
		                table[i][j] = true;
		                if(curr_length > max_length)           // to get least starting index substring
		                {
		                    begin = i;
		                    max_length = curr_length;   
		                }
		            }
		        }
		    }
		    System.out.println(s.substring(begin,max_length + begin));
		}
		
	}
}
