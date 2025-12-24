#ifndef SOCIALNET
#define SOCIALNET
#include "user.hpp"
#include "graph.hpp"

class SocialNet{
    private:
        unordered_map<string,User*> users;
        int globalTime;
        Graph graph;
    public:
        SocialNet();
        void addUser(string username);
        void addFriend(string username1,string username2);
        void listFriends(string username);
        void suggestFriends(string username,int n);
        void degreesOfSeperation(string username1,string username2);
        void addPost(string username,string content);
        void outputPosts(string username,int n);
};

#endif