//Definition file::
//This file contains all function definitions

#include"tenant.h" //header file






/*creating a newnode for linkedlist with data(values) fetched from td(structure variable of tenant structure) */
t_node* t_createNode(t_details td){
      
      t_node *newnode = (t_node*)malloc(sizeof(t_node));
      
      newnode->t_house_no = td.t_house_no;
      newnode->t_date_of_living = td.t_date_of_living;
      newnode->t_id_pk = td.t_id_pk;
      strcpy(newnode->t_name, td.t_name);
      strcpy(newnode->t_pan_id_proof, td.t_pan_id_proof);
      
      newnode->next = NULL;
      
      return newnode;    

}//createNode()






/*adding node to linkedlist containing tenant_details
parameters: *head pointing to the first node of linkedlist , *newnode containing new record fetched from file*/
t_node* t_addNode(t_node *head,t_node *newnode){
      t_node *temp = head;
      
      //check if linked list is empty
      if(head==NULL)
            head = newnode;
      else{
            while(temp->next!=NULL)
                  temp = temp->next;
                  
            temp->next = newnode;      
      }//else
      return head;
}//addNode



/*
This is fuction that take structre as an input and its return type is void,
The main use of this fucntion is to add details to an database file "tenant_detail.txt" by taking all the inputs from the user.
*/
t_details addTenantDetails(t_details td){
      int i,ch,j=1,c_exist=0,returned_value=0;
      FILE *fptr;    
   
      fptr = fopen("tenant_details.txt","a");    //opens the file in append mode
      if(fptr == NULL){                // if no such file exist the this loop enters
      
           printf("\nCannot open file: ");
                exit(0);
      }
   
      do  //if file succesfully opened then the program start taking input     
      {
           
           
           printf("\nEnter all required details:\n");    //display statement
           
           printf("Tenant house_no : ");           //display statement
           scanf("%d",&td.t_house_no);            //taking user input for tenant id
                 
          // while(getchar()!= '\n');                  
           printf("Tenant Name : ");  //display statement
           while(getchar()!= '\n');         
           scanf("%[^\n]%*c",td.t_name);     //taking user input for tenant name
           returned_value=nameToValidate(td.t_name); 
           if(returned_value==0){
           
               
               addTenantDetails(td);
               break;
           }//if            
                      
                    
           printf("Tenant pan_id_proof: ");      //display statement
           scanf("%s",td.t_pan_id_proof);          //taking user input for pan id
           returned_value=panToValidate(td.t_pan_id_proof);
           if(returned_value==0){
           
                
                addTenantDetails(td);
                break;
           }//if  
           c_exist=tenPanIdValidation(td);
           if(c_exist==0)
           {
                             
           printf("Tenant date_of_living(dd/mm/yy) : ");      //display statement
           
           //taking user input for date of living
           scanf("%d/%d/%d",&td.t_date_of_living.day,&td.t_date_of_living.month,&td.t_date_of_living.year); 
           returned_value=dateToValidate(td.t_date_of_living.day,td.t_date_of_living.month,td.t_date_of_living.year);
           if(returned_value==0){
           
               
               addTenantDetails(td);
               break;
           }//if                 
           
	     td.t_id_pk=autoIncrementTenant(j);
	     j++;
	     fprintf(fptr,"%d,%s,%s,%d/%d/%d,%d\n",td.t_id_pk,td.t_name,td.t_pan_id_proof,td.t_date_of_living.day,td.t_date_of_living.month,td.t_date_of_living.year,td.t_house_no);  
          
           printf("if you want to enter more data select\n1=yes\n0=no\n(1/0): ");   //display statement
           scanf("%d",&ch);            //taking user input for yes or no          
          }//if
          
          else if(c_exist==1)
          {
          
            printf("\n\n\n\t\t\t\tYou are already a resident in that society!!\n");
            printf("if you want to enter more data select\n1=yes\n0=no\n(1/0): ");   //display statement
            scanf("%d",&ch);
          
          }//else if 
          
          else if(c_exist==2)
             break;
      }while(ch != 0);  //do while loop ended 
          
   	j=1;
      fclose(fptr); //closes the file opened in append mode after work is complete 
       
       
      
      return td;
      
    
    	        
}//addTenantDetails();


