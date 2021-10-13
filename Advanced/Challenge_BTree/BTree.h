#include<bits/stdc++.h>
using namespace std;
 

class BTreeNode
{
    int *keys;      // Keys stored
    int t;          // Minimum out-degree
    BTreeNode **C;  // Children nodes
    int n;          // Number of Children
    bool leaf;      // Bool denoting if its a leaf node
public:
    BTreeNode(int _t, bool _leaf);   // Constructor
    void insertNonFull(int k);  // Inserting into the node, provided it isn't full
    void splitChild(int i, BTreeNode *y);   // Splitting its ith child
    void traverse();                        //For Post-order traversal
    BTreeNode *search(int k);               //For Searching

friend class BTree;
};
 
// A BTree
class BTree
{
    BTreeNode *root;        // Root Node
    int t;                  // Minimum out-degree of node 
public:

    BTree(int _t)       //Constructor
    {  root = NULL;  t = _t; }
 

    void traverse()    // Tree Traversal
    {  if (root != NULL) root->traverse(); }

    BTreeNode* search(int k)       // Searching for a value
    {  return (root == NULL)? NULL : root->search(k); }
 
    void insert(int k);     // Inserting a value
    void Delete(int k);     //TODO :  Deleting a value 
};
 

