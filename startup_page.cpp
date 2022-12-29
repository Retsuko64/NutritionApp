#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include "usernames_and_passwords.hh"
#include "nutritionist_page.hh"
using namespace std;

void startUpPage();
void loginPage();
void RegisterPage();
bool checkCredentials(string,string);
void homePage(string);
void calculateBMI(string);
void setFoodIntake(string);
void checkUserDiet(string);
void adminLogin();

UserAndPasswords information;
Nutritionist nInfo;

int main() {  
startUpPage();
return 0;
}

/**
 * This function will start up the app by displaying 2 different options either sign in or register
*/
void startUpPage() {
cout<<"-------------Nutrition App----------------"<<endl;
cout<<"Hello user, press 1 to login or 2 to register (3 for admin login)"<<endl;
cout<<"1- Login\n2- Register\n3- Admin Login"<<endl;

int choice; 
cin>>choice;

switch(choice){
    case 1:
    loginPage();
    break;
    case 2:
    RegisterPage();
    break;
    case 3:
    adminLogin();
    break;
    default:
    cout<<"Unknown operation--(please click either 1 or 2 option)"<<endl;
}
}

/**
 * This function will take the username and password from the admin, and checks to confirm that indeed they would be the admin.
*/
void adminLogin() {
string username;
string password;

cout<<"--------Admin Login-----------"<<endl;
cout<<"Input your user name"<<endl;
cin>>username;
cout<<"Input your Password"<<endl;
cin>>password;

nInfo.checkAdmin(username, password);
}

/**
 * when user presses 1, the loginPage function will be called, and then ask user for his credentials, we then see if it exist in the 
 * hashMap (unordered_map) and if it does this function will take the user to the home page using the HomePage function.
*/
void loginPage(){
string username;
string password;

cout<<"--------login Page-----------"<<endl;
cout<<"Input your user name"<<endl;
cin>>username;
cout<<"Input your Password"<<endl;
cin>>password;

if(information.getInfo().find(username) == information.getInfo().end())  
cout<<"Username does not exist"<<endl;
else {
   if (information.getInfo().at(username) == password){
      homePage(username);
   } 
   else 
   cout<<"Wrong password"<<endl;
}
}

/**
 * When user presses 2, he will be prompted to a register page, he should follow the instructions given by this function, (username
 * length - avoid empty information - illegal input - etc..) after that we will store the information
*/
void RegisterPage(){
string username;
string password;
cout<<"-------Register page---------"<<endl;
while(true) {
cout<<"Input your user name"<<endl;
cin>>username;
cout<<"Input your Password"<<endl;
cin>>password;

if(checkCredentials(username , password)){
information.registerUser(username , password);
break;
}
else{
cout<<"Invalid"<<endl;
}
}

cout<<"User Registered successfully"<<endl;
startUpPage();
}

/**
 * function that will check if the username and password placed are valid as in:
 * 1) username doesn't already exist
 * 2) password size 
 * 3) they're not empty
 * @param username 
 * @param password
 * @return bool value, 1 if its valid credentials , 0 otherwise.
 * 
*/
bool checkCredentials(string username, string password) {
if (username.length() <= 4) { // username is small or empty
cout<<"Small username"<<endl;
return false;
}

else if (information.getInfo().find(username) != information.getInfo().end() || username == "Jane"){ //user already exist
cout<<"User already exist"<<endl;
return false;
}

else if(password.length() <= 5){ // weak password 
cout<<"Short password"<<endl;
return false;
}

return true; // else if no return is called means that its valid
}

/**
 * user's main home page we will display a set of options to the user and they will pick either of the choices.
*/
void homePage(string username) {
cout<<"-----------HomePage------------"<<endl;
int choice;
cout<<"Welcome "<<username<<endl;
cout<<"Select one of the options"<<endl;
cout<<"1-Calculate BMI\n2-Find diet\n3-Set today's food intake\nOr click any to exit program"<<endl;

cin>>choice;
switch(choice){
case 1:
calculateBMI(username);
break;
case 2:
checkUserDiet(username);
break;
case 3:
setFoodIntake(username);
break;
default:
cout<<"Program ended"<<endl;
}
}

/**
 * This function after the user asks for it, user will follow instructions, by placing height and meter it will return the BMI
 * 
 * @param username, to be used to go back to the homepage
*/
void calculateBMI(string username){
cout<<"----------Calculate BMI-------------"<<endl;
double weight,height;
bool again = true;

cout<<"Input your weight (in kilograms)"<<endl;
while(true){
if (cin>>weight) // if weight is not a value it would return false
break;
else {
   cout<<"Invalid"<<endl;
   cin.clear(); // resets the error state
   while(cin.get() != '\n') ; // clears everything that was placed in the previous line
}
}

cout<<"Input your height (in meters)"<<endl;
while(true){
if (cin>>height) // similarily, if height is not a value it returns false
break;
else {
   cout<<"invalid"<<endl;
   cin.clear(); // resets the error state
   while(cin.get() != '\n') ; // clears everything that was placed on the previous line
}
}
cout<<"Your BMI is"<<endl;
cout<<weight/(height*height)<<endl; // final result

homePage(username); //then back to homepage
}


/**
 * this function will read a file that contains the user's Diet
 * @param username
*/
void checkUserDiet(string username){
ifstream file(username+"Diet.txt");
string message;
while(getline(file, message)){
   cout<<message<<endl;
}

file.close();
homePage(username);
}

/**
 * This function will allow the user to state what he ate during his day.
 * @param username
*/
void setFoodIntake(string username){
string null, breakfast, lunch, snack, dinner;
getline(cin, null);// if i dont do this it will skip to break lunch part and avoid breakfast
cout<<"----------What you had today?-------------"<<endl;
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
file.open(username+"Today.txt");
file<<message;

file.close();
homePage(username);
}