/*function to check whether pan id is existing or not*/
int tenPanIdValidation(t_details tds){

   t_details td;
   int exist=0;
   FILE *fptr;
   fptr = fopen("tenant_details.txt","r");    //opens the file in append mode
   if(fptr == NULL)                // if no such file exist the this loop enters
   {
         printf("\nCannot open file: ");
                exit(0);
   }
   
   
   while(fscanf(fptr,"%d,%[^,],%[^,],%d/%d/%d,%d\n",&td.t_id_pk,td.t_name,td.t_pan_id_proof,&td.t_date_of_living.day,&td.t_date_of_living.month,&td.t_date_of_living.year,&td.t_house_no)  != -1 ){ //EOF = -1
   
      //checks if person and its associated pan_id exists or not
      if(strcmp(tds.t_pan_id_proof,td.t_pan_id_proof)==0 && strcmp(td.t_name,tds.t_name)==0) {
        printf("\n\n\n\t\t\t\tPan number exists!!\n");
        exist=1;
      }//if
      else if(strcmp(tds.t_pan_id_proof,td.t_pan_id_proof)==0) //if some other person provides same pan id
      {
         printf("\n\n\n\t\t\t\tPan number is available!!\n");
         exist=2;
         break;
      }//else
   
   }
		
	fclose(fptr);
	
	return exist;
      
}//tenPanIdValidation()


/*function to auto-increment id where it takes a count parameter of int type and returns it added with id value to increment id value when new data is inserted to the file*/
int autoIncrementTenant(int count){
	FILE *fptr;
	fptr=fopen("tenant_details.txt","r");
	
	int id = 1000;
	t_details td;
	while(fscanf(fptr,"%d,%[^,],%[^,],%d/%d/%d,%d\n",&td.t_id_pk,td.t_name,td.t_pan_id_proof,&td.t_date_of_living.day,&td.t_date_of_living.month,&td.t_date_of_living.year,&td.t_house_no)  != -1 ) //EOF = -1

		id=td.t_id_pk;

	fclose(fptr);
	return id+count;
}//autoIncrementTenant()


/*This is a function that writes data(values) inside a file,
parameters:It take a FILE pointer and t_details variable */
void t_writeFile(FILE *fptr,t_details td){
      //apending new data into the file in next line  
      fprintf(fptr,"%d,%s,%s,%d/%d/%d,%d\n",td.t_id_pk,td.t_name,td.t_pan_id_proof,td.t_date_of_living.day,td.t_date_of_living.month,td.t_date_of_living.year,td.t_house_no);   

}//writeFile() 



/*  This is a display function to display all the tenant details in the database file.
This function firt opens the file the display all the content line by line present inside the file   */
void t_display(){

     char *sptr;
     FILE *fptr;
     sptr = (char*)malloc(150 * sizeof(char));
     
     fptr = fopen("tenant_details.txt" ,"r");
     if(fptr == NULL){                // if no such file exist the this loop enters
     
             printf("\nCannot open file: ");
                  exit(0);
     }//if
     
     while(fscanf(fptr,"%[^\n]%*c",sptr)!=-1){
         printf("%s\n",sptr);
     }//while
     
     fclose(fptr);
     
  
}//display()



