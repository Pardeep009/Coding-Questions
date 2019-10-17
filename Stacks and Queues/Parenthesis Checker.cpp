/*

  Given an expression string exp. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
  For example, the program should print 'balanced' for exp = “[()]{}{[()()]()}” and 'not balanced' for exp = “[(])”
  
  Example:
  Input:
  3
  {([])}
  ()
  ([]

  Output:
  balanced
  balanced
  not balanced
  
*/

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		//code
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		String query;
		int f;
		while(t!=0)
		{
		    t--;
		    query = sc.next();
		    Stack<Character> stk = new Stack<Character>();
		    int i=0;
		    int len = query.length();
		    f=0;
		    while(i<len)
		    {
		        if(query.charAt(i) == '{' || query.charAt(i) == '[' || query.charAt(i) == '(' )
		        {
		            stk.push(query.charAt(i));
		        }
		        else
		        {
		            if(stk.size()!=0 && ((query.charAt(i) == '}' && stk.peek() == '{') || (query.charAt(i) == ')' && stk.peek() == '(') || (query.charAt(i) == ']' && stk.peek() == '[') ))
		            {
		                stk.pop();
		            }
		            else
		            {
		                f=1;
		                break;
		            }
		        }
		        i++;
		    }
		    if(f==1 || stk.size()!=0)
		    {
		         System.out.println("not balanced");
		    }
		    else
		    {
		        System.out.println("balanced");
		    }
		}
	}
}
