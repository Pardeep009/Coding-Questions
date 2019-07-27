/*
    Problem -> https://www.interviewbit.com/problems/distinct-numbers-in-window/
    A=[1, 2, 1, 3, 4, 3] and K = 3

    All windows of size K are

    [1, 2, 1]
    [2, 1, 3]
    [1, 3, 4]
    [3, 4, 3]

    So, we return an array [2, 3, 3, 2].

*/
vector<int> Solution::dNums(vector<int> &arr, int k) {
    unordered_map<int,int> map;              // hash variable to store frequency of each value
    int i,c=0,size = arr.size();
    vector<int> ans;
    for(i=0;i<k && i<size;i++)                // making first window of size k
    {
        if(map.find(arr[i]) == map.end())         // checking if the a[i] occured first time
        {
            c++;                             // if yes,increase unique count
            map[arr[i]] = 1;                 // store it in hashmap
        }
        else
        {
            map[arr[i]]++;                 // if already present increase its frequency
        }
    }
    int start = 0;                     // window starting index
    ans.push_back(c);                    // first window answer pushing in vector
    for(;i<size;i++)                      //  i works as window ending index
    {
        map[arr[start]]--;                  // decrease frequency of arr[start] in hashmap 
        if(!map[arr[start]])                // if its frequency becomes zero,decease unique count
        {
            c--;
        }
        if(map.find(arr[i]) == map.end())       // if a[i] occurrs first time
        {
            c++;                               // increase unique count
            map[arr[i]] = 1;                    // store element in hashmap
        }
        else                                 // if a[i] already present
        {
            map[arr[i]]++;                    // increase frquency count of arr[i]
            if(map[arr[i]]==1)                // if its frquency becomes 1,means it was removed from window by start variable and is added by i variable again
            c++;                               // then increase unique count
        }
        ans.push_back(c);                   // current window answer pushing in vector
        start++;                            // shift start vaiable to point to next window start
    }
    return ans;                      
}
