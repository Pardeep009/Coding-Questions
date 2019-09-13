/*
  Given a string A representing a roman numeral.
  Convert A into integer.

  A is guaranteed to be within the range from 1 to 3999.

  NOTE: Read more
  details about roman numerals at Roman Numeric System



  Input Format

  The only argument given is string A.
  Output Format

  Return an integer which is the integer verison of roman numeral string.
  For Example

  Input 1:
      A = "XIV"
  Output 1:
      14

  Input 2:
      A = "XX"
  Output 2:
      20
*/
int Solution::romanToInt(string A) {
    int num=0;
    int i=0;
    while(i<A.length())
    {
        if(A[i]=='I')
        {
            num+=1;
        }
        else if(A[i]=='V')
        {
            if(i>0&&A[i-1]=='I')
            {
                num+=3;
            }
            else {
                num+=5;
            }
        }
        else if(A[i]=='X')
        {
            if(i>0&&A[i-1]=='I')
            {
                num+=8;
            }
            else {
                num+=10;
            }
        }
        else if(A[i]=='L')
        {
            if(i>0&&A[i-1]=='X')
            {
                num+=30;
            }
            else {
                num+=50;
            }
        }
        else if(A[i]=='C')
        {
            if(i>0&&A[i-1]=='X')
            {
                num+=80;
            }
            else {
                num+=100;
            }
        }
        else if(A[i]=='D')
        {
            if(i>0&&A[i-1]=='C')
            {
                num+=300;
            }
            else {
                num+=500;
            }
        }
        else if(A[i]=='M')
        {
            if(i>0&&A[i-1]=='C')
            {
                num+=800;
            }
            else {
                num+=1000;
            }
        }
        i++;
    }
    return num;
}
