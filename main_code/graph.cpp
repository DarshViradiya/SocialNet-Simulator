#include "graph.hpp"
#include <unordered_set>

Graph::Graph(){
    
}

void Graph::addEdge(string &username1,string &username2){
    adj[username1].push_back(username2);
    adj[username2].push_back(username1);
}

vector<string> Graph::friends(string username){
    vector<string> listFriends=adj[username];
    sort(listFriends.begin(),listFriends.end());
    return listFriends;
}

vector<string> Graph::suggestFriends(string username,int n,vector<string> &suggested){
    if(n==0){
        return suggested;
    }
    unordered_set<string> direct(adj[username].begin(),adj[username].end());
    direct.insert(username);
    unordered_map<string,int> visited;
    visited[username]++;
    unordered_map<string,int> mutual;
    for(string name:adj[username]){
        for(string FoF:adj[name]){
            if(direct.find(FoF)==direct.end()){
                mutual[FoF]++;
            }
        }
    }
    vector<pair<string,int>> sorted;
    for(auto &pair:mutual){
        sorted.push_back(pair);
    }
    sort(sorted.begin(),sorted.end(),[](const auto &a, const auto &b){
        if(a.second!=b.second) return a.second>b.second;
        return a.first<b.first;
    });
    for(auto ele:sorted){
        suggested.push_back(ele.first);
        visited[ele.first]++;
    }
    vector<string> temp;
    for(string name:adj[username]){
        for(string neighbours:adj[name]){
            if(visited[neighbours]==0 && mutual.find(neighbours)==mutual.end() && direct.find(neighbours)==direct.end()){
                temp.push_back(neighbours);
                visited[neighbours]++;
            }
        }
    }
    sort(temp.begin(),temp.end());
    suggested.insert(suggested.end(),temp.begin(),temp.end());
    if(suggested.size()<n){
        return suggested;
    }
    else{
        vector<string> ans;
        for(int i=0;i<n;i++){
            ans.push_back(suggested[i]);
        }
        suggested=ans;
        return suggested;
    }
}

int Graph::shortestPath(string &username1,string &username2){
    if(username1==username2) return 0;
    queue<string> bfs;
    bfs.push(username1);
    unordered_map<string,int> visited;
    unordered_map<string,int> dist;
    visited[username1]++;
    dist[username1]=0;
    int path=0;
    while(!bfs.empty()){
        string temp=bfs.front();
        bfs.pop();
        for(auto it:adj[temp]){
            if(!visited[it]){
                visited[it]++;
                dist[it]=dist[temp]+1;
                bfs.push(it);
                if(it==username2){
                    return dist[it];
                }
            }
        }
    }
    return -1;
}