/*
https://www.interviewbit.com/problems/first-missing-integer/
First Missing Positive

Given an unsorted integer array, find the smallest missing positive integer.

Example 1:
Input: [1,2,0]
Output: 3

Example 2:
Input: [3,4,-1,1]
Output: 2

Example 3:
Input: [7,8,9,11,12]
Output: 1

*/
int Solution::firstMissingPositive(vector<int> &arr) {
    int size = arr.size(),i=0,j=0;
    // if(size == 1)
    // return arr[0] == 1 ? 2 : 1;
    while(i<size)           // shift negative elements to left side and positive elements to right side
    {
        if(arr[i]<=0)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }
        i++;
    }
    if(j==size && arr[j-1]<=0)             // if all are negative elements,then answer is 1
    {
        return 1;
    }
    int index,start=j;                // start is pointing to first positive element in array
    for(;j<size;j++)
    {
        index = abs(arr[j])-1;              // mark index for visited positive values at their respective indexes as in sorted array
        if(index+start<size)
        {
            if(arr[index+start]>0)          // if already marked(duplicate case),no need to mark again
            arr[index+start] *=-1;
        }
    }
    for(j=start;j<size;j++)
    {
        if(arr[j]>0)                  // start from first positive element,check each index,if positive means this index value isn't visited,answer is found
        return j-start+1;
    }
    return j-start+1;
}
