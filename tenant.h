//header file::
/* This is file containing function prototype, global declarations.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"validation.h"
#include "tenant_history.h"

#define EXITFORTENANT 0
#define TENANTNAMES 1
#define TENANTHOUSENOS 2
#define TENANTPANIDS 3
#define TENANTSDATEOFLIVING 4
#define EXITPREV 5

//struct for date

struct ten_Date{
    int day,month,year;
};


/*creating a structure 
In this structure we are storing one integer data which is for tenant id_pk,house no. and strings for storing t_name,t_pan_id_proof
*/
typedef struct tenant_Details
{
    char t_name[20],t_pan_id_proof[20];                // taking string inputs
    int t_house_no,t_id_pk;           //taking integer input
    struct ten_Date t_date_of_living;   

}t_details;      //giving an alternative name to the tenantDetails structure
 





//struct Linkedlist to store tenant details in a t_node
typedef struct t_LinkedList
{
     char t_name[20],t_pan_id_proof[20];               // taking string inputs
    int t_house_no,t_id_pk;           //taking integer input
    struct ten_Date t_date_of_living;   
    struct t_LinkedList *next; 
}t_node;


int tenPanIdValidation(t_details); //function to validate pan id 
int autoIncrementTenant(); //function to increment id


//This is a function for creating newnode for linkedlist
t_node* t_createNode(t_details);


//This is a function to add node to an linkedlist
t_node* t_addNode(t_node *,t_node *);


//This is a fuction that takes details that are needed to be modified by the user
void t_enterModifiedData(t_node *);




//This is a fuction used for adding tenant details
t_details addTenantDetails(t_details);


//This is a function to write one record to file
void t_writeFile(FILE *, t_details);
            
 
//This is a function to delete details of an tenant
void deleteTenantDetails(t_details,t_node *);


//This is a function to modify tenant details
void modifyTenantDetails(t_details,t_node *);


//This is a function to display tenant details using Tenant_id;
void t_display();


//This is a function that is used to display the ID'S of all the Tenant
void t_displayID(t_node *);
