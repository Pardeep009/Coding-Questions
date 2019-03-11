/*
question link-> https://leetcode.com/problems/rotate-array/

Given an array, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: [-1,-100,3,99] and k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
*/
class Solution 
{
public:
    void rotate(vector<int>& arr, int k) 
    {
        int size=arr.size();
        if(k==0||size==k||k%size==0)
            return;
        if(k>size)
        {
            k=k%size;
        }
        int i,j;
        i=size-k;
        int a[k];
        j=0;
        while(i<size)
        {
            a[j++]=arr[i++];    // copy last k elements in an auxillary array
        }
        i=size-k-1;
        j=size-1;
        while(i>=0)
        {
            arr[j--]=arr[i--];     // copy left size-k elemnts to right of array
        }
        i=0;
        while(i<k)
        {
            arr[i]=a[i];      // copy auxilarry array elements into original array 
            i++;
        }
    }
};