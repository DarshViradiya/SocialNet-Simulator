#include "socialNet.hpp"

SocialNet::SocialNet(){
    globalTime=0;
}

void SocialNet::addUser(string username){
    if(username.empty()){
        cout<<"Username cannot be empty"<<endl;
        return;
    }
    if(users.find(username)==users.end()){
        users[username]=new User(username);
        cout<<"User "<<username<<" added to SocialNet"<<endl;
    }
    else{
        cout<<"User already exists"<<endl;
    }
}

void SocialNet::addFriend(string username1,string username2){
    if(username1.empty() || username2.empty()){
        cout<<"Either 1 or both username/s are empty"<<endl;
        return;
    }
    if(username1==username2){
        cout<<"Self friendship is not possible"<<endl;
        return;
    }
    if(users.find(username1)==users.end() || users.find(username2)==users.end()){
        cout<<"Both users must exist for them to be friends"<<endl;
    }
    else{
        graph.addEdge(username1,username2);
        cout<<username1<<" and "<<username2<<" are friends now"<<endl;
    }
}

void SocialNet::listFriends(string username){
    if(username.empty()){
        cout<<"Username cannot be empty"<<endl;
        return;
    }
    if(users.find(username)==users.end()){
        cout<<username<<" does not exist"<<endl;
    }
    else{
        vector<string> neighbours=graph.friends(username);
        if(neighbours.empty()){
            cout<<username<<" has no firends yet"<<endl;
        }
        cout<<"Friends of "<<username<<" are:"<<endl;
        for(auto ele:neighbours){
            cout<<ele<<" "<<endl;
        }
        cout<<endl;
    }
}

void SocialNet::suggestFriends(string username,int n){
    vector<string> suggested;
    vector<string> FoF;
    if(users.find(username)==users.end()){
        cout<<username<<" does not exist"<<endl;
        return;
    }
    FoF=graph.suggestFriends(username,n,suggested);
    if(FoF.size()==0){
        cout<<"There are no friends to suggest"<<endl;
    }
    else{
        cout<<"Top "<<FoF.size()<<" friends of friends of "<<username<<" are:"<<endl;
        for(auto ele:FoF){
            cout<<ele<<" "<<endl;
        }
        cout<<endl;
    }
}

void SocialNet::degreesOfSeperation(string username1,string username2){
    if(users.find(username1)==users.end() || users.find(username2)==users.end()){
        cout<<"Both users must exist for them to be friends"<<endl;
    }
    else{
        int minDis=graph.shortestPath(username1,username2);
        cout<<"Minimum degree of seperation between "<<username1<<" and "<<username2<<" is: "<<minDis<<endl;
    }
}

void SocialNet::addPost(string username,string content){
    if(users.find(username)==users.end()){
        cout<<username<<" does not exist"<<endl;
    }
    else{
        globalTime++;
        users[username]->addPosts(globalTime,content);
        cout<<username<<" has added a post"<<endl;
    }
}

void SocialNet::outputPosts(string username,int n){
    if(users.find(username)==users.end()){
        cout<<username<<" does not exist"<<endl;
    }
    else{
        users[username]->outputPosts(n);
    }
}