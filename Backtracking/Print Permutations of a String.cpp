/*

  Given a string S. Print all permutations of a given string.
  
*/

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
    public static void swapChars(StringBuilder str,int i,int j)
    {
        char ch;
        ch = str.charAt(i);
        str.setCharAt(i,str.charAt(j));
        str.setCharAt(j,ch);
        
    }
    static void printCombinations(StringBuilder str,int start,int end)
    {
        if(start==end)
        {
            System.out.print(str + " ");
            return;
        }
        int i;
        for(i=start;i<end;i++)
        {
            swapChars(str,start,i);
            printCombinations(str,start+1,end);
            swapChars(str,start,i);
        }
        
    }
    
	public static void main (String[] args) {
		//code
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t!=0)
		{
		    t--;
		    String s = sc.next();
		    StringBuilder str = new StringBuilder(s);
		    printCombinations(str,0,str.length());
		    System.out.println();
		}
	}
}
