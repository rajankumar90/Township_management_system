//Definition File
//This file uses switch case to create menu for admin activities

#include"admin_menu.h"



/*function to display the menu-list of admin and arrange activities/functionalities to be performed by admin by using switch-case*/
int displayAdminMenu(){

  int ch,back=0;
  o_details od;
  node *head = NULL;
  e_node *ehead = NULL;
  t_node *thead = NULL;
  t_details td;
  e_details ed;
  
  system("clear");
  printf("-------------------------------------------------------------\n");
  printf("-----------------WELCOME TO THE ADMIN MENU-------------------\n");
  printf("-------------------------------------------------------------\n");
  printf("\n\t\t1 : Add Owner Details \n\n\t\t2 : Delete Owner Details \n\n\t\t3 : Modify Owner Details \n\n\t\t4 : Display Owner Details \n\n\t\t5 : Display House Details \n\n\t\t6 : Check Visitor Details \n\n\t\t7 : Add Tenant Details \n\n\t\t8 : Delete Tenant Details \n\n\t\t9 : Modify Tenant Details \n\n\t\t10 : Display Tenant Details \n\n\t\t11 : Add Employee \n\n\t\t12 : Delete Employee \n\n\t\t13 : Modify Employee \n\n\t\t14 : Display Employee \n\n\t\t15 : Logout \n\n\t\t0 : Stop");
  
  printf("\n\n\n\t\tEnter the choice: ");
  scanf("%d",&ch); 
  
  system("clear"); //to clear screen
  
     switch(ch){
              
              case ADDOWNERDETAILSOD:  //to add owner details 
                      addOwnerDetails(od);
                      getchar();
                      printf("\nPress Enter to continue...................");
                      getchar();
                      displayAdminMenu();
                      break; 
                      
              case DELETEOWNERDETAILSOD: //to delete owner details
                      deleteOwnerDetails(od,head);
                      getchar();
                      printf("\nPress Enter to continue...................");
                      getchar();
                      displayAdminMenu();
                      break; 
                      
              case MODIFYOWNERDETAILSOD:  //to modify owner details
                      modifyOwnerDetails(od,head);
                      getchar();
                      printf("\nPress Enter to continue...................");
                      getchar();
                      displayAdminMenu();
                      break;
                      
              case DISPLAYOWNEROD:  //to display owner details
                      printf("\n----------------------------------------------------------\n");
                      printf("--------------------OWNER DETAIALS-----------------\n");
                      printf("------------------------------------------------------\n\n");
                      display();
                      getchar();
                      printf("\nPress Enter to continue...................");
                      getchar();
                      displayAdminMenu();
                      break;
                      
              case DISPLAYHOUSEOWNERHIST:  //to display house-owner history details 
                      printf("\n----------------------------------------------------------\n");
                      printf("--------------------HOUSE OWNER HISTORY-----------------\n");
                      printf("----------------------------------------------------------\n\n");
                      displayHouseOwnerHistory();
                      getchar();
                      printf("\nPress Enter to continue...................");
                      getchar();
                      displayAdminMenu();
                      break;
                           
              case CHECKVISITORDETAILVD: //to check visitor details
                      printf("\n----------------------------------------------------------\n");              
                      printf("--------------------VISITOR DETAIALS-----------------\n");
                      printf("------------------------------------------------------\n\n");              
                      v_displayVisitorDetails();
                      getchar();
                      printf("\nPress Enter to continue...................");
                      getchar();
                      displayAdminMenu();
                      break;
                                            
              case ADDTENANTDETAILSTD:       //to add tenant details       
                      addTenantDetails(td);
                      getchar();
                      printf("\nPress Enter to continue...................");
                      getchar();
                      displayAdminMenu();
                      break;
                                            
              case DELETETENANTDETAILSTD:   //to delete tenant details           
                      deleteTenantDetails(td,thead);
                      getchar();
                      printf("\nPress Enter to continue...................");
                      getchar();
                      displayAdminMenu();
                      break;          
                                  
              case MODIFYTENANTDETAILSTD:     //to modify tenant details         
                      modifyTenantDetails(td,thead);
                      getchar();
                      printf("\nPress Enter to continue...................");
                      getchar();
                      displayAdminMenu();
                      break; 
            
              case DISPLAYTENANTTD:        //to display tenant details
                      printf("\n----------------------------------------------------------\n");              
                      printf("--------------------TENANT DETAIALS-----------------\n");
                      printf("------------------------------------------------------\n\n");
                      t_display();
                      getchar();
                      printf("\nPress Enter to continue...................");
                      getchar();
                      displayAdminMenu();
                      break; 
                                 
              case ADDEMPLOYEEDETAILSED:   //to add employee details
           	      addEmpDetails(ed);
           	      getchar();
                      printf("\nPress Enter to continue...................");
                      getchar();
                      displayAdminMenu();
                      break;
                      
      	      case DELETEEMPLOYEEDETAILSED:  //to delete employee details
                      deleteEmpDetails(ed,ehead);
                      getchar();
                      printf("\nPress Enter to continue...................");
                      getchar();
                      displayAdminMenu();
                      break;
                      
              case MODIFYEMPLOYEEDETAILSED:  //to modify employee details
                      modifyEmpDetails(ed,ehead);
                      getchar();
                      printf("\nPress Enter to continue...................");
                      getchar();
                      displayAdminMenu();
           	      break;           
           	      
              case DISPLAYEMPLOYEEDETAILSED:  //to display employee details
                      printf("\n----------------------------------------------------------\n");
                      printf("--------------------EMPLOYEE DETAIALS-----------------\n");
                      printf("------------------------------------------------------\n\n");
                      e_display();
                      getchar();
                      printf("\nPress Enter to continue...................");
                      getchar();
                      displayAdminMenu();
                      break;
                                          
              case LOGOUTFROMADMIN:   //to logout from admin portal
                      back = 1;          
                      break;                      
                                   
              case STOP:          //exit from admin portal    
                      exit(0);
                                           
              default:
                      printf("\n\n\n\t\t\t\tEnter valid choice........\n");
                      getchar();
                      printf("\nt\t\tPress Enter to continue...................");
                      getchar();
                      displayAdminMenu();
           	      break;        
                      
      }//switch
      if(back == 1)
           main_menu(); //if logout option is clicked admin returns to main menu
       
      
    return back;                  

}//displayAdminMenu()



