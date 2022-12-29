#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "usernames_and_passwords.hh"
#include <sstream>  
using namespace std;

void printHashMap(unordered_map<string,string>); // for testing purpose

UserAndPasswords::UserAndPasswords() {
loadInfo();// load all the information from the text file
UserAndPasswords::info["Retsuko64"] = "Splatoon2022";
}

/**
 * returns the hashmap of users and passwords
*/
unordered_map<string,string> UserAndPasswords::getInfo(){
    return UserAndPasswords::info;
}

/**
 * adds the user to the hashmap then we will save it on a text file too using the saveInfo() function.
 * @param username
 * @param password
*/
void UserAndPasswords::registerUser(string username, string password) {
UserAndPasswords::info[username] = password;
saveInfo(username, password);
}


/**
 * when user registers we want to store his information in the text file, which is what this function will do.
 * @param username
 * @param password
*/
void UserAndPasswords::saveInfo(string username, string password){
ofstream file;
file.open("users.txt", ios::app); // app means to append, cause if we don't put it the open() function will overide the file 
                                  // and delete all the users :(
file<<username<<" "<<password<<"@";
file.close();
}

/**
 * What this function will do it will read the text file that contains usernames and passwords and place them in the hashmap
 * to be used for login purposes.
*/
void UserAndPasswords::loadInfo(){
ifstream file("users.txt");
string s;
string info;
string infoArray[2]; // first element is going to be username 2nd would be password

while(getline(file, s , '@')){ // read the line on the text file until it reaches '@'
int i = 0;
stringstream X(s);

while(getline(X , info , ' ')){ // after reading line we will split it
infoArray[i] = info;
i++;
}

UserAndPasswords::info[infoArray[0]] = infoArray[1];// first element would be the username and second would be the password
}

file.close();
}


/**
 * the function will iterate through the hashmap
 * @param hashmap of strings keys and string values
*/
void printHashMap(unordered_map<string,string> hash){
    for (auto s : hash){
        cout<<"Username: "<< s.first <<" Password: "<< s.second<<endl;
    }
}