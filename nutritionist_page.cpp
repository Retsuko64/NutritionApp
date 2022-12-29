#include <iostream>
#include <string>
#include <fstream>
#include "nutritionist_page.hh"
using namespace std;

/**
 * the admin's main page, they will be presented by a menu, they would have to choose either of the options, else quit.
 * @param username, to introduce
*/
void Nutritionist::homePage(string username){
int choice;
cout<<"----------Admin-------------"<<endl;
cout<<"Welcome "<<username<<endl;
cout<<"Choose one of the options"<<endl;
cout<<"1-Check today's user's food intake\n2-Set up a diet for user\nor other key to exit program"<<endl;
cin>>choice;

switch(choice){
case 1:
readFoodIntake();
break;
case 2:
setupDiet();
default:
cout<<"Program Ended"<<endl;
}
}

/**
 * this function only checks if the credentials placed match the admin's credentials, in order to confirm if its the admin or not.
 * @param username 
 * @param password
*/
void Nutritionist::checkAdmin(string username , string password){
    if (username == admin && password == adminPassword){
        homePage(username);
    }
}

/**
 * This function will set up a diet for a specific user. first the admin states who, then a file would be created for that specefic 
 * user.
*/
void Nutritionist::setupDiet() {
string null, username, breakfast, lunch, snack, dinner;
getline(cin, null); 
cout<<"------------Set Up Diet-------------"<<endl;
cout<<"For which user?"<<endl;
getline(cin, username);

cout<<"Breakfast: "<<endl;
getline(cin, breakfast);

cout<<"Lunch: "<<endl;
getline(cin, lunch);

cout<<"Snack: "<<endl;
getline(cin, snack);

cout<<"Dinner: "<<endl;
getline(cin, dinner);

string message = "Breakfast: " + breakfast + "\n" + "Lunch: " + lunch + "\n" + "Snack: " + snack + "\n" + "Dinner: " + dinner;

ofstream file;
file.open(username+"Diet.txt");
file<<message;

file.close();
homePage("Jane");
}

/**
 * This function will allow the admin to read from a file, after stating its name(it would be the username) then it will
 * show the food intake the user had today.
*/
void Nutritionist::readFoodIntake() {
string username, message;
cout<<"------------Read food Intake-------------"<<endl;
cout<<"For what user?"<<endl;
cin>>username;
ifstream file(username+"Today.txt");
while(getline(file, message)){
   cout<<message<<endl;
}

file.close();
homePage("Jane");
}