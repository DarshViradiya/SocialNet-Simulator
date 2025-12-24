#include "socialNet.hpp"
#include <sstream>

vector<string> splitString(string s){
    istringstream iss(s);
    vector<string> tokens;
    string token;
    while(iss>>token){
        tokens.push_back(token);
    }
    return tokens;
}

string toLowerStr(string s) {
    transform(s.begin(),s.end(),s.begin(),::tolower);
    return s;
}

int main(){
    SocialNet sn;
    string line;
    cout<<"SocialNet is now running, type 'END' to quit"<<endl;
    while(true){
        if(!getline(cin,line)) break;
        if(line=="END") break;
        vector<string> tokens=splitString(line);
        if(tokens.empty()) continue;
        string command=tokens[0];
        if(command=="ADD_USER" && tokens.size()==2) sn.addUser(toLowerStr(tokens[1]));
        else if(command=="ADD_FRIEND" && tokens.size()==3) sn.addFriend(toLowerStr(tokens[1]),toLowerStr(tokens[2]));
        else if(command=="LIST_FRIENDS" && tokens.size()==2) sn.listFriends(toLowerStr(tokens[1]));
        else if(command=="SUGGEST_FRIENDS" && tokens.size()==3){
            try {
                int n = stoi(tokens[2]);
                sn.suggestFriends(toLowerStr(tokens[1]), n);
            } catch (const invalid_argument&) {
                cout << "Error: '" << tokens[2] << " is not a valid number for OUTPUT_POSTS." << endl;
            } catch (const out_of_range&) {
                cout << "Error: number too large in OUTPUT_POSTS command." << endl;
            }
        }
        else if(command=="DEGREES_OF_SEPARATION" && tokens.size()==3) sn.degreesOfSeperation(toLowerStr(tokens[1]),toLowerStr(tokens[2]));
        else if(command=="ADD_POST" && tokens.size()>=3){
            size_t pos=line.find(tokens[2]);
            string longStr=line.substr(pos);
            sn.addPost(toLowerStr(tokens[1]),longStr);
        }
        else if(command=="OUTPUT_POSTS" && tokens.size()==3){
            try {
                int n = stoi(tokens[2]);
                sn.outputPosts(toLowerStr(tokens[1]), n);
            } catch (const invalid_argument&) {
                cout << "Error: '" << tokens[2] << " is not a valid number for OUTPUT_POSTS." << endl;
            } catch (const out_of_range&) {
                cout << "Error: number too large in OUTPUT_POSTS command." << endl;
            }
        }
        else{
            cout<<"Invalid Input"<<endl;
        }
    }
    cout<<"Exiting SocialNet"<<endl;
    return 0;
}