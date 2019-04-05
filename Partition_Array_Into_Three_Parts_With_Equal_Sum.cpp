/*
https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/
Problem: Partition Array Into Three Parts With Equal Sum
Given an array A of integers, return true if and only if we can partition the array into three non-empty parts with equal sums.

Formally, we can partition the array if we can find indexes i+1 < j with
(A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1] + ... + A[A.length - 1])

Example 1:
Input: [0,2,1,-6,6,-7,9,1,2,0,1]
Output: true
Explanation: 0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1

Example 2:
Input: [0,2,1,-6,6,7,9,-1,2,0,1]
Output: false

Example 3:
Input: [3,3,6,5,-2,2,5,1,-9,4]
Output: true
Explanation: 3 + 3 = 6 = 5 - 2 + 2 + 5 + 1 - 9 + 4
*/
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& v)
    {
        int sum = accumulate(v.begin(), v.end(), 0);
        if(sum %3 != 0)
            return false;
        int val = sum/3;
        int c=0,i,size=v.size();
        for(i=0; i<size; i++)
        {
            c+=v[i];
            if(c==val)
            {
                c=0;
            }
        }
        return (c==0);
    }
};
/*
Unoredered Map solution
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& v) 
    {
        unordered_map<int,int> um;
        unordered_map<int,int>::iterator it;
        int size=v.size(),sum=0,i;
        for(i=0;i<size;i++)
        {
            sum+=v[i];
            um[sum]=i;
        }
        sum=0;
        for(i=0;i<size;i++)
        {
            sum+=v[i];
            it=um.find(sum*2);
            if(it!=um.end()&&it->second>i)
            {
                it=um.find(sum*3);
                if(it!=um.end()&&it->second==size-1)
                    return true;
            }
        }
        return false;
    }
};
*/
