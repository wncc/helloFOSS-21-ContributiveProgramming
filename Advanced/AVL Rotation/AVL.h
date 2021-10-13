struct Node{
    int key;
    Node* left_child;
    Node* right_child;
    int height;
};

class AVLTree{
    Node* root;
    Node* left_rotate(Node* x);
    Node* right_rotate(Node* x);

    public:
    AVLTree();
    Node* insert_node(int key);
    Node* delete_node(int key);
    int height_tree();
    void in_order();  
};

