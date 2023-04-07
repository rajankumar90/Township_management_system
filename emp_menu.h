//header files
#include<stdio.h>
#include<string.h>    //use for strcmp(),strcpy(),etc.
#include<stdlib.h>
#include"validation.h"
#include "visitor_details.h"
#include "visit_details.h"


#define EXITEMPLOYEE 0
#define LISTVISITORDETAIL 1
#define ADDVISITORDETAIL 2
#define MODIFYVISITORS 3
#define ADDVISITENTRIES 4
#define DISPLAYVISITENTRIES 5
#define LISTOWNERDET 6
#define LISTTENANTDET 7
#define LOGOUTFROMEMP 8


#define EXITEMP 0
#define LOGINEMP 1
#define REGISTEREMP 2


//structure for Employee
struct Employee{

	//initialising variables
	int eid_pk;         //employee id
	char emp_name[20];  //employee name
	char email_id[50];  //employee email id 
	long int emp_phone_no;//employee phone number
	char login_id[20];    //employee login id
	char password[20];    //employee password
};

//function declaration
void WelcomeTitleLogin();//WelcomeTitleLogin function declaration

void WelcomeScreen();   //welcome screen function declaration

void Title();	     //Title function declaration

void Menu();	     //menu function declaration

void LoginScreen();     //login screen function declaration

void listtenanatdetails(); //to display owner details by reading the data from owner detail file

void listOwnerdetails(); //to display tenant details by reading data from tenant details file

void Exit();	      //exit function declaration

void login_register_menu();   //login and registration function declaration

void logine();		//login function declaration

void regster();        //registration function declaration

int autoIncrementEmployee(int);  //to increment id automatically
