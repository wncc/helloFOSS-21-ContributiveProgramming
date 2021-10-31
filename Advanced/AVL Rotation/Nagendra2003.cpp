#include "Nagendra2003.h"
#include<iostream>
using namespace std;
AVLTree::AVLTree(){
    root=nullptr;
}
int AVLTree::height(Node* N){
    if(N==nullptr){return 0;}
    else{return N->height;}
}
Node * AVLTree::left_rotate(Node *x)
{
    Node *a = x->right_child;
    Node *b = a->left_child;
    a->left_child = x;
    x->right_child = b;

    x->height = max(height(x->left_child),height(x->right_child)) + 1;
    a->height = max(height(a->left_child),height(a->right_child)) + 1;
    return a;//new root
}
Node * AVLTree::right_rotate(Node *x)
{
    Node *a = x->left_child;
    Node *b = a->right_child;
    a->right_child = x;//rotations
    x->left_child = b;
    x->height = max(height(x->left_child), height(x->right_child) ) + 1;
    a->height = max(height(a->left_child),height(a->right_child)) + 1;
 
    return a;//new root
}
Node* AVLTree::insert_helper(Node* x, int key)
{
    if (x == NULL){
        Node *temp=new Node();
        temp->key=key;
        return temp;
    }
 
    if (key < x->key)
        x->left_child = insert_helper(x->left_child, key);
    else
        x->right_child = insert_helper(x->right_child, key);
 
    x->height = 1 + max(height(x->left_child),height(x->right_child)); //height update
 
    int balance; //difference in heights of child
    if(x==nullptr){balance=0;}
    else{balance = height(x->left_child) - height(x->right_child);} 
    //four cases if it becomes unbalanced

    if (balance > 1 && key < x->left_child->key)
        return right_rotate(x);

    if (balance < -1 && key > x->right_child->key)
        return left_rotate(x);

    if (balance > 1 && key > x->left_child->key)
    {
        x->left_child = left_rotate(x->left_child);
        return right_rotate(x);
    }

    if (balance < -1 && key < x->right_child->key)
    {
        x->right_child= right_rotate(x->right_child);
        return left_rotate(x);
    }

    return x;
}
void AVLTree::insert_node(int key){
    root=insert_helper(root,key);
}

Node* AVLTree::delete_helper(Node* root, int key)
{
    if (root == NULL)
        return root;

    if ( key < root->key )
        root->left_child = delete_helper(root->left_child, key);
 
    else if( key > root->key )
        root->right_child = delete_helper(root->right_child, key);
    
    //if key is equal
    else
    {
        // node with only one child or no child
        if( (root->left_child == NULL) ||
            (root->right_child == NULL) )
        {
            Node *temp = root->left_child ? root->left_child : root->right_child;
 
            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
            *root = *temp; 
            delete(temp);
        }
        else
        {
            Node* temp = root->right_child;
            while (temp->left_child != NULL){temp = temp->left_child;}
            
            root->key = temp->key;
 
            root->right_child = delete_helper(root->right_child,temp->key);
        }
    }

    if (root == NULL){return root;}

    root->height = 1 + max(height(root->left_child),height(root->right_child));//height update

    int balance;
    if(root==nullptr){balance=0;}
    else{balance = height(root->left_child) - height(root->right_child);} 
 
    // 4 cases if node is unbalanced
    if (balance > 1 && (root->left_child==nullptr || (height(root->left_child->left_child) - height(root->left_child->right_child))>= 0))
        return right_rotate(root);
 
    // Left Right Case
    if (balance > 1 && root->left_child!=nullptr &&(height(root->left_child->left_child) - height(root->left_child->right_child)<0))
    {
        root->left_child = left_rotate(root->left_child);
        return right_rotate(root);
    }
 
    // Right Right Case
    if (balance < -1 && (root->left_child==nullptr || (height(root->right_child->left_child) - height(root->right_child->right_child))<= 0))
        return left_rotate(root);
 
    // Right Left Case
    if (balance < -1 && root->left_child!=nullptr &&(height(root->right_child->left_child) - height(root->right_child->right_child)>0))
    {
        root->right_child = right_rotate(root->right_child);
        return left_rotate(root);
    }
 
    return root;
}
void AVLTree::delete_node(int key){
    root=delete_helper(root,key);
} 

int AVLTree::height_tree(){
    return height(root);
}

void AVLTree::in_order_helper(Node *x){
    if(x!=nullptr){
        in_order_helper(x->left_child);
        cout<<x->key<<" ";
        in_order_helper(x->right_child);
    }
}
void AVLTree::in_order(){
    in_order_helper(root);
    cout<<endl;
}