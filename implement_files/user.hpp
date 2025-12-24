#ifndef USER
#define USER

#include <iostream>
#include "avlTree.hpp"
using namespace std;

struct User{
    public:
        string username;
        AVLTree posts;

        User(string name);
        void addPosts(int time,string content);
        void outputPosts(int n);
};

#endif