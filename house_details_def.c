//Definition file::
//This file contains all function definitions

#include"house_details.h" //header file


//it is a function that is used to crete a list of house data for the houses present in the township
void fixedHouseData(){
    FILE *fptr;
    fptr = fopen("house_details.txt","w");
    int i=1,j=1;
    while(i<=15)
    {
         fprintf(fptr,"%d,NS,FLAT,%d\n",100+i,0);    //entering data using loop for flat
         i++;
    }
    while(j<=10)
    {
        fprintf(fptr,"%d,NS,ROW HOUSE,%d\n",115+j,0);   //entering data using loop for row house
        j++;
    }
    fclose(fptr);

}//fixedHouseData()


//creating a newnode for linkedlist with data(values) fetched from parameter hd
h_node* hd_createNode(h_details hd){
      
      h_node *newnode = (h_node*)malloc(sizeof(h_node));            //allocating memory to the node
      
      //adding data inside the node passed from h_details structure
      newnode->house_id = hd.house_id;
      strcpy(newnode->avl,hd.avl);
      strcpy(newnode->house_type, hd.house_type);
      newnode->resident_id = hd.resident_id;
      
      newnode->next = NULL;
      
      return newnode;    //returning node

}//createNode()



/*adding node to linkedlist containing house_details
parameters: *head pointing to the first node of linkedlist , *newnode containing new record fetched from file*/
h_node* hd_addNode(h_node *head,h_node *newnode){
      h_node *temp = head;                //declaring a temporary node pointer
      
      //check if linked list is empty
      if(head==NULL)
            head = newnode;
      else
      {
            while(temp->next!=NULL)          //iterating till the last node
                  temp = temp->next;
                  
            temp->next = newnode;      
      }
      return head;
}//addNode



/*
This is fuction that take structre as an input and its return type is void,
The main use of this fucntion is to add details to an database file "house_detail.txt" by taking all the inputs from the user.
*/
h_details addHouseDetails(h_details hd){
      int i,ch,op,j=1;
      FILE *hptr;    
   
      hptr = fopen("house_details.txt","a");    //opens the file in append mode
      if(hptr == NULL){                // if no such file exist the this loop enters
      
           
                exit(0);
      }//if
      printf("press 1 to reset all house data \n");
      printf("press 2 to Add new House details \n");
      printf("Enter choice");
      scanf("%d",&op);
      switch(op)
      {
            case 1:
                  fixedHouseData();
                  break;
                  
            case 2:
                  do  //if file succesfully opened then the program start taking input     
      		  {
      
           		printf("\nEnter all required details:\n");    //display statement
                   
           		hd.house_id = autoIncrementhousedetails(j);
           		j++;
           
           		strcpy(hd.avl,"NS");
           	  
           		while(getchar()!= '\n');          
           		printf("HOUSE TYPE(FLAT/ROW HOUSE) : ");      //display statement
           		scanf("%[^\n]%*c",hd.house_type);          //taking user input for house type
                     
                        hd.resident_id = 0;
                     
           	        //apending new data into the file in next line
           		fprintf(hptr,"%d,%s,%s,%d\n", hd.house_id, hd.avl, hd.house_type, hd.resident_id);    
          
           		printf("if you want to enter more data select\n1=yes\n0=no\n(1/0): ");   //display statement
           		scanf("%d",&ch);            //taking user input for yes or no          
          
                  }while(ch != 0);  //do while loop ended
                  j=1;
                  break;
                  
              default:
                  printf("Enter valid choice");                          
      }//switch
      
      
   
     
      fclose(hptr); //closes the file opened in append mode after work is complete      
      
      return hd;
          
}//addHouseDetails();





/*function to increment house id automatically. It takes a "count parameter of integer type and returns id value to the function"*/
int autoIncrementhousedetails(int count){
	FILE *fptr;
	fptr=fopen("house_details.txt","r");
	
	int id = 100;
	h_details hd;
	while(fscanf(fptr,"%d,%[^,],%[^,],%d\n", &hd.house_id, hd.avl, hd.house_type, &hd.resident_id) != -1)
	{
		   id=hd.house_id;
	}	
	fclose(fptr);
	return id+count;
}//autoIncrementhousedetails()







/*  This is a display function to display all the house details in the database file.
This function first opens the file the display all the content line by line present inside the file   */
void displayhd(h_details hd){

      FILE *hptr;
     
      hptr = fopen("house_details.txt","r");    //opens the file in read mode
      if(hptr == NULL)                // if no such file exist the this loop enters
      {
             printf("\nCannot open file: ");
                  exit(0);
      }
     
      while(fscanf(hptr,"%d,%[^,],%[^,],%d\n",&hd.house_id, hd.avl, hd.house_type, &hd.resident_id)  != -1 ) //EOF = -1
      {  
             printf("%d,%s,%s,%d\n",hd.house_id, hd.avl, hd.house_type, hd.resident_id);
      }
      
      
      fclose(hptr);
        
}//display()








