//Definition file::
//This file contains all function definitions


#include"owner_details.h" //header file




//creating a newnode for linkedlist with data fetched from parameter od
node* createNode(o_details od) {
      
      node *newnode = (node*)malloc(sizeof(node));              //allocating dynamic memory to the node
      
      //add all the data inside the node using the values passed from o_details structure
      strcpy(newnode->owner_name, od.owner_name);
      newnode->owner_id = od.owner_id;
      strcpy(newnode->pan_id, od.pan_id);
      strcpy(newnode->email_id, od.email_id);
      newnode->phone_no = od.phone_no;
      newnode->next = NULL;
      
      return newnode;       //returning node            

}//createNode()






/*adding node to linkedlist containing owner_details
parameters: *head pointing to the first node of linkedlist , *newnode containing new record fetched from file*/
node* addNode(node *head,node *newnode) {

      node *temp = head;        //assigning a temporary the adress of the head node so it can iterate
      
      //check if linked list is empty
      if(head==NULL)
            head = newnode;      //if linkedlist is empty head new node becomes the head node
      else {
            while(temp->next!=NULL)              //condition till temp reaches the last node
                  temp = temp->next;
                  
            temp->next = newnode;      
      }//else
      
      return head;      //returning head
      
}//addNode







/*
This is fuction that take structre as an input and its return type is void,
The main use of this fucntion is to add details to an database file "owner_detail.txt" by taking all the inputs from the user.
*/
o_details addOwnerDetails(o_details od) {

      int ch,j=1,id,c_exist=0,returned_value=0;  
      FILE *fptr;    
   
      fptr = fopen("owner_details.txt","a");    //opens the file in append mode
      if(fptr == NULL) {               // if no such file exist the this loop enters
           printf("\nCannot open file: ");
                exit(0);
      }//if
   
      do { //if file succesfully opened then the program start taking input     
      
           printf("\nEnter all required details:\n");    //display statement
           
           od.owner_id = autoIncrementowner(j);        //creating id for new owner using autoincrement function
           id = od.owner_id;
           j++;
                 
           while(getchar()!= '\n');             //flush statement     
           printf("Owner's Name : ");          //display statement
           scanf("%[^\n]%*c",od.owner_name);     //taking user input for owner name 
           returned_value=nameToValidate(od.owner_name);
           
           if(returned_value==0) {
           
                addOwnerDetails(od);
                break;
           }//if            
                    
           printf("Owner's Pan Id : ");      //display statement
           scanf("%s",od.pan_id);          //taking user input for pan id
           returned_value=panToValidate(od.pan_id);
           
           if(returned_value==0) {
           
                addOwnerDetails(od);
                break;
           }//if
             
           c_exist=panIdValidation(od);
           if(c_exist==0) {
                      
           printf("Owner's Email Id : ");      //display statement
           scanf("%s",od.email_id);           //taking user input for email id
           returned_value=emailToValidate(od.email_id);
           
           if(returned_value==0) {
           
                addOwnerDetails(od);
                break;
           }//if  
           
                    
           printf("Owner's Phone No : ");     //display statement
           scanf("%ld",&od.phone_no);      //taking user input for phone no 
           returned_value=phoneNoToValidate(od.phone_no);
            
           if(returned_value==0) {
           
                addOwnerDetails(od);
                break;
           }//if        
          
           //apending new data into the file in next line
           writeFile(fptr,od);  
           
           modifyHouseDetails(id);
          
           printf("if you want to enter more data select\n1=yes\n0=no\n(1/0): ");   //display statement
           scanf("%d",&ch);            //taking user input for yes or no          
           }//if
          
           else if(c_exist==1) {
          
           	printf("if you want to enter more data select\n1=yes\n0=no\n(1/0): ");   //display statement
           	scanf("%d",&ch);            //taking user input for yes or no
           }//else if
          
           else if(c_exist==2)
                break;
                
      }while(ch != 0);  //do while loop ended     
   
      fclose(fptr); //closes the file opened in append mode after work is complete      
      j=1;
      
      return od;
          
}//addOwnerDetails();




/*function to check whether pan id is existing or not*/
int panIdValidation(o_details pd) {

   o_details od;
   int exist=0;
   FILE *fptr;
   fptr = fopen("owner_details.txt","r");    //opens the file in append mode
   if(fptr == NULL) {               // if no such file exist the this loop enters

       printf("\nCannot open file: ");
       exit(0);
   }//if
   
   while(fscanf(fptr,"%d,%[^,],%[^,],%[^,],%ld\n",&od.owner_id, od.owner_name, od.pan_id, od.email_id, &od.phone_no) != -1 ) { //EOF = -1
   
	 if(strcmp(pd.pan_id,od.pan_id)==0 && strcmp(pd.owner_name,od.owner_name)==0) {
	 
	   printf("\n\n\n\t\t\t\tPan Id exists for this owner\n");
	   modifyHouseDetails(od.owner_id);
	   //pd.owner_id=od.owner_id;
	   /*pd.owner_name=od.owner_name;
	   
	   pd.pan_id=od.pan_id;*/
	   exist=1;
	   
	 }//if  
	 else if(strcmp(pd.pan_id,od.pan_id)==0){
	   printf("\n\n\b\t\t\t\tPan is already available\n");
	   exist=2;
	   break;
	 }//else if  
   }//while	
	fclose(fptr); 
	
	return exist;
      
}//panIdValidation()




