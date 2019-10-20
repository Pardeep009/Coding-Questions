/*
  Given a string A representating json object. Return an array of string denoting json object with proper indentaion.

  Rules for proper indentaion:
  Every inner brace should increase one indentation to the following lines.
  Every close brace should decrease one indentation to the same line and the following lines.
  The indents can be increased with an additional ‘\t’
  
  Note: 
  [] and {} are only acceptable braces in this case.
  
  Input Format
  The only argument given is the integer array A.
  
  Output Format
  Return a list of strings, where each entry corresponds to a single line. 
  The strings should not have "\n" character in them.
  
  For Example
  Input 1:
      A = "{A:"B",C:{D:"E",F:{G:"H",I:"J"}}}"
  Output 1:
      { 
          A:"B",
          C: 
          { 
              D:"E",
              F: 
              { 
                  G:"H",
                  I:"J"
              } 
          } 
      }

  Input 2:
      A = ["foo", {"bar":["baz",null,1.0,2]}]
  Output 2:
     [
          "foo", 
          {
              "bar":
              [
                  "baz", 
                  null, 
                  1.0, 
                  2
              ]
          }
      ]
      
*/
  vector<string> Solution::prettyJSON(string A) {
    vector<string> res;
    int size = A.size();
    int i=1;
    string s(1,A[0]);
    res.push_back(s);
    string v="";
    string ind="\t";
    v = ind;
    while(i<size)
    {
        if(A[i] == ']' || A[i] == '}')
        {
            if(A[i-1]!=']' && A[i-1]!='}')
            {
                res.push_back(v);   
            }
            ind = ind.substr(0,ind.length()-1);
            v = ind + A[i];
            if(A[i+1] == ',')
            {
                v = v + ',';
                i++;
            }
            res.push_back(v);
            v = ind;
        }
        else if(A[i] == '{' || A[i] == '[')
        {
            if(A[i-1]!=',' && A[i-1]!='{' && A[i-1]!= '[')
            {
                res.push_back(v);
            }
            v = ind + A[i];
            res.push_back(v);
            ind = ind + "\t";
            v = ind;
        }
        else if(A[i] == ',')
        {
            v = v + A[i];
            res.push_back(v);
            v = ind;
        }
        else
        {
            v = v + A[i];
        }
        i++;
    }
    return res;
}
