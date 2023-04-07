
//Definition file::
//This file contains all function definitions


#include "tenant_history.h" 




/*function definition for adding tenant history in the database
prameter: it takes two parameters */
void addTenanthistory(int id)
{
     	 
      FILE *fptr;
      tdetails td;    
      int returned_value=0;
      fptr = fopen("tenant_history.txt","a");    //opens the file in append mode
      if(fptr == NULL)                // if no such file exist the this loop enters
      {
           printf("\nCannot open file: ");
                exit(0);
      }
   	

           //storing data in the structue from the parameters
	     td.t_id_fk = id;

           //td.t_leave_time;
           
           //td.t_id_fk = t_id_fk;   
   	    
	   printf("Enter leave time : ");
           scanf("%d",&td.t_leave_time);

           printf("Enter staying from,(dd/mm/yyyy) : ");
           scanf("%d/%d/%d", &td.t_staying_from.day, &td.t_staying_from.month, &td.t_staying_from.year);
           returned_value=dateToValidate(td.t_staying_from.day,td.t_staying_from.month, td.t_staying_from.year);
           if(returned_value==0){
           
               
               addTenanthistory(id);
               
           } 
           
           
           printf("Enter stayed_till,(dd/mm/yyyy) : ");
           scanf("%d/%d/%d", &td.t_staying_till.day, &td.t_staying_till.month, &td.t_staying_till.year);
           returned_value=dateToValidate(td.t_staying_till.day, td.t_staying_till.month, td.t_staying_till.year);
           if(returned_value==0){
           
               
               addTenanthistory(id);
               
           } 
           
           
             
          
           //apending new data into the file in next line
           fprintf(fptr,"%d,%d,%d/%d/%d,%d/%d/%d\n",td.t_id_fk,td.t_leave_time,td.t_staying_from.day, td.t_staying_from.month, td.t_staying_from.year, td.t_staying_till.day, td.t_staying_till.month, td.t_staying_till.year);    
             
          
        //do while loop ended     
   
      fclose(fptr); //closes the file opened in append mode after work is complete      
      
          
}//addTenantDetails();






//function definiton to display all the data available in the tenant_history.txt file
void displayTenantHistory()
{

      FILE *fptr;  //opening the file pointer
      tdetails td;      //creating a structure variable
     
      fptr = fopen("tenant_history.txt","r");    //opens the file in append mode
      if(fptr == NULL)                // if no such file exist the this loop enters
      {
             printf("\nCannot open file: ");
                  exit(0);
      }
     
     
      //reading all the data from the file line by line.      
      while(fscanf(fptr,"%d,%d,%d/%d/%d,%d/%d/%d\n",&td.t_id_fk, &td.t_leave_time, &td.t_staying_from.day, &td.t_staying_from.month, &td.t_staying_from.year, &td.t_staying_till.day, &td.t_staying_till.month, &td.t_staying_till.year)  != -1 ) //EOF = -1
      {  
      
             //printing all the data from the database 
             printf("%d,%d,%d/%d/%d,%d/%d/%d\n",td.t_id_fk,td.t_leave_time,td.t_staying_from.day, td.t_staying_from.month, td.t_staying_from.year, td.t_staying_till.day, td.t_staying_till.month, td.t_staying_till.year);
      }
      
      
      fclose(fptr);  //closing opened file 
        
}//display()
