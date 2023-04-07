//header file::
// This is file containing function prototype, global declarations.


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"validation.h"

//struct for date

struct t_Date
{
    int day,month,year;
};


//creating a structure 


typedef struct Ten_Details
{
    int t_id_fk;                      //taking integer input	
    int t_leave_time;                // taking string inputs
    struct t_Date t_staying_from;
    struct t_Date t_staying_till;   

}tdetails;      //giving an alternative name to the tenantDetails structure
 




//function declaration for adding the house history to the tenant history list
void addTenanthistory(int);





//function declaration for displaying all the data stroed in tenant history database
void displayTenantHistory();



