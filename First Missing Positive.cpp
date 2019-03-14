/*
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
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        vector<int>::iterator it;
        int i;
        for(i=1;;i++)
        {
            it=find(nums.begin(),nums.end(),i);
            if(it==nums.end())
            return i;
        }
    }
};