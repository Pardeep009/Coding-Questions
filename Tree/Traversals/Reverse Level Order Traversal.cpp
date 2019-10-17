/*
  Given a tree. The task is to print the Reverse Level Order Traversal of the given tree.
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
        
  Output should be 7 2 5 1 11 13 4 4 8 5      
*/

/*This is a function problem.You only need to complete the function given below*/
/* A tree Node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

void reversePrint(Node *root)
{
    //Your code here
    if(root==NULL)
    return;
    queue<Node*> q;
    stack<int> stk;
    q.push(root);
    stk.push(root->data);
    Node *temp = NULL; 
    while(q.size())
    {
        temp = q.front();
        q.pop();
        if(temp->right)
        {
            q.push(temp->right);
            stk.push(temp->right->data);
        }
        if(temp->left)
        {
            q.push(temp->left);
            stk.push(temp->left->data);
        }
    }
    while(stk.size())
    {
        cout<<stk.top()<<" ";
        stk.pop();
    }
}
