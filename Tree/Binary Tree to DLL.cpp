/*

  Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place.
  The order of nodes in DLL must be same as Inorder of the given Binary Tree.
  The first node of Inorder traversal (left most node in BT) must be head node of the DLL.
  
  Example:
  Input:
  2
  2
  1 2 R 1 3 L
  4
  10 20 L 10 30 R 20 40 L 20 60 R

  Output:
  3 1 2 
  2 1 3 
  40 20 60 10 30 
  30 10 60 20 40

  Explanation:
  Testcase1: The tree is
          1
       /      \
     3       2
  So, DLL would be 3<=>1<=>2

  Testcase2: The tree is
                             10
                          /        \
                       20         30
                    /       \
                 40       60
  So, DLL would be 40<=>20<=>60<=>10<=>30.
    
*/
void inorder(Node*root,queue<node*>&q){
  if(root)
  {
    inorder(root->left,q);
    q.push(root);
    inorder(root->right,q);
  }
 }
 
 void bToDLL(Node *root, Node **head_ref)
 {
    // your code here
    if(root)
    {
      queue<node*> q;
      inorder(root,q);
      *head_ref = q.front();
      Node* t=NULL;
      while(!q.empty())
      {
        t=q.front();
        q.pop();
        if(!q.empty())
        {
          t->right=q.front();
          q.front()->left=t;
        }
        else
        {
          t->right=NULL;
        }
      }
    }
 }
 /*          // recursive approach
  void DLL(Node *root,Node **head_ref,Node* &temp)
  {
      if(root == NULL)
      return;

      DLL(root->left,head_ref,temp);

      if(*head_ref == NULL)
      {
          *head_ref = root;
      }
      else
      {
          temp->right = root;
          root->left = temp;
      }
      temp = root;
      
      DLL(root->right,head_ref,temp);

  }
  void bToDLL(Node *root, Node **head_ref)
  {
      // your code here
      Node *tail_ref=NULL;
      DLL(root,head_ref,tail_ref);
  }
 */
