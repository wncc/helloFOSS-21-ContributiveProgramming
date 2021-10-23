#include <bits/stdc++.h>
using namespace std;

struct Node{
    char c;                 //the character stored, if stored
    int f;                  //Total frequency associated with all nodes, in the subtree through this node
    Node* left_child;
    Node* right_child;
    Node(char ch, char freq);
    Node(char ch, char freq, Node* l,Node* r);
};

class Huffman{

    int frequency[256];         // Maintaining frequencies for all of the characters appearing in the text
   
    struct Node *root;          // The Root node
   
    string inputfile;           // Input File's name
  
    public:

        Huffman(string filename);
        // Constructor: Read from file and compute character frequencies 
        
        void compress(string filename); 
        // Compress the text in the input file and output it!
        
        void decompress(string inputFile, string outputFile);    
        //Take some excerpts of compressed text from inputFile and print the actual decompressed text in outputFile 
};

// Implement all of these functions in huffman.cpp alongwith a main() function which calls all these functions in appropriate order.