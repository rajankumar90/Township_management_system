//Definition file::
//This file contains all function definitions

#include"emp_details.h" //header file







//creating a newnode for linkedlist with data(values) fetched from parameter od
e_node* e_createNode(e_details ed){
      
      e_node *newnode = (e_node*)malloc(sizeof(e_node));
      
      newnode->eid_pk = ed.eid_pk;
      strcpy(newnode->emp_name, ed.emp_name);
      strcpy(newnode->email_id, ed.email_id);
      newnode->emp_phone_no = ed.emp_phone_no;
      strcpy(newnode->login_id, ed.login_id);
      strcpy(newnode->emp_password, ed.emp_password);
      
      newnode->next = NULL;
      
      return newnode;    

}//createNode()





/*adding node to linkedlist containing employee_details
parameters: *head pointing to the first node of linkedlist , *newnode containing new record fetched from file*/
e_node* e_addNode(e_node *head,e_node *newnode){
      e_node *temp = head;
      
      //check if linked list is empty
      if(head==NULL)
            head = newnode;
      else
      {
            while(temp->next!=NULL)
                  temp = temp->next;
                  
            temp->next = newnode;      
      }//else
      return head;
}//addNode





/*
This is fuction that take structre as an input and its return type is void,
The main use of this fucntion is to add details to an database file "employee_detail.txt" by taking all the inputs from the user.
*/
e_details addEmpDetails(e_details ed){
      int i,ch,j=1,returned_value=0;
      FILE *fptr;    
   
      fptr = fopen("employee_details.txt","a");    //opens the file in append mode
      if(fptr == NULL)                // if no such file exist the this loop enters
      {
           printf("\nCannot open file: ");
                exit(0);
      }
   
      do  //if file succesfully opened then the program start taking input     
      {
      
           printf("\nEnter all required details:\n");    //display statement
           
           /*printf("Employee Id : ");           //display statement
           scanf("%d",&ed.eid_pk);            //taking user input for employee id*/
           
           
           
           while(getchar()!= '\n');                  
           printf("Employee Name : ");  //display statement
           //while(getchar()!= '\n');         
           scanf("%[^\n]%*c",ed.emp_name);     //taking user input for Employee name 
           returned_value=nameToValidate(ed.emp_name);
           if(returned_value==0){
           
               
               addEmpDetails(ed);
               break;
           }//if       
                      
           while(getchar()!= '\n');          
           printf("Employee Email_id: ");      //display statement
           scanf("%s",ed.email_id);          //taking user input for email id
           returned_value=emailToValidate(ed.email_id);
           if(returned_value==0){
           
               
               addEmpDetails(ed);
               break;
           }//if 
           
           printf("Employee Phone No : ");     //display statement
           scanf("%ld",&ed.emp_phone_no);      //taking user input for phone no 
           returned_value=phoneNoToValidate(ed.emp_phone_no);
           if(returned_value==0){
           
               
               addEmpDetails(ed);
               break;
           }//if          
                    
           while(getchar()!= '\n');                  
           printf("Login Id : ");      //display statement
           scanf("%s",ed.login_id);           //taking user input for login id
           returned_value=usernameToValidate(ed.login_id);
           if(returned_value==0){
           
               
               addEmpDetails(ed);
               break;
           }//if 
           
           while(getchar()!= '\n');                  
           printf("Password : ");      //display statement
           scanf("%s",ed.emp_password);           //taking user input for password
           returned_value=passwordToValidate(ed.emp_password);
           if(returned_value==0){
           
               
               addEmpDetails(ed);
               break;
           }//if 
           
                   
           ed.eid_pk=autoIncrementEmp(j);
           j++;
           fprintf(fptr,"%d,%s,%s,%ld,%s,%s\n", ed.eid_pk, ed.emp_name, ed.email_id, ed.emp_phone_no, ed.login_id, ed.emp_password);
         
            
          
           printf("if you want to enter more data select\n1=yes\n0=no\n(1/0): ");   //display statement
           scanf("%d",&ch);            //taking user input for yes or no          
           
      }while(ch != 0);  //do while loop ended   
      j=1;
      
      fclose(fptr); //closes the file opened in append mode after work is complete      
      
     
      return ed;
                
}//addEmployeeDetails();






int autoIncrementEmp(int count)
{
	FILE *fptr;
	fptr=fopen("employee_details.txt","r");
	
	int id = 1000;
	e_details ed;
	while(fscanf(fptr,"%d,%[^,],%[^,],%ld,%[^,],%s\n",&ed.eid_pk, ed.emp_name, ed.email_id, &ed.emp_phone_no, ed.login_id, ed.emp_password)  != -1 )
	
		   id=ed.eid_pk;
		
	fclose(fptr);
	return id+count;
}




