#ifndef AVLTREE
#define AVLTREE

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct Node{
    int time;
    string content;
    Node* left;
    Node* right;
    int height;

    Node(int t,string c){
        time=t;
        content=c;
        left=nullptr;
        right=nullptr;
        height=1;
    }
};

class AVLTree{
    private:
        Node* root;
        int getHeight(Node* node);
        int heightDiff(Node* node);
        Node* rightRotate(Node* node);
        Node* leftRotate(Node* node);
        Node* insertNode(Node* node,int time,string content);
        void inorder(Node* node,vector<Node*> &traversal);
    
    public:
        AVLTree();
        void addPost(int time,string content);
        void outputPosts(int num);
};


#endif