/*This is the function we will be using to modify our data in the list*/
void modifyTenantDetails(t_details td,t_node* head)
{
      FILE *fptr;
      //node *head = NULL;
      t_node *temp = NULL;
      t_node *newnode = NULL;
      int id;
      
      fptr = fopen("tenant_details.txt","r");    //opens the file in read mode
      if(fptr == NULL){                // if no such file exist the this loop enters
      
             printf("\nCannot open file: ");
                  exit(0);
      }//if
     
      while(fscanf(fptr,"%d,%[^,],%[^,],%d/%d/%d,%d\n",&td.t_id_pk,td.t_name,td.t_pan_id_proof,&td.t_date_of_living.day,&td.t_date_of_living.month,&td.t_date_of_living.year,&td.t_house_no)  != -1 ) {//EOF = -1
        
             newnode = t_createNode(td);
             head = t_addNode(head,newnode);
      }
      
      fclose(fptr);
      
      printf("<------ Tenant ID LIST ------> \n");
      t_displayID(head);
      printf("CHOOSE WHOSE VALUE YOU WANT TO UPDATE: ");
      scanf("%d",&id);
      
      temp = head;
      if(temp == NULL){
            printf("\n\n\tLinked list is empty.........!!!!!\n");
                 exit(0);
      } //if          
      else
      {
            while(temp != NULL)
            {
                  if(id == temp->t_id_pk)
                  {
                         t_enterModifiedData(temp);
                         break;
                  }//if
                  else
                  {
                  temp = temp->next;
                  }//else
            }//while
       }//else
       
       
       
       fptr = fopen("tenant_details.txt","w");
       if(fptr == NULL){                // if no such file exist the this loop enters
       
            printf("\nCannot open file: ");
                 exit(0);
       }
       temp = head;
      
       if(temp == NULL){
             printf("\n\n\tLinked list is empty.........!!!!!\n");
                  exit(0);
       }//if
       
       else{
             while(temp != NULL){
                   fprintf(fptr,"%d,%s,%s,%d/%d/%d,%d\n",temp->t_id_pk,temp->t_name,temp->t_pan_id_proof,temp->t_date_of_living.day,temp->t_date_of_living.month,temp->t_date_of_living.year,temp->t_house_no);
                   temp=temp->next;   
             }//while
       } //else     
       fclose(fptr);
       
     
     	           
}//modifyTenantDetails()




//This is a function to delete data from the database list of tenant_details
void deleteTenantDetails(t_details td,t_node *head)
{
      FILE *fptr;
      t_node *temp = NULL, *tag = NULL, *newnode = NULL;
      int id;
      
      fptr = fopen("tenant_details.txt","r");    //opens the file in read mode
      if(fptr == NULL){                // if no such file exist the this loop enters

             printf("\nCannot open file: ");
                  exit(0);
      }//if
     
      while(fscanf(fptr,"%d,%[^,],%[^,],%d/%d/%d,%d\n",&td.t_id_pk,td.t_name,td.t_pan_id_proof,&td.t_date_of_living.day,&td.t_date_of_living.month,&td.t_date_of_living.year,&td.t_house_no)  != -1 ) //EOF = -1
      {  
             newnode = t_createNode(td);
             head = t_addNode(head,newnode);
      }
      
      fclose(fptr);
      
      
      printf("<------ Tenant ID LIST ------> \n");
      t_displayID(head);
      printf("CHOOSE WHOSE RECORDS YOU WANT TO DELETE : ");
      scanf("%d",&id);
      
      tag = temp;
      temp = head;
      
      
      if(temp == NULL){
            printf("\n\n\tLinked list is empty.........!!!!!\n");
                 exit(0);
      }//if           
      else
      {
            
            while(temp != NULL){
                  if(id == temp->t_id_pk){
                     addTenanthistory(id);
                     if(temp == head){
                           head = temp->next;
                           free(temp);
                           break;
                     }//if
                     else{
                           tag->next = temp->next;
                           free(temp);
                           break;
                     }//else         
                  }//if
                  else
                  {
                  tag = temp;
                  temp = temp->next;
                  }//else
            }//while
       }//else
       
       
       fptr = fopen("tenant_details.txt","w");
       if(fptr == NULL){                // if no such file exist the this loop enters
       
            printf("\nCannot open file: ");
                 exit(0);
       }//if
       temp = head;
      
       if(temp == NULL){
             printf("\n\n\tLinked list is empty.........!!!!!\n");
                  exit(0);
       }//if
       
       else{
             while(temp != NULL){
                   fprintf(fptr,"%d,%s,%s,%d/%d/%d,%d\n",temp->t_id_pk,temp->t_name,temp->t_pan_id_proof,temp->t_date_of_living.day,temp->t_date_of_living.month,temp->t_date_of_living.year,temp->t_house_no);
                   temp=temp->next;   
             }//while
       }//else      
       fclose(fptr);
      
       
}//deleteTenantDetails() 