/*This is the function we will be using to modify our data in the list*/
void modifyHouseDetails(int resident_id){
      FILE *hptr;
      h_details hd;
      h_node* head = NULL;
      h_node *temp = NULL;
      h_node *newnode = NULL;
      int id;
      
      hptr = fopen("house_details.txt","r");    //opens the file in read mode
      if(hptr == NULL){                // if no such file exist the this loop enters
             printf("\nCannot open file: ");
                  exit(0);
      }//if
     
      while(fscanf(hptr,"%d,%[^,],%[^,],%d\n", &hd.house_id, hd.avl, hd.house_type, &hd.resident_id) != -1){
        
             newnode = hd_createNode(hd);
             head = hd_addNode(head,newnode);
      }//while
      
      fclose(hptr);
      
      printf("<------ AVAILABLE HOUSE LIST ------> \n");
      displayNSHouse(head);
      printf("CHOOSE HOUSE FOR UPDATING OWNER DETAILS: ");
      scanf("%d",&id);
      
      temp = head;
      if(temp == NULL){
            printf("\n\n\tNO DATA FOUND....!!!!!!!\n");
                 exit(0);
      } //if          
      else
      {
            while(temp != NULL)
            {
                  if(id == temp->house_id)
                  {
                         temp->resident_id = resident_id;
                         strcpy(temp->avl,"S");
                         break;
                  }//if
                  else
                  {
                  temp = temp->next;
                  }//else
            }//while
       }//else
       
       
       hptr = fopen("house_details.txt","w");
       if(hptr == NULL){                // if no such file exist the this loop enters
       
            printf("\nCannot open file: ");
                 exit(0);
       }//if
       temp = head;
      
       if(temp == NULL){
       
             printf("\n\n\tNo Data found.........!!!!!\n");
                  exit(0);
       }//if
       
       else{
             while(temp != NULL){
                   fprintf(hptr,"%d,%s,%s,%d\n",temp->house_id, temp->avl, temp->house_type, temp->resident_id); 
                   temp=temp->next;   
             }//while
       } //else     
       fclose(hptr);
              
}//modifyHouseDetails()




/*to display the houses which are not sold. This function takes head pointer as argument to the function and returns void*/
void displayNSHouse(h_node *head){
  h_node *temp = head;
      if(temp == NULL)
      {
            printf("\n\n\tNO DATA TO DISPLAY\n");
                 exit(0);
      }
      else
      {
            while(temp != NULL)
            { 
                  if(strcmp(temp->avl,"NS")==0)
                  {
                  printf("%d\n",temp->house_id);
                  }
                  temp = temp->next;
            }
      }      
}//displayNSHouse();


/*to display the houses which are sold. This function takes head pointer as argument to the function and returns void*/
void displaySHouse(h_node *head){
  h_node *temp = head;
      if(temp == NULL)
      {
            printf("\n\n\tNO DATA TO DISPLAY\n");
                 exit(0);
      }
      else
      {
            while(temp != NULL)
            { 
                  if(strcmp(temp->avl,"S")==0)
                  {
                  printf("%d\n",temp->house_id);
                  }
                  temp = temp->next;
            }
      }      
}//displaySHouse();










//This is a function to delete data from the database list of house_details
int deleteHouseDetails(int id){
      FILE *hptr;
      int dhid;
      h_details hd;
      h_node* head = NULL;
      h_node *temp = NULL, *tag = NULL, *newnode = NULL;
      
      
      hptr = fopen("house_details.txt","r");    //opens the file in read mode
      if(hptr == NULL)                // if no such file exist the this loop enters
      {
             printf("\nCannot open file: ");
                  exit(0);
      }
     
      while(fscanf(hptr,"%d,%[^,],%[^,],%d\n", &hd.house_id, hd.avl, hd.house_type, &hd.resident_id) != -1)
      {  
             newnode = hd_createNode(hd);
             head = hd_addNode(head,newnode);
      }
      
      fclose(hptr);
      
     
      
      tag = temp;
      temp = head;
      
      
      if(temp == NULL)
      {
            printf("\n\n\tLinked list is empty.........!!!!!\n");
                 exit(0);
      }//if           
      else
      {
            
            while(temp != NULL)
            {
                  if(id == temp->resident_id)
                  {
                     temp->resident_id = 0;
                     strcpy(temp->avl,"NS");
                     dhid = temp->house_id;
                  }//if
                  else
                  {
                  tag = temp;
                  temp = temp->next;
                  }//else
            }//while
       }//else
       
       
       hptr = fopen("house_details.txt","w");
       if(hptr == NULL){                // if no such file exist the this loop enters
            printf("\nCannot open file: ");
                 exit(0);
       }//if
       temp = head;
      
       if(temp == NULL){
             printf("\n\n\tNO DATA FOUND...........!!!!!\n");
                  exit(0);
       }//if
       
       else{
             while(temp != NULL)
             {
                   fprintf(hptr,"%d,%s,%s,%d\n",temp->house_id, temp->avl, temp->house_type, temp->resident_id); 
                   temp=temp->next;      
             }
       }//if      
       fclose(hptr);
      
      return dhid; 
}//deleteHouseDetails() 