/*This is a function that writes data(values) inside a file,
parameters:It take a FILE pointer and e_details variable */
void e_writeFile(FILE *fptr,e_details ed)
{
      //apending new data into the file in next line  
      fprintf(fptr,"%d,%s,%s,%ld,%s,%s\n", ed.eid_pk, ed.emp_name, ed.email_id, ed.emp_phone_no, ed.login_id, ed.emp_password);   

}//writeFile() 



/*  This is a display function to display all the owner details in the database file.
This function firt opens the file the display all the content line by line present inside the file   */
void e_display()
{

      char *sptr;
     FILE *fptr;
     sptr = (char*)malloc(150 * sizeof(char));
     
     fptr = fopen("employee_details.txt" ,"r");
     if(fptr == NULL)                // if no such file exist the this loop enters
     {
             printf("\nCannot open file: ");
                  exit(0);
     }
     
     while(fscanf(fptr,"%[^\n]%*c",sptr)!=-1)
     {
         printf("%s\n",sptr);
     }
     
     fclose(fptr);
     
     printf("\n\nDISPLAYING DATA.................\n");   
}//e_display()



/*This is the function we will be using to modify our data in the list*/
void modifyEmpDetails(e_details ed,e_node* head)
{
      FILE *fptr;
      //node *head = NULL;
      e_node *temp = NULL;
      e_node *newnode = NULL;
      int id;
      
      fptr = fopen("employee_details.txt","r");    //opens the file in read mode
      if(fptr == NULL)                // if no such file exist the this loop enters
      {
             printf("\nCannot open file: ");
                  exit(0);
      }
     
      while(fscanf(fptr,"%d,%[^,],%[^,],%ld,%[^,],%s\n",&ed.eid_pk, ed.emp_name, ed.email_id, &ed.emp_phone_no, ed.login_id, ed.emp_password)  != -1 ) //EOF = -1
      {  
             newnode = e_createNode(ed);
             head = e_addNode(head,newnode);
      }
      
      fclose(fptr);
      
      printf("<------ Employee ID LIST ------> \n");
      e_displayID(head);
      printf("CHOOSE WHOSE VALUE YOU WANT TO UPDATE: ");
      scanf("%d",&id);
      
      temp = head;
      if(temp == NULL)
      {
            printf("\n\n\tLinked list is empty.........!!!!!\n");
                 exit(0);
      }           
      else
      {
            while(temp != NULL)
            {
                  if(id == temp->eid_pk)
                  {
                         e_enterModifiedData(temp);
                         break;
                  }
                  else
                  {
                  temp = temp->next;
                  }
            }
       }
       
       
       
       fptr = fopen("employee_details.txt","w");
       if(fptr == NULL)                // if no such file exist the this loop enters
       {
            printf("\nCannot open file: ");
                 exit(0);
       }
       temp = head;
      
       if(temp == NULL)
       {
             printf("\n\n\tLinked list is empty.........!!!!!\n");
                  exit(0);
       }
       
       else
       {
             while(temp != NULL)
             {
                   fprintf(fptr,"%d,%s,%s,%ld,%s,%s\n",temp->eid_pk, temp->emp_name, temp->email_id, temp->emp_phone_no, temp->login_id, temp->emp_password);
                   temp=temp->next;   
             }
       }      
       fclose(fptr);
       
       
              
}//modifyOwnerDetails()




//This is a function to delete data from the database list of owner_details
void deleteEmpDetails(e_details ed,e_node *head)
{
      FILE *fptr;
      e_node *temp = NULL, *tag = NULL, *newnode = NULL;
      int id;
      
      fptr = fopen("employee_details.txt","r");    //opens the file in read mode
      if(fptr == NULL)                // if no such file exist the this loop enters
      {
             printf("\nCannot open file: ");
                  exit(0);
      }
     
      while(fscanf(fptr,"%d,%[^,],%[^,],%ld,%[^,],%s\n",&ed.eid_pk, ed.emp_name, ed.email_id, &ed.emp_phone_no, ed.login_id, ed.emp_password)  != -1 ) //EOF = -1
      {  
             newnode = e_createNode(ed);
             head = e_addNode(head,newnode);
      }
      
      fclose(fptr);
      
      
      printf("<------ Employee ID LIST ------> \n");
      e_displayID(head);
      printf("CHOOSE WHOSE RECORDS YOU WANT TO DELETE : ");
      scanf("%d",&id);
      
      tag = temp;
      temp = head;
      
      
      if(temp == NULL)
      {
            printf("\n\n\tLinked list is empty.........!!!!!\n");
                 exit(0);
      }           
      else
      {
            
            while(temp != NULL)
            {
                  if(id == temp->eid_pk)
                  {
                     if(temp == head)
                     {
                           head = temp->next;
                           free(temp);
                           break;
                     }
                     else
                     {
                           tag->next = temp->next;
                           free(temp);
                           break;
                     }         
                  }
                  else
                  {
                  tag = temp;
                  temp = temp->next;
                  }
            }
       }
       
       
       fptr = fopen("employee_details.txt","w");
       if(fptr == NULL)                // if no such file exist the this loop enters
       {
            printf("\nCannot open file: ");
                 exit(0);
       }
       temp = head;
      
       if(temp == NULL)
       {
             printf("\n\n\tLinked list is empty.........!!!!!\n");
                  exit(0);
       }
       
       else
       {
             while(temp != NULL)
             {
                   fprintf(fptr,"%d,%s,%s,%ld,%s,%s\n",temp->eid_pk, temp->emp_name, temp->email_id, temp->emp_phone_no, temp->login_id, temp->emp_password);
                   temp=temp->next;   
             }
       }      
       fclose(fptr);
      
       
       
}//deleteEmpDetails() 




