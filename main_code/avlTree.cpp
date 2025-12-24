#include "avlTree.hpp"

AVLTree::AVLTree(){
    root=nullptr;
}

int AVLTree::getHeight(Node* node){
    return node ? node->height : 0;
}

int AVLTree::heightDiff(Node* node){
    return node ? getHeight(node->left)-getHeight(node->right) : 0;
}

Node* AVLTree::rightRotate(Node* node){
    Node* x=node->left;
    Node* y=x->right;
    node->left=y;
    x->right=node;

    x->height=max(getHeight(x->left),getHeight(x->right))+1;
    node->height=max(getHeight(node->left),getHeight(node->right))+1;

    return x;
}


Node* AVLTree::leftRotate(Node* node){
    Node* x=node->right;
    Node* y=x->left;
    node->right=y;
    x->left=node;

    x->height=max(getHeight(x->left),getHeight(x->right))+1;
    node->height=max(getHeight(node->left),getHeight(node->right))+1;

    return x;
}

Node* AVLTree::insertNode(Node* node,int time,string content){
    if(!node) return new Node(time,content);
    if(time<node->time){
        node->left=insertNode(node->left,time,content);
    }
    else if(time>node->time){
        node->right=insertNode(node->right,time,content);
    }
    else{
        return node;
    }
    node->height=max(getHeight(node->left),getHeight(node->right))+1;
    int diff=heightDiff(node);
    if(diff>1 && time<node->left->time){
        return rightRotate(node);
    }
    if(diff>1 && time>node->left->time){
        node->left=leftRotate(node->left);
        return rightRotate(node);
    }
    if(diff<-1 && time>node->right->time){
        return leftRotate(node);
    }
    if(diff<-1 && time<node->right->time){
        node->right=rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void AVLTree::inorder(Node* node,vector<Node*> &traversal){
    if(!node) return;
    inorder(node->left,traversal);
    traversal.push_back(node);
    inorder(node->right,traversal);
}

void AVLTree::addPost(int time,string content){
    root=insertNode(root,time,content);
}

void AVLTree::outputPosts(int num){
    vector<Node*> traversal;
    inorder(root,traversal);
    int len=traversal.size();
    if(len==0){
        cout<<"No posts available"<<endl;
        return;
    }
    int post_num=1;
    if(num==-1 || len<num){
        for(int i=len-1;i>=0;i--){
            cout<<"Post #"<<post_num<<" : "<<traversal[i]->content<<endl;
            post_num++;
        }
    }
    else{
        for(int i=len-1;i>=len-num;i--){
            cout<<"Post #"<<post_num<<" : "<<traversal[i]->content<<endl;
            post_num++;
        }
    }
}