#include<iostream>
#include<queue>
#include<vector>
#include<bitset>
#include<fstream>

#define MAX_TREE_HT 200

using namespace std;
struct Node{
    char c;
    long unsigned int f;
    Node* left;
    Node* right;
    Node(){f=0;left=nullptr;right=nullptr;}
};
class Huffman{
    int frequency[256];         // Maintaining frequencies for all of the characters appearing in the text
            // The Root node
    string inputfile;           // Input File's name

    struct Node *root;  
    public:
        Huffman(string filename);
        // Constructor: Read from file and compute character frequencies
        
        void setCodes(Node* root, char* arr,int top,string* codes);
        //Helper function to set code for each character

        void compress(string filename); 
        // Compress the text in the input file and output it!
        
        void decompress(string inputFile, string outputFile); 
        //Take some excerpts of compressed text from inputFile and print the actual decompressed text in outputFile 
};

//helper function
void Huffman:: setCodes(Node* root, char* arr,int top,string* codes)
{       
    // Assign 0 to left edge and recur
    if (root->left!=nullptr) {
        arr[top]='0';
       setCodes(root->left, arr,top+1,codes);
    }
    
        // Assign 1 to right edge and recur
    if (root->right!=nullptr) {
        arr[top]='1';
        setCodes(root->right, arr,top+1,codes);
    }

    if ((root->left==nullptr) && (root->right==nullptr)) {  //isleaf
        codes[(int)root->c]="";
        for(int i=0;i<top;i++){
            codes[(int)root->c]+=arr[i];
        }
        // cout<<root->c<<" "<<codes[(int)root->c]<<endl;
    }
}

Huffman::Huffman(string filename){
    inputfile=filename;
        for(int i=0;i<256;i++){
        frequency[i]=0;
    }

    fstream filein(filename,fstream::in);
    char c;
    while(filein>>noskipws>>c){
        frequency[(int)c]++;
    }
}
void Huffman::compress(string filename){

    //creating huffman tree
    Node* mynode[256]; //to store node of each character
    auto compare = [](Node* x,Node *y){return x->f > y->f;}; //comparator of priority queue
    priority_queue <Node*,vector<Node*>,decltype(compare)> pq(compare); 

    for(int i=0;i<256;i++){
        mynode[i]=new Node();
        mynode[i]->c=(char)i;
        mynode[i]->f=frequency[i];
        if(frequency[i]!=0){
            pq.push(mynode[i]);
        }
    }

    while(pq.size()>1){
        Node *min1=pq.top();
        pq.pop();
        Node* min2=pq.top();
        pq.pop();

        Node* temp=new Node();
        temp->f=min1->f + min2->f;
        temp->left=min2;
        temp->right=min1;

        pq.push(temp);
    }
    root=pq.top();

    string codes[256];  //code for each character if freq!=0
    Node *temp=root;
    char arr[MAX_TREE_HT];
    setCodes(temp,arr,0,codes);

    fstream filein(inputfile,fstream::in);
    ofstream outdata;
    outdata.open(filename);

    char c;
    int current_bit = 0;
    string eightbit="";
    char byte;
    while(filein>>noskipws>>c){
        string temp=codes[(int)c];
        for(int i=0;i<temp.length();i++){
           eightbit+=temp[i];

           current_bit++;
            if (current_bit == 8){
                bitset<8> x(eightbit);
                outdata<<(char)x.to_ulong(); //write ascii
                current_bit = 0;
                eightbit="";
            }
        }
    }
}

void Huffman::decompress(string inputFile, string outputFile){
    fstream filein(inputFile,fstream::in);
    ofstream outdata;
    outdata.open(outputFile);
    char c;
    Node*temp=root;
    while(filein>>noskipws>>c){
        int ascii=(int)c;
        if(ascii<0){ascii=ascii+256;}

        char bits[8];
        for(int i=7;i>=0;i--){
            if(ascii%2==1){bits[i]='1';}
            else{bits[i]='0';}
            ascii/=2;
        }

        for(int i=0;i<8;i++){
            if(bits[i]=='1' && temp->right!=nullptr){
                temp=temp->right;
            }
            else if(bits[i]=='0' && temp->left!=nullptr){
                temp=temp->left;
            }
            else{
                cout<<"error";
            }
            if(temp->left==nullptr && temp->right==nullptr){
                outdata<<temp->c;
                temp=root;
            }
        }
    }
    outdata.close();
}
int main(int argc,char* argv[]){
    if(argc==4){
        Huffman h(argv[1]);
        h.compress(argv[2]);
        h.decompress(argv[2],argv[3]);
    }
    else{cout<<"Please run as \"executable input.txt encoded.txt decoded.txt\""<<endl;}
}