/*function to auto-increment id where it takes a count parameter of int type and returns it added with id value to increment id value when new data is inserted to the file*/
int autoIncrementowner(int count)
{
	FILE *fptr;
	fptr=fopen("owner_details.txt","r");
	
	int id = 1000;
	o_details od;
	while(fscanf(fptr,"%d,%[^,],%[^,],%[^,],%ld\n",&od.owner_id, od.owner_name, od.pan_id, od.email_id, &od.phone_no)  != -1 ){ //EOF = -1
	
	        id=od.owner_id;
	}//while	
	fclose(fptr);
	return id+count;
}//autoIncrementowner();






/*This is a function that writes data(values) inside a file,
parameters:It take a FILE pointer and o_details variable */
void writeFile(FILE *fptr,o_details od){
      //apending new data into the file in next line  
      fprintf(fptr,"%d,%s,%s,%s,%ld\n", od.owner_id, od.owner_name, od.pan_id, od.email_id, od.phone_no);   

}//writeFile() 






/*  This is a display function to display all the owner details in the database file.
This function firt opens the file the display all the content line by line present inside the file   */
void display(){

     char *sptr;
     FILE *fptr;
     sptr = (char*)malloc(150 * sizeof(char));
     
     fptr = fopen("owner_details.txt" ,"r");
     if(fptr == NULL) {               // if no such file exist the this loop enters
     
             printf("\nCannot open file: ");
                  exit(0);
     }//if
     
     while(fscanf(fptr,"%[^\n]%*c",sptr)!=-1){
         printf("%s\n",sptr);
     }//while
     
     fclose(fptr);
      
     
}//display()





/*This is the function we will be using to modify our data in the list*/
void modifyOwnerDetails(o_details od,node* head)
{
      FILE *fptr;
      //node *head = NULL;
      node *temp = NULL;
      node *newnode = NULL;
      int id;
      
      fptr = fopen("owner_details.txt","r");    //opens the file in read mode
      if(fptr == NULL) {               // if no such file exist the this loop enters
      
             printf("\nCannot open file: ");
                  exit(0);
      }//if
     
      while(fscanf(fptr,"%d,%[^,],%[^,],%[^,],%ld\n",&od.owner_id, od.owner_name, od.pan_id, od.email_id, &od.phone_no)  != -1 ){ //EOF = -1
        
             newnode = createNode(od);
             head = addNode(head,newnode);
      }//while
      
      fclose(fptr);
      
      printf("<------ OWNER'S ID LIST ------> \n");
      displayID(head);
      printf("\nCHOOSE WHOSE VALUE YOU WANT TO UPDATE: ");
      scanf("%d",&id);
      
      temp = head;
      if(temp == NULL){
            printf("\n\n\tNO DATA TO MODIFY.........!!!!!\n");
                 exit(0);
      } //if          
      else{
            while(temp != NULL){
                  if(id == temp->owner_id){
                         enterModifiedData(temp);
                         break;
                  }//if
                  else{
                  temp = temp->next;
                  }//else
            }//while
       }//else
       
       
       
       fptr = fopen("owner_details.txt","w");
       if(fptr == NULL) {               // if no such file exist the this loop enters
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
                   fprintf(fptr,"%d,%s,%s,%s,%ld\n",temp->owner_id,  temp->owner_name, temp->pan_id, temp->email_id, temp->phone_no);
                   temp=temp->next;   
             }//while
       } //else     
       fclose(fptr);
       
         
}//modifyOwnerDetails()