void t_enterModifiedData(t_node *temp){
       t_details td;
       int choice,returned_value=0;
       
            printf("PLEASE CHOOSE FROM THE LIST WHICH DATA YOU WANT TO UPDATE\n");
   
       	    printf("1 : TENANT-NAME\n");
       	    printf("2 : TENANT-HOUSENO\n");
            printf("3 : TENANT_PAN-ID\n");
	    printf("4 : TENANT-DATE-OF-LIVING\n");
            printf("5 : BACK-TO-PREVIOUS-MENU\n");
            printf("0 : EXIT-PROGRAM\n");
       
            printf("ENTER YOUR CHOICE : ");
            scanf("%d",&choice);
            switch(choice)
            {
            	case TENANTNAMES:
                 	while(getchar()!= '\n');
                 	printf("Current Tenant Name : %s\n",temp->t_name);                  
       		 	printf("Update Tenant Name To : ");          //display statement
       		 	scanf("%[^\n]%*c",td.t_name);     //taking user input for tenant name
       		 	returned_value=nameToValidate(td.t_name); 
       		 	if(returned_value==0){
           
                           
                           t_enterModifiedData(temp);
                           break;
                        }//if 
       		 	strcpy(temp->t_name, td.t_name);
       		 	printf("\n\n\tTENANT DATA HAS BEEN UPDATED......\n");
                 	break;
                 	
                 	
            	case TENANTHOUSENOS:
            	        printf("Current Tenant House no. : %d\n",temp->t_house_no);       
                 	printf("Update Tenant House no. : ");      //display statement
                 	scanf("%d",&td.t_house_no);          //taking user input for house_no
                 	temp->t_house_no=td.t_house_no;
                 	printf("\n\n\tTENANT DATA HAS BEEN UPDATED......\n");
                	break;
                	
                	
            	case TENANTPANIDS: 
            	        printf("Current Tenant Pan id proof : %s\n",temp->t_pan_id_proof);       
                 	while(getchar()!= '\n');                  
                 	printf("Update Tenant Pan id proof : ");      //display statement
                 	scanf("%s",td.t_pan_id_proof);           //taking user input for pan id proof
                 	returned_value=panToValidate(td.t_pan_id_proof);
                 	if(returned_value==0){
           
                           
                           t_enterModifiedData(temp);
                           break;
                        }//if
                 	strcpy(temp->t_pan_id_proof, td.t_pan_id_proof);
                 	printf("\n\n\tTENANT DATA HAS BEEN UPDATED......\n");
                 	break;
                 	
                 	
     

		case TENANTSDATEOFLIVING:
			printf("Current Tenant Living date : %d/%d/%d\n",temp->t_date_of_living.day,temp->t_date_of_living.month,temp->t_date_of_living.year);       
                 	printf("Update Tenant Living date : ");     //display statement
                 	scanf("%d/%d/%d",&td.t_date_of_living.day,&td.t_date_of_living.month,&td.t_date_of_living.year);      //taking user input for living date 
                 	returned_value=dateToValidate(td.t_date_of_living.day,td.t_date_of_living.month,td.t_date_of_living.year);
                 	if(returned_value==0){
           
                           
                           t_enterModifiedData(temp);
               
                        }//if 
                 	temp->t_date_of_living = td.t_date_of_living;
                 	printf("\n\n\tTENANT DATA HAS BEEN UPDATED......\n");
                 	break;

			
		case EXITPREV:
		      getchar();
                      printf("\nPress Enter to continue...................");
                      getchar();
                      displayAdminMenu();
                      break;		
          
            	case EXITFORTENANT:
                      exit(0);
                                    
            	default:
                 	printf("INVALID CHOICE"); 
       		}//switch  
       		

                           
}//enterModifiedData()




//This function will list all the tenant names registered in the database.
void t_displayID(t_node *head){ 
      t_node *temp = head;
      if(temp == NULL){
            printf("\n\n\tNO DATA TO DISPLAY\n");
                 exit(0);
      }//if
      else{
            while(temp != NULL){
                  printf("%d\n",temp->t_id_pk);
                  temp = temp->next;
            }//while
      }//else
                        
}//displayID()



