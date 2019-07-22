/*You are required to complete this method*/
int maxLen(int arr[], int n)
{
//Your code here
    if(n==1)
    return 0;
    
    unordered_map<int,int> map;
    
    int *leftsum = new int[n];
    for(int i=0;i<n;i++)
    {
        if(!arr[i])
        arr[i] = -1;
    }
    leftsum[0] = arr[0];
    for(int i=1;i<n;i++)
    {
        leftsum[i] = leftsum[i-1] + arr[i];
    }
    int max = 0;
    for(int i=0;i<n;i++)
    {
        if(leftsum[i] == 0)
        {
            max = max > i+1 ? max : i+1;
        }
        else if(map.find(leftsum[i])==map.end())
        {
            map[leftsum[i]] = i;
        }
        else
        {
            max = max > ( i- map[leftsum[i]]) ? max : (i - map[leftsum[i]]) ;
        }
    }
    return max;
}