//This is a function to delete data from the database list of owner_details
void deleteOwnerDetails(o_details od,node *head)
{
      FILE *fptr;
      node *temp = NULL, *tag = NULL, *newnode = NULL;
      int id,house_id;
      char hohname[20];
      
      fptr = fopen("owner_details.txt","r");    //opens the file in read mode
      if(fptr == NULL)                // if no such file exist the this loop enters
      {
             printf("\nCannot open file: ");
                  exit(0);
      }
     
      while(fscanf(fptr,"%d,%[^,],%[^,],%[^,],%ld\n",&od.owner_id, od.owner_name, od.pan_id, od.email_id, &od.phone_no)  != -1 ) //EOF = -1
      {  
             newnode = createNode(od);
             head = addNode(head,newnode);
      }
      
      fclose(fptr);
      
      
      printf("<------ OWNER'S ID LIST ------> \n");
      displayID(head);
      printf("\nCHOOSE WHOSE RECORDS YOU WANT TO DELETE : \n");
      scanf("%d",&id);
      
      tag = temp;
      temp = head;
      
      
      if(temp == NULL)
      {
            printf("\n\n\tNo data to delete.........!!!!!\n");
                 exit(0);
      }           
      else
      {
            
            while(temp != NULL)
            {
                  if(id == temp->owner_id)
                  {
                     strcpy(hohname,temp->owner_name);
                     house_id = deleteHouseDetails(id);
                     addhousehistory(id,hohname,house_id);
                     
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
       
       
       fptr = fopen("owner_details.txt","w");
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
                   fprintf(fptr,"%d,%s,%s,%s,%ld\n",temp->owner_id, temp->owner_name, temp->pan_id, temp->email_id, temp->phone_no);
                   temp=temp->next;   
             }
       }      
       fclose(fptr);
       
       
       
}//deleteOwnerDetails() 






/*function which uses switch case to prompt user to choose which data he/she wants to modify*/
void enterModifiedData(node *temp)
{
       o_details od;
       int choice,returned_value=0;
       
            printf("PLEASE CHOOSE FROM THE LIST WHICH DATA YOU WANT TO UPDATE\n");
   
       	    printf("1:NAME OF OWNER\n");
       	    printf("2:PANID OF OWNER\n");
            printf("3:EMAIL ID OF OWNER\n");
            printf("4:PHONE NUMBER OWNER\n");
            printf("5:BACK TO PREVIOUS MENU FROM OWNER\n");
            printf("0:EXIT PROGRAM\n");
       
            printf("ENTER YOUR CHOICE : ");
            scanf("%d",&choice);
            printf("\n");
            switch(choice)
            {
            	case NAMEOWNER:
                 	while(getchar()!= '\n');
                 	printf("Current Owner's Name : %s\n",temp->owner_name);                  
       		 	printf("Update Owner's Name To : ");          //display statement
       		 	scanf("%[^\n]%*c",od.owner_name);     //taking user input for owner name
       		 	returned_value=nameToValidate(od.owner_name); 
       		 	if(returned_value==0){
           
                        
                            enterModifiedData(temp);
                            break;
                        }   
       		 	strcpy(temp->owner_name, od.owner_name);
       		 	printf("\n\n\tOWNER DATA HAS BEEN UPDATED......\n");
                 	break;
                 	
            	case PANIDOWNER:
            	        printf("Current Owner's Pan Id : %s\n",temp->pan_id);       
                 	printf("Update Owner's Pan Id To : ");      //display statement
                 	scanf("%s",od.pan_id);          //taking user input for pan id
                 	returned_value=panToValidate(od.pan_id);
                 	if(returned_value==0){
           
                        
                            enterModifiedData(temp);
                            break;
                        }   
                 	strcpy(temp->pan_id, od.pan_id);
                 	printf("\n\n\tOWNER DATA HAS BEEN UPDATED......\n");
                	break;
                	
            	case EMAILIDOWNER: 
            	        printf("Current Owner's Email ID : %s\n",temp->email_id);       
                 	while(getchar()!= '\n');                  
                 	printf("Update Owner's Email Id To : ");      //display statement
                 	scanf("%s",od.email_id);           //taking user input for email id
                 	returned_value=emailToValidate(od.email_id);
                 	if(returned_value==0){
           
                        
                            enterModifiedData(temp);
                            break;
                         } 
                 	strcpy(temp->email_id, od.email_id);
                 	printf("\n\n\tOWNER DATA HAS BEEN UPDATED......\n");
                 	break;
                 	
            	case PHONENUMBEROWNER:
            	        printf("Current Owner's Phone Number : %ld\n",temp->phone_no);       
                 	printf("Update Owner's Phone Number To : ");     //display statement
                 	scanf("%ld",&od.phone_no);      //taking user input for phone no 
                 	returned_value=phoneNoToValidate(od.phone_no); 
                 	if(returned_value==0){
           
                        
                            enterModifiedData(temp);
                            break;
                        } 
                 	temp->phone_no = od.phone_no;
                 	printf("\n\n\tOWNER DATA HAS BEEN UPDATED......\n");
                 	break;
                 	
            	case BACKTOPREVIOUSMENUFROMOWNER:
                        getchar();
                        printf("\nPress Enter to continue...................");
                        getchar();
                        displayAdminMenu();
                 	break;
                 	          
            	case EXITFROMOWNER:
                	exit(0);              
            	default:
                 	printf("INVALID CHOICE"); 
       		}   
                           
}//enterModifiedData()






//This function will list all the owner names registered in the database.
void displayID(node *head)
{ 
      node *temp = head;
      if(temp == NULL)
      {
            printf("\n\n\tNO DATA TO DISPLAY\n");
                 exit(0);
      }
      else
      {
            while(temp != NULL)
            {
                  printf("%d\n",temp->owner_id);
                  temp = temp->next;
            }
      }
                        
}//displayID()
























