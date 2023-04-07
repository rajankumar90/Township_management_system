//definition file
//This file contains all function definitions


#include "visit_details.h"             //header file





//This function is accepting pan details from the user and checking it to compare in the visitor details database file and further asks the user to enter visit details as well. It then appends the data in visit details file.
//If the pan details of the user do not exist in the dataabase then it asks the user to first enter the visitor details data from the user and appends it to the visitor database

void addVisitEntry() {
    visit_details visit;
    visitor_det v;
    int exist = 0,returned_value=0;
    char pan[20];
    FILE *fp;

    printf("Enter PAN of the visitor: ");
    scanf("%s", pan);
    returned_value=panToValidate(pan);
    if(returned_value==0){
           
        
        addVisitEntry();
    } 

    fp = fopen("visitor_details.txt","r");                                  //opening the visitor_details file in read mode
    if (fp == NULL) {
        fp = fopen("visitor_details.txt", "w");
        fclose(fp);
        fp = fopen("visitor_details.txt", "r");
    }

    while (fscanf(fp, "%[^,],%[^,],%[^,],%ld", v.visitor_name, v.pan_id, v.email_id, &v.phone_no) != -1) {
        if (strcmp(pan, v.pan_id) ==0) {                 //comparing pan entered by user with the data in the database file
            exist = 1;
            break;
        }
    }
    fclose(fp);                                                             //closing the file opened in read mode

    if (exist ==0) {                                                     //if the pan entered by the user do not exist in the database file
        printf("Your details do not exist in our visitor details database.\nPlease add visitor details first\n");     //display statement
        addvisitorDetails(v);                                         //calling this function to add visitor details in the database first
    }
    
    fp = fopen("visit_details.txt", "a");                                //opening visit details file in append mode



    printf("\nPlease enter your visit Details:: \n");                    //display statement

    printf("Enter flat number: ");                                        //display statement
    scanf("%d",&visit.flat);                                             //taking user input for the flat number he wants to visit in
    
    
    printf("Enter visit_date(dd/mm/yyyy):: ");
    scanf("%d/%d/%d", &visit.visit_date.day, &visit.visit_date.month,&visit.visit_date.year);      //taking user input for date of visit
    returned_value=dateToValidate(visit.visit_date.day,visit.visit_date.month,visit.visit_date.year);
    if(returned_value==0){
           
        
        addVisitEntry();
               
    } 
    
    printf("Enter visit time: ");
    scanf("%s", visit.time);                                             //taking user input for time of visit

    printf("\nDetails added successfully!!!\n");


    //appending the data into the visit_details file
    fprintf(fp, "%d,%s,%d/%d/%d,%s\n", visit.flat, pan, visit.visit_date.day, visit.visit_date.month,
            visit.visit_date.year, visit.time);

    fclose(fp);                         //closing the file
    
    
   /* getchar();
    printf("\nPress Enter to continue...................");
    getchar();
    Menu(); */

}


//This function is used to display all the visit details
void displayVisit() {
    visit_details visit;
    FILE *fp;

    fp = fopen("visit_details.txt", "r");                                     //opening the file in read mode
    if (fp == NULL) {
        fp = fopen("visit_details.txt", "w");
        fclose(fp);
        fp = fopen("visit_details.txt", "r");
    }

    while (fscanf(fp, "%d,%[^,],%d/%d/%d,%[^\n]", &visit.flat, visit.pan, &visit.visit_date.day,
                  &visit.visit_date.month, &visit.visit_date.year, visit.time) != -1) {
        //reading the data into the file
        printf("%d,%s,%d/%d/%d,%s\n", visit.flat, visit.pan, visit.visit_date.day, visit.visit_date.month,
               visit.visit_date.year, visit.time);

    }

    fclose(fp);                                                                 //closing the file opened in read mode
}
