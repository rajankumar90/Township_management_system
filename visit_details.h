//Visit details module
//header file
/* This is file containing function prototype, global declarations.
*/

#ifndef VISIT_DETAILS_H
#define VISIT_DETAILS_H


#include<stdio.h>
#include<string.h>
#include"visitor_details.h"
#include"validation.h"

#define ADDVISITENTRY 1
#define DISPLAYVISITENTRY 2
#define EXITVISIT 3


//struct for date

struct Date
{
    int day,month,year;
};


//This is a struct to store visit details
//This is a nested structure for date

typedef struct visit_details {
    int flat;
    char pan[20],time[20];
    
    
    struct Date visit_date;
}visit_details;

//This is fucntion to dispaly menu for the user
//void visitDetails_menu();


//This function is used to accept visit details from visitors and append it into a database file named visit_details.txt simultaneously
void addVisitEntry();


//This function is used to display the visit details
void displayVisit();

//visit main menu
void visitDetails_menu();

#endif
