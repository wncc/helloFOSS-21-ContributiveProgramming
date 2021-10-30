struct Node{
    int key;
    Node* left_child;
    Node* right_child;
    int height;
    Node(){
        left_child=nullptr;
        right_child=nullptr;
        height=1; //height of leaf =1
    }
};

class AVLTree{
    Node* root;
    int height(Node* N);
    Node* left_rotate(Node* x);
    Node* right_rotate(Node* x);
    Node* insert_helper(Node* node,int key);
    Node* delete_helper(Node* node,int key);
    void in_order_helper(Node *x);

    public:
    AVLTree();
    void insert_node(int key);
    void delete_node(int key); 
    int height_tree();
    void in_order();
};