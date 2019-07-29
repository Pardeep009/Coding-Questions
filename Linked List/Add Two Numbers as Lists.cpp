/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {

    ListNode *temp1 = A, *temp2 = B,*new_head = NULL,*temp = NULL,*last = NULL;
    int carry = 0,sum = 0;
    while(temp1&&temp2)
    {
        sum = temp1->val + temp2->val + carry;
        carry = sum/10;
        temp = new ListNode(sum%10);
        if(new_head == NULL)
        {
            last = temp;
            new_head = temp;
        }
        else
        {
            last->next = temp;
            last = temp;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    while(temp1)
    {
        sum = temp1->val + carry;
        carry = sum/10;
        temp = new ListNode(sum%10);
        if(new_head == NULL)
        {
            last = temp;
            new_head = temp;
        }
        else
        {
            last->next = temp;
            last = temp;
        }
        temp1 = temp1->next;
    }
    while(temp2)
    {
        sum = temp2->val + carry;
        carry = sum/10;
        temp = new ListNode(sum%10);
        if(new_head == NULL)
        {
            last = temp;
            new_head = temp;
        }
        else
        {
            last->next = temp;
            last = temp;
        }
        temp2 = temp2->next;
    }
    if(carry)
    {
        temp = new ListNode(carry);
        if(new_head == NULL)
        {
            last = temp;
            new_head = temp;
        }
        else
        {
            last->next = temp;
            last = temp;
        }
    }
    return new_head;
}
