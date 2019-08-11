/*
  Given an array of size N that represents a Tree in such a way that array indexes are values in tree nodes and array values
  give the parent node of that particular index (or node).
  The value of the root node index would always be -1 as there is no parent for root.
  Construct the standard linked representation of Binary Tree from this array representation.
  
  Example:
  2                       // TEST CASES
  7                       // NO OF NODES
  -1 0 0 1 1 3 5          // PARENT ARRAY
  5                       // NO OF NODES
  -1 0 0 2 2              // PARENT ARRAY
  
  Output:
  0 1 2 3 4 5 6
  0 1 2 3 4
  
  Explanation:
  Testcase 1: For the array parent[] = {-1, 0, 0, 1, 1, 3, 5}; the tree generated will have a sturcture like

             0
           /   \
          1     2
         / \
        3   4
       /
      5
    /
    6
  
*/
Node *createTree(int parent[], int n)
{
    Node *nodes[n];
    Node *root = NULL;
    for(int i=0;i<n;i++)
    {
        nodes[i] = new Node(i);
    }
    for(int i=0;i<n;i++)
    {
        if(parent[i] == -1)
        {
            root = nodes[i];
        }
        else
        {
            if(nodes[parent[i]]->left)
            {
                nodes[parent[i]]->right = nodes[i];
            }
            else
            {
                nodes[parent[i]]->left = nodes[i];
            }
        }
    }
    return root;
}
