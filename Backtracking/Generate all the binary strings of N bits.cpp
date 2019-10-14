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
void generateAllBinaryStrings(int n, string s, int i) 
{ 
    if (i == n) { 
        cout<<s<<endl; 
        return; 
    } 
  
    // First assign "0" at ith position 
    // and try for all other permutations 
    // for remaining positions 
    s[i] = 0; 
    generateAllBinaryStrings(n, s, i + 1); 
  
    // And then assign "1" at ith position 
    // and try for all other permutations 
    // for remaining positions 
    s[i] = 1; 
    generateAllBinaryStrings(n, s, i + 1); 
} 
  
int main() 
{ 
    int n; 
    cin>>n;
    string s(n); 
  
    // Print all binary strings 
    generateAllBinaryStrings(n, arr, 0); 
  
    return 0; 
} 
