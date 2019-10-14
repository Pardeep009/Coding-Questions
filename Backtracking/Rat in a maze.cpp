/*
  Consider a rat placed at (0, 0) in a square matrix m[][] of order n and has to reach the destination at (n-1, n-1). 
  Your task is to complete the function printPath() which returns a sorted array of strings denoting all the possible 
  directions which the rat can take to reach the destination at (n-1, n-1). The directions in which the rat can move 
  are 'U'(up), 'D'(down), 'L' (left), 'R' (right).
  
  Example
  Input:
  2
  4
  1 0 0 0 1 1 0 1 0 1 0 0 0 1 1 1
  4
  1 0 0 0 1 1 0 1 1 1 0 0 0 1 1 1

  Output:
  DRDDRR
  DDRDRR DRDDRR

  Explanation:
  Testcase 2: The given input is in the form
  1 0 0 0
  1 1 0 1
  1 1 0 0
  0 1 1 1
  For the above matrix the rat can reach the destination at (3, 3) from (0, 0) by two paths ie DRDDRR and DDRDRR when 
  printed in sorted order we get DDRDRR DRDDRR.
  
*/

void maze(vector<string> &v,int m[MAX][MAX],int i,int j,int n,int k,char *ch)
{
    if(i==n||j==n||i==-1||j==-1)
    return;
    
    else if(i==n-1 && j==n-1)
    {
        ch[k]='\0';
        string s(ch);
        v.push_back(s);
        return;
    }
    else if(m[i][j]==0 || m[i][j]==-1)
    return;
    
    m[i][j]=-1;
    
    ch[k]='D';
    maze(v,m,i+1,j,n,k+1,ch);
    
    ch[k]='R';
    maze(v,m,i,j+1,n,k+1,ch);
    
    ch[k]='U';
    maze(v,m,i-1,j,n,k+1,ch);
    
    ch[k]='L';
    maze(v,m,i,j-1,n,k+1,ch);
    
    m[i][j]=1;
  
}
vector<string> printPath(int m[MAX][MAX], int n)
{
    vector<string> v;
    char *s = new char[n+n];
    maze(v,m,0,0,n,0,s);
    sort(v.begin(),v.end());
   
    return v;
    //Your code here	
}
