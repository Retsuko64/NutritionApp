#ifndef _USERNAMES_AND_PASSWORDS_HH_
#define _USERNAMES_AND_PASSWORDS_HH_
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

class UserAndPasswords{
private:
unordered_map<string,string> info; 
void loadInfo();
void saveInfo(string,string);

public:
UserAndPasswords();
unordered_map<string,string> getInfo();
void registerUser(string,string);
};
#endif