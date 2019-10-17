/*
  Given a binary tree, find height of it.
  
          1
       /     \
     10      39
    /
  5
  
  The above tree has a height of 3.
  
  Note: Height of empty tree is considered 0.
  
*/
int height(Node* node)
{
   // Your code here 
   if(node == NULL)
   return 0;
   else
   {
       int l = height(node->left)+1;
       int r = height(node->right)+1;
       return l>r?l:r;
   }
}
