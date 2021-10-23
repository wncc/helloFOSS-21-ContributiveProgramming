#include <bits/stdc++.h>
#include "huffman.h"
using namespace std;

Node::Node(char ch, char freq)
{
    f = freq;
    c = ch;
    left_child = right_child = NULL;
}

Node::Node(char ch, char freq, Node* l,Node* r)
{
    f = freq;
    c = ch;
    left_child = l;
    right_child = r;
}

struct heap_comp 
{
	bool operator()(Node* l, Node* r)
	{ return (l->f > r->f); }
};

struct encoding
{
    char c;
    string code;
    encoding(){}
    void set(char letter,string co)
    {
        c = letter;
        code = co;
    }
};

void codes(struct Node* root, string str, vector<encoding> &enc)
{
	if (!root)
		return;

	if (root->c != '&')
	{
        enc[int(root->c)].set(root->c,str);
        //cout<<root->c<< ": " << str << "\n";
    }

	codes(root->left_child, str+"0",enc);
	codes(root->right_child, str+"1",enc);
}

Huffman::Huffman(string filename)
{
    inputfile = filename;
    filename.append(".txt");  
    root = NULL;
    for (int i = 0; i < 256; i++)
        frequency[i] = 0;
    
    fstream f;                   
    f.open(filename, ios::in);         
    if (!f) {                        
        cout<<"File doesn’t exist."; 
        exit(0);         
    }
    else {
        string str;
        char x;                     
        while (getline(f, str)) {         
            for (long i = 0; i < str.length(); i++)
            {
                frequency[int(str[i])]++; 
            }
            
            /*f>>x;
            frequency[int(x)]++; */           
            //cout<<x;                  
        }
    }
    f.close();
}

void Huffman::compress(string filename)
{
    if(filename.compare(inputfile)!=0)
    {
        cout<<filename<<":"<<inputfile<<endl;
        cout<<"Bye";
        return;
    }
    fstream f;  
    filename.append("_config.txt");                 
    f.open(filename, ios::trunc|ios::out);   

    priority_queue<Node*, vector<Node*>, heap_comp> Heap;
    Node *top,*left,*right;
    vector<encoding> enc(256);

    //making the nodes
    for (int i = 0; i < 256; i++)
    {
        if(frequency[i]!=0)
        {
            Heap.push(new Node(char(i),frequency[i]));
        }
    }
    
    //using the huffman encodig algorithm to do text compression
    while (Heap.size() != 1) {

		left = Heap.top();
		Heap.pop();

		right = Heap.top();
		Heap.pop();

		top = new Node('&',(left->f + right->f),left,right);
		Heap.push(top);
	}
    root = Heap.top();

    //storing encodings/codes in vector of struct encoding and _config textfile
    string str;
    codes(root,str,enc);
    for (int i = 0; i < 256; i++)
    {
        if(frequency[i]!=0)
        {
            f << char(i)<<":"<<enc[i].code<<"\n";
        }
    }
    f.close();

    //completing compression ny reading the file and converting storing the compressed file separately
    filename = inputfile;
    filename.append("_compressed.txt"); 
    fstream fout,fin;
    fout.open(filename, ios::trunc|ios::out); 
    filename = inputfile;
    filename.append(".txt"); 
    fin.open(filename, ios::in);
     
    char x;                     
    while (!fin.eof()) 
    {         
        fin>>x;
        fout<<enc[int(x)].code;
    }
    fout.close();
    fin.close();
}

void Huffman::decompress(string inputFile, string outputFile)
{
    fstream fcom,fdec,fencode;

    string filename = inputFile;
    filename.append("_compressed.txt"); 
    fcom.open(filename, ios::in);

    filename = outputFile;
    filename.append(".txt"); 
    fdec.open(filename, ios::trunc|ios::out);

    /*filename = inputFile;
    filename.append("_config.txt"); 
    fencode.open(filename, ios::in);

    //getting the encodings/keys from config file.
    vector<encoding> enc(256);

    string str;
    while (getline(fencode, str)) 
    {
        if(str.length()>0)
        {
            char c = str[0];
            string code;
            code = str.substr(1,str.length()-1);
            enc[int(c)].set(c,code);
            //cout<<c<<":"<<code<<endl;
        }
    }
    fencode.close();*/

    //getting the encoded/compressed data from input file
    string str;
    getline(fcom,str);
    fcom.close();
    
    
    //decompression and writing to output file
    Node *curr;
    for (long long i = 0; i < str.length(); )
    {
        curr = root;
        while(curr->c=='&')
        {
            if(str[i]=='0')
            { curr = curr->left_child; }
            else// if(str[i]=='1')
            { curr = curr->right_child; }
            i++;
        }
        fdec<<curr->c;
    }
    fdec.close();
}

int main(int argc, char** argv)
{
    string filename(argv[1]);
    string outfile(argv[2]);
    cout<<filename<<":::"<<outfile<<endl;
    Huffman x(filename);
    x.compress(filename);
    x.decompress(filename,outfile);
    return 0;
}