void e_enterModifiedData(e_node *temp)
{
       e_details ed;
       int choice,returned_value=0;
       
            printf("PLEASE CHOOSE FROM THE LIST WHICH DATA YOU WANT TO UPDATE\n");
   
       	    printf("1 : NAME OF EMPLOYEE\n");
       	    printf("2 : PASSWORD OF EMPLOYEE\n");
            printf("3 : EMAIL ID OF EMPLOYEE\n");
            printf("4 : PHONE NUMBER OF EMPLOYEE\n");
            printf("5 : BACK TO PREVIOUS MENU FROM EMPLOYEE\n");
            printf("6 : EXIT FROM EMPLOYEE\n");
       
            printf("ENTER YOUR CHOICE : ");
            scanf("%d",&choice);
            switch(choice)
            {
            	case NAMESOFEMP:
                 	while(getchar()!= '\n');
                 	printf("Current Employee Name : %s\n",temp->emp_name);                  
       		 	printf("Update Employee Name To : ");          //display statement
       		 	scanf("%[^\n]%*c",ed.emp_name);     //taking user input for owner name 
       		 	returned_value=nameToValidate(ed.emp_name);
                        if(returned_value==0){
           
                        
                        e_enterModifiedData(temp);
                        break;
                        }   
       		 	strcpy(temp->emp_name, ed.emp_name);
       		 	printf("\n\n\tEmployee DATA HAS BEEN UPDATED......\n");
                 	break;
                 	
                 	
                 	
            	case PASSWORDSOFEMP:
            	        printf("Current Employee Password : %s\n",temp->emp_password);       
                 	printf("Update Employee Password To : ");      //display statement
                 	scanf("%s",ed.emp_password);          //taking user input for password
                 	returned_value=passwordToValidate(ed.emp_password);           
                        if(returned_value==0){
           
                        
                        e_enterModifiedData(temp);
                        break;
                        }       
                 	strcpy(temp->emp_password, ed.emp_password);
                 	printf("\n\n\tOWNER DATA HAS BEEN UPDATED......\n");
                	break;
                	
                	
                	
            	case EMAILSOFEMP: 
            	        printf("Current Employee Email ID : %s\n",temp->email_id);       
                 	while(getchar()!= '\n');                  
                 	printf("Update Employee Email Id To : ");      //display statement
                 	scanf("%s",ed.email_id);           //taking user input for email id
                 	returned_value=emailToValidate(ed.email_id);
                        if(returned_value==0){
           
                        e_enterModifiedData(temp);
                        break;
                        } 
                 	strcpy(temp->email_id, ed.email_id);
                 	printf("\n\n\tEmployee DATA HAS BEEN UPDATED......\n");
                 	break;
                 	
                 	
                 	
            	case PHONENOSOFEMP:
            	        printf("Current Employee Phone Number : %ld\n",temp->emp_phone_no);       
                 	printf("Update Employee Phone Number To : ");     //display statement
                 	scanf("%ld",&ed.emp_phone_no);      //taking user input for phone no  
                 	returned_value=phoneNoToValidate(ed.emp_phone_no);
                        if(returned_value==0){
           
                        
                        e_enterModifiedData(temp);
                        break;
                        } 
                 	temp->emp_phone_no = ed.emp_phone_no;
                 	printf("\n\n\tEmployee DATA HAS BEEN UPDATED......\n");
                 	break;
                 	
                 	
                 	
            	case BACKTOPREVIOUSEMPS:
                 	getchar();
                        printf("\nPress Enter to continue...................");
                        getchar();
                        displayAdminMenu();
                 	break;          
            	case EXITFROMEMP:
                	exit(0);              
            	default:
                 	printf("INVALID CHOICE"); 
       		}   
                           
}//enterModifiedData()




//This function will list all the owner names registered in the database.
void e_displayID(e_node *head)
{ 
      e_node *temp = head;
      if(temp == NULL)
      {
            printf("\n\n\tNO DATA TO DISPLAY\n");
                 exit(0);
      }
      else
      {
            while(temp != NULL)
            {
                  printf("%d\n",temp->eid_pk);
                  temp = temp->next;
            }
      }
                        
}//displayID()



