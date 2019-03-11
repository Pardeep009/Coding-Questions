/*
question-link-->https://leetcode.com/problems/container-with-most-water/

Given n non-negative integers a1, a2, ..., an , where each represents a
point at coordinate (i, ai). n vertical lines are drawn such that the 
two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which 
together with x-axis forms a container, such that the container contains
the most water.

Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49

*/
class Solution 
{
public:
    int maxArea(vector<int>& v) 
    {
        int i,j=v.size()-1,small,amount,max=INT_MIN;
        for(i=0;i<j;)
        {
                small=v[i]>v[j]?v[j]:v[i];
                amount=small*(j-i);
                max=max>amount?max:amount;
                if(small==v[i])
                {
                    i++;
                }
                else
                {
                    j--;
                }
        }
        return max;
    }
};