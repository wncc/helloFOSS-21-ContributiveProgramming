#include<bits/stdc++.h>

using namespace std;

template<typename T>
class AVLNode {
public:
    AVLNode<T> *left = NULL, *right = NULL;
    int height = 0;
    T val;

    AVLNode() {}
    AVLNode(T x) : val(x) {}

    ~AVLNode() {
        delete left;
        delete right;
    }

    int getHeight(AVLNode<T> *x) {
        if (!x) return -1;
        else return x->height;
    }

    AVLNode<T>* rotateLeft() {
        AVLNode<T> *dummy = right;
        right = dummy->left;
        dummy->left = this;
        height = 1 + max(getHeight(left), getHeight(right));
        dummy->height = 1 + max(getHeight(dummy->left), getHeight(dummy->right));
        return dummy;
    }

    AVLNode<T>* rotateRight() {
        AVLNode<T> *dummy = left;
        left = dummy->right;
        dummy->right = this;
        height = 1 + max(getHeight(left), getHeight(right));
        dummy->height = 1 + max(getHeight(dummy->left), getHeight(dummy->right));
        return dummy;
    }

    AVLNode<T>* balance() {
        int rh = getHeight(right), lh = getHeight(left);
        if (abs(rh-lh) <= 1) return this;
        AVLNode<T> *dummy = this;
        if (rh > lh + 1) {
            int rlh = getHeight(right->left), rrh = getHeight(right->right);
            if (rrh > rlh) {
                dummy = rotateLeft();
            } else {
                right = right->rotateRight();
                dummy = rotateLeft();
            }
        } else if (lh > rh + 1) {
            int llh = getHeight(left->left), lrh = getHeight(left->right);
            if (llh > lrh) {
                dummy = rotateRight();
            } else {
                left = left->rotateLeft();
                dummy = rotateRight();
            }
        }
        return dummy;
    }

    void show() {
        if (left) left->show();
        cout << val << " ";
        if (right) right->show();
    }

    AVLNode<T>* insert(T x) {
        if (x <= val) {
            if (!left) left = new AVLNode<T>(x);
            else left = left->insert(x);
        } else {
            if (!right) right = new AVLNode<T>(x);
            else right = right->insert(x);
        }
        height = 1 + max(getHeight(left), getHeight(right));
        AVLNode<T>* dummy = balance();
        return dummy;
    }
};

template<typename T>
class AVLTree {
    int _size = 0, _height = -1;
    AVLNode<T>* root = new AVLNode<T>();
public:

    AVLTree() {}
    
    void insert(T x) {
        if (_size == 0) root->val = x;
        else root = root->insert(x);
        _size++;
        _height = root->height;
    }

    int height() {
        return _height;
    }

    int size() {
        return _size;
    }

    void showOrder() {
        if (_size) root->show();
    }

};

int main() {
    AVLTree<int> T;
    int n = 1000;
    for (int i = 0; i < n; i++) T.insert(rand() % 100);
    cout << T.size() << " " << T.height() << endl;
    T.showOrder();
}
