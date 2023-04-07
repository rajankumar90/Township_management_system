//header file::
/* This is file containing function prototype, global declarations.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"validation.h"




//creating a structure that will store the date in day,month and year format 
struct Date_House{
    int day,month,year;
};





//creating a structure that will store all the data related to house onwer history
typedef struct house_owner_details{
              
    int previous_owner_id, house_id; 
    char name_of_prev_owner[20];   // taking string inputs
    struct Date_House staying_from;
    struct Date_House staying_till;
    
}hoh;      //giving an alternative name to the ownerDetails structure
 




//function declaration for adding the house history to the house owner history list
void addhousehistory(int, char[],int);





//function declaration for displaying all the data stroed in house owner histroy database
void displayHouseOwnerHistory();





