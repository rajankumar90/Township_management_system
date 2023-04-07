//header file::
/* This is file containing function prototype, global declarations.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>




/*creating a structure 
In this structure we are storing one integer data which is for resident id, house_id and house type
*/
typedef struct houseDetails{
    int house_id;           //taking integer input
    char avl[3],house_type[12];
    int resident_id;       //taking integer input
    
    //struct LinkedList *next; 
    
}h_details;      //giving an alternative name to the houseDetails structure
 



//struct Linkedlist to store house details in a node
typedef struct housedetLinkedList{
    int house_id;           //taking integer input
    char avl[3],house_type[12];
    int resident_id;       //taking integer input
    
    struct housedetLinkedList *next; 
}h_node;



//This function is for the allotment data how many houses owner has
void fixedHouseData();

int autoIncrementhousedetails(int count); //to auto-increment house id

//This is a function for creating newnode for linkedlist
h_node* hd_createNode(h_details);


//This is a function to add node to an linkedlist
h_node* hd_addNode(h_node *,h_node *);


//This is fucntion to dispaly menu for the user
void house_menu();


//This is a fuction used for entering house details data inside our database file
h_details addHouseDetails(h_details);

void displayNSHouse(h_node *); //to display the houses which are not sold

void displaySHouse(h_node *); //to display the houses which are sold
 
//This is a function to delete house details inside our database file
int deleteHouseDetails(int);


//This is a function to modify house details inside our database file
void modifyHouseDetails(int);


//This is a function to display house details using resident_id;
void displayhd(h_details);

