//header file::
/* This is file containing function prototype, global declarations.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"house_owner_history.h"
#include"house_details.h"
#include"validation.h"

#define EXITAPPLICATIONFOROWNER 0
#define ADDOWNERDETAIL 1
#define MODIFYOWNERDETAIL 2
#define DELETEOWNERDETAIL 3
#define DISPLAYOWNERDETAIL 4
#define DISPLAYLINKEDLISTS 5

#define EXITFROMOWNER 0
#define NAMEOWNER 1
#define PANIDOWNER 2
#define EMAILIDOWNER 3
#define PHONENUMBEROWNER 4
#define BACKTOPREVIOUSMENUFROMOWNER 5


/*creating a structure 
In this structure we are storing one integer data which is for owner id, one long interger for storing the phone number
and three strings for storing email id , ownner name and pan id 
*/
typedef struct ownerDetails{
    int owner_id;           //taking integer input
    long int phone_no;       //taking long integer input
    char email_id[50], owner_name[20], pan_id[20];   // taking string inputs
    
}o_details;      //giving an alternative name to the ownerDetails structure
 





//struct Linkedlist to store ownner details in a node
typedef struct LinkedList{
    int owner_id;           //taking integer input
    long int phone_no;       //taking long integer input
    char email_id[50], owner_name[20], pan_id[20];   // taking string inputs
    struct LinkedList *next; 
}node;

int panIdValidation(o_details); //to validate pan details 

int autoIncrementowner(int); //to autoincrement id of owner

//This is a function for creating newnode for linkedlist
node* createNode(o_details);


//This is a function to add node to an linkedlist
node* addNode(node *,node *);



//This is a fuction that takes details that are needed to be modified by the user
void enterModifiedData(node *);




//This is a fuction used for entering house owner details data inside our database file
o_details addOwnerDetails(o_details);


//This is a function to write one record to file
void writeFile(FILE *, o_details);
            
 
//This is a function to delete house owner details inside our database file
void deleteOwnerDetails(o_details,node *);


//This is a function to modify house owner details inside our database file
void modifyOwnerDetails(o_details,node *);


//This is a function to display house owner details using owner_id;
void display();


//This is a function that is used to display the ID'S of all the owners
void displayID(node *);
