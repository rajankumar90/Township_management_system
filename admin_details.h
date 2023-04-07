//header file
/* this is the file containing function prototype, global declarations */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"validation.h"    


//this is a structure which stores attributes of admin entity
typedef struct admin_details 
{

  //declaring structure(admin) member variables which are of different data types
  int admin_id;     
  char username[20];
  char password[20];

}admin;

void acceptAdminDetails(); //this function accepts admin details and stores values in a txt-file
void adminDetailsRead();  //this function reads the data of admin from the txt-file and prints the details
int autoIncrementAdmin(int); //this function automatically increments id value when new data is inserted to the file 
