//header file
/* this is the file containing function prototype, global declarations */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"owner_details.h" 
#include "emp_details.h"
#include "visitor_details.h"
#include "tenant.h"


#define STOP 0
#define ADDOWNERDETAILSOD 1
#define DELETEOWNERDETAILSOD 2
#define MODIFYOWNERDETAILSOD 3
#define DISPLAYOWNEROD 4
#define DISPLAYHOUSEOWNERHIST 5
#define CHECKVISITORDETAILVD 6
#define ADDTENANTDETAILSTD 7
#define DELETETENANTDETAILSTD 8
#define MODIFYTENANTDETAILSTD 9
#define DISPLAYTENANTTD 10
#define ADDEMPLOYEEDETAILSED 11
#define DELETEEMPLOYEEDETAILSED 12
#define MODIFYEMPLOYEEDETAILSED 13
#define DISPLAYEMPLOYEEDETAILSED 14
#define LOGOUTFROMADMIN 15




int displayAdminMenu(); //function to display the menu-list of admin to choose which operation has to be performed

