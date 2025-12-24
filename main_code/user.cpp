#include "user.hpp"

User::User(string name){
    username=name;
}

void User::addPosts(int time,string content){
    posts.addPost(time,content);
}

void User::outputPosts(int n){
    posts.outputPosts(n);
}