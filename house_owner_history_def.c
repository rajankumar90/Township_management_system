//Definition file::
//This file contains all function definitions


#include "house_owner_history.h" 




/*function definition for adding house owner history in the database
prameter: it takes two parameters one for taking the id of the the previous owner and one for taking the name of the previous owner*/
void addhousehistory(int id, char name[],int house_id){
      
      FILE *fptr;
      hoh hd;    
      int returned_value=0;
      fptr = fopen("house_owner_history.txt","a");    //opens the file in append mode
      if(fptr == NULL) {               // if no such file exist the this loop enters
      
           printf("\nCannot open file: ");
                exit(0);
      }//if
   
           //storing data in the structue from the parameters
           hd.previous_owner_id =id;
           strcpy(hd.name_of_prev_owner, name);
           
           
           hd.house_id = house_id;
           
                      
           printf("Enter staying from,(dd/mm/yyyy) : ");
           scanf("%d/%d/%d", &hd.staying_from.day, &hd.staying_from.month, &hd.staying_from.year);
           returned_value=dateToValidate(hd.staying_from.day,hd.staying_from.month,hd.staying_from.year);
           if(returned_value==0){
           
               
               addhousehistory(id,name,house_id);
               
           } //if
           
           printf("Enter stayed_till,(dd/mm/yyyy) : ");
           scanf("%d/%d/%d", &hd.staying_till.day, &hd.staying_till.month, &hd.staying_till.year);
           returned_value=dateToValidate(hd.staying_till.day, hd.staying_till.month, hd.staying_till.year);
           if(returned_value==0){
           
               
               addhousehistory(id,name,house_id);
               
           } //if
           
       
          
           //apending new data into the file in next line
           fprintf(fptr,"%d,%s,%d,%d/%d/%d,%d/%d/%d\n", hd.previous_owner_id, hd.name_of_prev_owner, hd.house_id, hd.staying_from.day, hd.staying_from.month, hd.staying_from.year, hd.staying_till.day, hd.staying_till.month, hd.staying_till.year);    
             
          
        //do while loop ended     
   
      fclose(fptr); //closes the file opened in append mode after work is complete      
      
          
}//addOwnerDetails();






//function definiton to display all the data available in the house_owner_detail.txt file
void displayHouseOwnerHistory(){

     char *sptr;
     FILE *fptr;
     sptr = (char*)malloc(200 * sizeof(char));
     
     fptr = fopen("house_owner_history.txt" ,"r");
     if(fptr == NULL){                // if no such file exist the this loop enters
             printf("\nCannot open file: ");
                  exit(0);
     }//if
     
     while(fscanf(fptr,"%[^\n]%*c",sptr)!=-1){
         printf("%s\n",sptr);
     }//while
     
     fclose(fptr);
     
        
}//display()






