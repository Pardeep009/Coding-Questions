/*

  Write a program to find the node at which the intersection of two singly linked lists begins.
  For example, the following two linked lists:


  A:          a1 → a2
                     ↘
                       c1 → c2 → c3
                     ↗
  B:     b1 → b2 → b3

  begin to intersect at node c1.

  Notes:
  If the two linked lists have no intersection at all, return null.
  The linked lists must retain their original structure after the function returns.
  You may assume there are no cycles anywhere in the entire linked structure.
  Your code should preferably run in O(n) time and use only O(1) memory.
  
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    ListNode *temp = A;
    int l1=0;
    while(temp)
    {
        l1++;
        temp = temp->next;
    }
    temp = B;
    int l2=0;
    while(temp)
    {
        l2++;
        temp = temp->next;
    }
    ListNode *temp1=A;
    while(l1>l2)
    {
        temp1 = temp1->next;
        l1--;
    }
    ListNode *temp2=B;
    while(l2>l1)
    {
        temp2 = temp2->next;
        l2--;
    }
    while(temp1 && temp2)
    {
        if(temp1 == temp2)
        {
            return temp1;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return NULL;
}
