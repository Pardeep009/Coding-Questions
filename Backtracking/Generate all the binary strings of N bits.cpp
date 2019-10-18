/*  
  Given a positive integer number N. The task is to generate all the binary strings of N bits. 
  These binary strings should be in ascending order.
  
  Example:
  Input: 2
  Output:
  0 0
  0 1
  1 0
  1 1
  
*/
#include <bits/stdc++.h> 
using namespace std; 
  
// Function to generate all binary strings 
void generateBinaryStrings(int n, string s, int i) 
{ 
    if (i == n) { 
        cout<<s<<endl; 
        return; 
    } 
 
    s[i] = 0; 
    generateBinaryStrings(n, s, i + 1); 
  
    s[i] = 1; 
    generateBinaryStrings(n, s, i + 1); 
} 
  
int main() 
{ 
    int n; 
    cin>>n;
    string s(n); 
  
    generateBinaryStrings(n, arr, 0); 
  
    return 0; 
} 
