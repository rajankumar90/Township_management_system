//header file::
/* This is file containing function prototype, global declarations.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"validation.h"

#define EXITFROMAPPLICATIONEMPLOYEE 0 
#define ADDEMPLOYEEDETAIL 1
#define MODIFYEMPLOYEEDETAIL 2
#define DELETEEMPLOYEEDETAIL 3
#define DISPLAYEMPLOYEEDETAIL 4

#define EXITFROMEMP 0
#define NAMESOFEMP 1
#define PASSWORDSOFEMP 2
#define EMAILSOFEMP 3
#define PHONENOSOFEMP 4
#define BACKTOPREVIOUSEMPS 5


/*creating a structure 
In this structure we are storing one integer data which is foremployee id, one long interger for storing the phone number
and four strings for storing employee name, email id, login id,password.
*/
typedef struct EmployeeDetails
{
    int eid_pk;           //taking integer input
    long int emp_phone_no;       //taking long integer input
    char emp_name[20], email_id[20], login_id[20],emp_password[20];   // taking string inputs
    
}e_details;      //giving an alternative name to the EmployeeDetails structure
 





//struct Linkedlist to store ownner details in a e_node
typedef struct e_LinkedList
{
    int eid_pk;           //taking integer input
    long int emp_phone_no;       //taking long integer input
    char emp_name[20], email_id[20], login_id[20],emp_password[20];   // taking string inputs
    struct e_LinkedList *next; 
}e_node;




int autoIncrementEmp(int); //to increment the employee id automatically


//This is a function for creating newnode for linkedlist
e_node* e_createNode(e_details);


//This is a function to add node to an linkedlist
e_node* e_addNode(e_node *,e_node *);


//This is a fuction that takes details that are needed to be modified by the user
void e_enterModifiedData(e_node *);



//This is a fuction used for adding employee details
e_details addEmpDetails(e_details);


//This is a function to write one record to file
void e_writeFile(FILE *, e_details);
            
 
//This is a function to delete details of an employee
void deleteEmpDetails(e_details,e_node *);


//This is a function to modify employee details
void modifyEmpDetails(e_details,e_node *);


//This is a function to display employee details using Employee_id;
void e_display();


//This is a function that is used to display the ID'S of all the Employees
void e_displayID(e_node *);
