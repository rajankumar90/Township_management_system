//header file::
/* This is file containing function prototype, global declarations.
*/

#ifndef VISITOR_DETAILS_H
#define VISITOR_DETAILS_H


#define ADDVISITORSDETAILS 1
#define MODIFYVISITORSDETAILS 2
#define LISTVISITORSDETAILS 3
#define EXITVISITORMENU 4


#define NAMEVISITOR 1
#define EMAILIDVISITOR 2
#define PHONENUMBERVISITOR 3
#define BACKTOPREVIOUSMENUFROMVISITOR 4
#define EXITFROMVISITOR 5

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"validation.h"




/*creating a structure 
In this structure we are storing one long integer for storing the phone number
and three strings for storing email id , visitor name and pan id 
*/
typedef struct visitor_det
{
    long int phone_no;       //taking long integer input
    char email_id[50], visitor_name[20], pan_id[20];   // taking string inputs
    
}visitor_det;      //giving an alternative name to the  Visitor Details structure
 





//struct Linkedlist to store visitor details in a node
typedef struct v_node
{
    long int phone_no;       //taking long integer input
    char email_id[50], visitor_name[20], pan_id[20];   // taking string inputs
    struct v_node *next;
}v_node;





//This is a function for creating newnode for linkedlist
v_node* v_createNode(visitor_det);


//This is a function to add node to an linkedlist
v_node* v_addNode(v_node *,v_node *);


//This is the display function for linkedlist
void v_displaylinkedList(v_node *);

//This is a fuction that takes details that are needed to be modified by the user
void v_enterModifiedData(v_node *);



//This is fucntion to display menu for the user
void visitorDetails_menu();


//This is a fuction used for entering visitor details data inside our database file
void addvisitorDetails();


//This is a function to write one record to the file
void v_writeFile(FILE *, visitor_det);
            

//This is a function to modify visitor details inside our database file
void modifyvisitorDetails(visitor_det,v_node *);


//This is a function to display visitor details using pan_id;
void v_displayVisitorDetails();


//This is a function that is used to display the Pan ID'S of all the visitors.
void displayPan(v_node *);

#endif
