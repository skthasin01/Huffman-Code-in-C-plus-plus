#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    char ch;
    int freq;

    Node *left;
    Node *right;

    Node(char c, int f)
    {
        this->ch = c;
        this->freq = f;
        left = NULL;
        right = NULL;
    }
};

class Compare
{
public:
    bool operator()(Node* a, Node* b)
    {
        return a->freq > b->freq;
    }
};

void heapTree(priority_queue<Node*, vector<Node*>, Compare> &minheap){

    if(minheap.size() <= 1)
    {
        return;
    }
    Node* leftn = minheap.top();
    minheap.pop();
    Node* rightn = minheap.top();
    minheap.pop();
    Node* parent = new Node('#',leftn->freq + rightn->freq);
    parent->left = leftn;
    parent->right = rightn;

    minheap.push(parent);
    heapTree(minheap);
    
}


void generateCode(Node* root, string code,map<char,string> &codes){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        codes[root->ch] = code;
        cout << root->ch << "=" << code << endl;
        return;
    }

    generateCode(root->left, code + "0",codes);
    generateCode(root->right, code + "1",codes);
}


int main()
{
    int n;
    cout << "Enter a number for Characters: " << endl;
    cin >> n;
    vector<char> character(n);
    vector<int> frequency(n);
    long long int total_freq = 0;
    cout << "Enter the Charecters & Frequencys : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> character[i] >> frequency[i];
        total_freq += frequency[i];
    }
    long long int total_bits = (total_freq * 8);
    cout <<"\nTotal Bits : " << total_bits <<endl;

    priority_queue<Node*, vector<Node*>, Compare> minheap;

    for (int i = 0; i < n; i++)
    {
        Node *newnode = new Node(character[i], frequency[i]);
        minheap.push(newnode);
    }
    heapTree(minheap);
    Node* root = minheap.top();
    map<char,string> codes;

    cout << "\nHuffman Codes:" << endl;
    generateCode(root, "",codes);

    long long int bits = 0;
    for(int i=0; i<n; i++){
        bits = bits + (frequency[i] * codes[character[i]].length());
    }
    cout << "\nCompressed Bits : " << bits << endl;
    long long int save_memory = total_bits - bits;
    cout << "Save Memory : " << save_memory << endl;

    return 0;
}