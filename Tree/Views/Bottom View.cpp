/*
  Given a binary tree, print the bottom view from left to right.
  A node is included in bottom view if it can be seen when we look at the tree from bottom.

                        20
                      /    \
                    8       22
                  /   \        \
                5      3       25
                      /   \      
                    10    14

  For the above tree, the bottom view is 5 10 3 14 25.
  
  If there are multiple bottom-most nodes for a horizontal distance from root, 
  then print the later one in level traversal. For example, in the below diagram, 3 and 4 are both the bottommost nodes 
  at horizontal distance 0, we need to print 4.

                        20
                      /    \
                    8       22
                  /   \     /   \
                5      3 4     25
                       /    \      
                   10       14

  For the above tree the output should be 5 10 4 14 25.
*/

/* Tree node class
struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references
    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
}; */

void generateview(Node *root,map<int,pair<int,int>> &m,int height,int index)
{
    if(root == NULL)
    return;
    m[index] = make_pair(root->data,height);
    generateview(root->left,m,height+1,index-1);
    generateview(root->right,m,height+1,index+1);
}

// Method that prints the bottom view.

void bottomView(Node *root)
{
   // Your Code Here
    map<int,pair<int,int>> m;
    generateview(root,m,0,0);
    map < int, pair < int, int > > ::iterator it; 
    for (it = m.begin(); it != m.end(); ++it) 
    { 
        pair < int, int > p = it -> second; 
        cout << p.first << " "; 
    } 
}
