//Definition file
//This file contains login credentials and uses functions to check and authenticate admin

#include "admin_login.h"



/*this function defines the size of "username" and "password and calls "acceptAdminCredentials() which accepts admin credentials and checks if the admin is existing or not."*/
void adminLogin(){

    char username[20];
    char password[20];
    
    
    //to accept admin credentials and check if the admin is existing or not.
    acceptCheckAdminCredentials(username,password); 

}//adminLogin();


/*this function accepts username and password from admin for login into the portal and checks if the admin is existing or not.It takes parameter of character pointer type and returns void*/
void acceptCheckAdminCredentials(char *username, char *password) {
      
      int ch=0, success=0 ,returned_value=0, reload=0;
      //system("clear");
      
      
    
      
      
      while(ch<=2)
      {
        
	printf("-------------------------------------------------------------\n");
	printf("----------------ENTER USERNAME AND PASSWORD------------------\n");
        printf("-------------------------------------------------------------\n");
        
        while(getchar()!='\n');            //flushes the input buffer
        printf("\n\t\tUSERNAME: ");
        scanf("%s",username);
        returned_value=usernameToValidate(username); //to validate username
        if(returned_value==0){
        
           printf("\n\t\tUsername length must not exceed 30 charcters!!!\n\t\tIt must start with an alphabet!!!\n");
           getchar();
           acceptCheckAdminCredentials(username,password);
           break;
       }//if
        
        
      
   
        while(getchar()!='\n');            //flushes the input buffer
        printf("\n\t\tPASSWORD: "); 
        scanf("%s",password);         //takes password as input from user(admin).
        returned_value=passwordToValidate(password);
        if(returned_value==0){
           
           acceptCheckAdminCredentials(username,password);
           break;
        }//if
      
      
        admin ad; //creating structure object to access its member variables
        FILE *fptr; //creating file pointer
      
        if(fptr==NULL){
	   printf("\n\tFile not available.....");
	   exit(0);
		   
        }//if
      
      
      fptr=fopen("admin_details.txt","r");  //to open the existing file in read mode
      
      //to read from file line by line unless EOF is encountered
      while(fscanf(fptr,"%d,%[^,],%s",&ad.admin_id,ad.username,ad.password)!=-1){ 
      
            
      //to check if admin is authenticated or not
         if(strcmp(ad.username,username)==0 && strcmp(ad.password,password)==0){ //to compare user entered data with data stored in file
         
              success=1;
              
         }//if
         
         
      
      
      }//while-inner
      
      
      if(success==1){
      
          printf("\n\n\t\t....Login Successful... ");
          getchar();
          printf("\n\n\t\tEnter a key to continue\n");
          getchar();
          system("clear");
          displayAdminMenu();  //from menus.h
          break;
      
      }//if
      
      
      else{
           
           printf("------------------------------------------------------------------\n");
	   printf("----------------------------WARNING-------------------------------\n");
           printf("------------------------------------------------------------------\n");
        
           printf("\n\n\t\tIncorrect Username or Password!!\n");
           printf("\t\tPlease Try Again ...\n");
           getchar();
           printf("\t\tPRESS ENTER TO RETRY.........\n\n");
           getchar();
           

           
          
      }//else
      
      fclose(fptr); //closes the file
      ch++;
      
    }//while-outer
      
    if(ch>2){
      
         printf("\n\n\t\tYou have crossed the limit!! You can't login");
         getchar();
         printf("\n\t\tPRESS ENTER TO RETURN TO THE MAIN MENU..............");
         getchar();
         main_menu(); //calling main_menu if the limit has been crossed to re-enter correct credentials for login
         
      
    }//if
      
      
      
      
      
     

}//acceptAdminCredentials()
















