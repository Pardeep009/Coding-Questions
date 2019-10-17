/*

  You are given a tree and you need to do the level order traversal on this tree.
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
  
  Level order traversal of above tree is 5 4 8 11 13 4 7 2 5 1
        
*/
void levelOrder(Node* node)
{
  //Your code here
  if(node == NULL)
  return;
  queue<Node*> q;
  q.push(node);
  while(q.size())
  {
      cout<<q.front()->data<<" ";
      if(q.front()->left)
      q.push(q.front()->left);
      if(q.front()->right)
      q.push(q.front()->right);
      q.pop();
  }
}
