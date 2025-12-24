#ifndef GRAPH
#define GRAPH

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

class Graph{
    private:
        unordered_map<string,vector<string>> adj;
    public:
        Graph();
        void addEdge(string &username1,string &username2);
        vector<string> friends(string username);
        vector<string> suggestFriends(string username,int n,vector<string> &suggested);
        int shortestPath(string &username1,string &username2);
};

#endif