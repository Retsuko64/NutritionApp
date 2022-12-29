#ifndef _NUTRITIONIST_PAGE_HH_
#define _NUTRITIONIST_PAGE_HH_
#include<iostream>
#include<string>
using namespace std;

class Nutritionist {
//admin's credentials
string admin = "Jane";
string adminPassword = "123456";

public:
void homePage(string);
void setupDiet();
void readFoodIntake();
void checkAdmin(string ,string);
};
#endif