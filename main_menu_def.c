//Definition file::
//This file contains all function definitions


#include"main_menu.h"






/*this function accepts the user choice to perform desired operations. If user chooses admin then it will direct him to admin login screen and in case of choosing employee it will direct him to employee login screen in-order to carry out further desired functionalities*/
void main_menu(){
   int choice;
   system("clear");
   printf("-----------------------------------------------------------\n");
   printf("----------------WELCOME TO THE MAIN MENU-------------------\n");
   printf("-----------------------------------------------------------\n");
   printf("\n\t\t1.ADMIN\n\n\t\t2.EMPLOYEE\n\n\t\t0.EXIT");
   printf("\n\n\t\tENTER YOUR CHOICE : ");
   scanf("%d",&choice);
   switch(choice){
        case ADMIN:                                              //here user chooses to login as admin by providing its credentials  
                 printf("\n\t\tThanks!! for choosing Admin...\n");
                 adminLogin();
                 break;           
        case EMPLOYEE:                                             //here user chooses to login as employee by providing its credentials
                 printf("\n\t\tThanks!! for choosing Employee...\n");
                 LoginScreen();
                 break;            
        case EXIT:                                                      //here user can exit from the portal by choosing this option
                 exit(0);               
        default:                                                       
                 printf("\n\t\tPlease enter a valid choice...\n");   //here user has to re-enter valid option if chosen incorrectly	         
   		 getchar();
                 printf("\nPress Enter to continue...................");
                 getchar();
                 main_menu(); //returning back to main menu
           	 break;        
   }
   
                                                     

}//main_menu();

