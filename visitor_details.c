//Definition file::
//This file contains all function definitions


#include "visitor_details.h" //header file


//menu for visitor details
void visitorDetails_menu() {
    visitor_det visitor;
    v_node *head=NULL;
    int choice = 0;

    system("clear");
    printf("<--:MENU:-->\n");
    printf("\n\n\n\n\n\t\t\t1:ADD-VISITOR-DETAILS\n");
    printf("\t\t\t2:MODIFY-VISITOR-DETAILS\n");
    printf("\t\t\t3:LIST-VISITOR-DETAILS\n");
    printf("\t\t\t0:EXIT-FROM-VISITOR-APPLICATION\n");

    printf("ENTER YOUR CHOICE.\n");
    scanf("%d", &choice);
    switch (choice) {
        case ADDVISITORSDETAILS:
             addvisitorDetails();
             break;
      case MODIFYVISITORSDETAILS:
             modifyvisitorDetails(visitor,head);
             break;
      case LISTVISITORSDETAILS:
             v_displayVisitorDetails();
             break;
      case EXITVISITORMENU:
             return;              
      default:
             printf("INVALID CHOICE");    

    }

}//visitor_menu()







//creating a newnode for linkedlist with data(values) fetched from parameter visitor
v_node *v_createNode(visitor_det visitor) {

    v_node *newnode = (v_node *) malloc(sizeof(v_node));

    strcpy(newnode->visitor_name, visitor.visitor_name);
    strcpy(newnode->pan_id, visitor.pan_id);
    strcpy(newnode->email_id, visitor.email_id);
    newnode->phone_no = visitor.phone_no;
    newnode->next = NULL;

    return newnode;

}//createNode()






/*adding node to linkedlist containing visitor_details
parameters: *head pointing to the first node of linkedlist , *newnode containing new record fetched from file*/
v_node *v_addNode(v_node *head, v_node *newnode) {
    v_node *temp = head;

    //check if linked list is empty
    if (head == NULL)
        head = newnode;
    else {
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
    }
    return head;
}//addNode






//function to display all the value stored in linkedlist
void v_displaylinkedList(v_node *head) {
    v_node *temp = head;

    if (temp == NULL)
        printf("\n\n\tLinked list is empty.........!!!!!\n");
    else {
        while (temp != NULL) {
            printf("%s,%s,%s,%ld\n", temp->visitor_name, temp->pan_id, temp->email_id, temp->phone_no);
            temp = temp->next;
        }
    }

}//displaylinkedList()






/*
This is fuction that take structre as an input and its return type is void,
The main use of this fucntion is to add details to an database file "visitor_detail.txt" by taking all the inputs from the user.
*/
void addvisitorDetails() {
    visitor_det visitor;
    int ch,returned_value=0;
    FILE *fptr;

    fptr = fopen("visitor_details.txt", "a");    //opens the file in append mode
    if (fptr == NULL)                // if no such file exist the this loop enters
    {
        printf("\nCannot open file: ");
        return;
    }

    do  //if file succesfully opened then the program start taking input
    {

        printf("\nEnter all required details:\n");    //display statement

        while (getchar() != '\n');
        printf("Visitor's Name : ");          //display statement
        scanf("%[^\n]%*c", visitor.visitor_name);     //taking user input for visitor name
        returned_value=nameToValidate(visitor.visitor_name);
        if(returned_value==0){
           
             
             addvisitorDetails();
             break;
        } 

        while (getchar() != '\n');
        printf("Visitor's Pan Id : ");      //display statement
        scanf("%s", visitor.pan_id);          //taking user input for pan id
        returned_value=panToValidate(visitor.pan_id);
        if(returned_value==0){
           
            
            addvisitorDetails();
            break;            
        }  

        while (getchar() != '\n');
        printf("Visitor's Email Id : ");      //display statement
        scanf("%s", visitor.email_id);           //taking user input for email id
        returned_value=emailToValidate(visitor.email_id);
        if(returned_value==0){
           
            
            addvisitorDetails();
            break;
        } 

        printf("Visitor's Phone No : ");     //display statement
        scanf("%ld", &visitor.phone_no);      //taking user input for phone no
        returned_value=phoneNoToValidate(visitor.phone_no);
        if(returned_value==0){
           
             
             addvisitorDetails();
             break;
        } 

        //apending new data into the file in next line
        v_writeFile(fptr, visitor);

        printf("if you want to enter more data select\n1=yes\n0=no\n(1/0): ");   //display statement
        scanf("%d", &ch);            //taking user input for yes or no

    } while (ch != 0);  //do while loop ended

    
    fclose(fptr); //closes the file opened in append mode after work is complete
    
}//addvisitorDetails();






/*This is a function that writes data(values) inside a file,
parameters:It take a FILE pointer and o_details variable */
void v_writeFile(FILE * fptr, visitor_det visitor) {

    //apending new data into the file in next line
    fprintf(fptr, "%s,%s,%s,%ld\n", visitor.visitor_name, visitor.pan_id, visitor.email_id, visitor.phone_no);

}//writeFile() 






/*  This is a display function to display all the visitor details in the database file.
This function firt opens the file the display all the content line by line present inside the file   */
void v_displayVisitorDetails() {
    
     char *sptr;
     FILE *fptr;
     sptr = (char*)malloc(150 * sizeof(char));
     
     fptr = fopen("visitor_details.txt" ,"r");
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

}//display()





/*This is the function we will be using to modify our data in the list*/
void modifyvisitorDetails(visitor_det visitor,v_node *head) {
    

    FILE *fptr;
    v_node *temp = NULL;
    v_node *newnode = NULL;
    char pan[20];
    int returned_value=0;
    fptr = fopen("visitor_details.txt", "r");    //opens the file in read mode
    if (fptr == NULL)                // if no such file exist the this loop enters
    {
        printf("\nCannot open file: ");
        return;
    }

    while (fscanf(fptr, "%[^,],%[^,],%[^,],%ld\n", visitor.visitor_name, visitor.pan_id, visitor.email_id,
                  &visitor.phone_no) != -1) //EOF = -1
    {
        newnode = v_createNode(visitor);
        head = v_addNode(head, newnode);
    }

    fclose(fptr);

    printf("<------ VISITOR'S PAN ID LIST ------> \n");
    displayPan(head);
    printf("CHOOSE WHOSE VALUE YOU WANT TO UPDATE: ");
    scanf("%s", pan);
    returned_value=panToValidate(pan);
    if(returned_value==0){
           
        
        modifyvisitorDetails(visitor,head);
    } 


    temp = head;

    if (temp == NULL) {
        printf("\n\n\tLinked list is empty.........!!!!!\n");
        return;
    } else {
        while (temp != NULL) {
            if (strcmp(temp->pan_id, pan) == 0) {
                v_enterModifiedData(temp);
                break;
            } else {
                temp = temp->next;
            }
        }
    }


    fptr = fopen("visitor_details.txt", "w");
    if (fptr == NULL)                // if no such file exist the this loop enters
    {
        printf("\nCannot open file: ");
        return;
    }
    temp = head;

    if (temp == NULL) {
        printf("\n\n\tLinked list is empty.........!!!!!\n");
        return;
    } else {
        while (temp != NULL) {
            fprintf(fptr, "%s,%s,%s,%ld\n", temp->visitor_name, temp->pan_id, temp->email_id, temp->phone_no);
            temp = temp->next;
        }
    }
    fclose(fptr);
    
}//modifyVisitorDetails()





void v_enterModifiedData(v_node *temp) {
    visitor_det visitor;
    int choice,returned_value=0;

    printf("PLEASE CHOOSE FROM THE LIST WHICH DATA YOU WANT TO UPDATE\n");

    
    printf("\n\n\n\n\t\t\t\t1:  NAME\n");
    printf("\t\t\t\t2 :EMAIL ID\n");
    printf("\t\t\t\t3 :PHONE NUMBER\n");
    printf("\t\t\t\t4: BACK TO PREVIOUS MENU\n");
    printf("\t\t\t\t5: EXIT\n\n");

    printf("ENTER YOUR CHOICE : ");
    scanf("%d", &choice);
    switch (choice) {
        case NAMEVISITOR:
            while (getchar() != '\n');
            printf("Current Visitor's Name : %s\n", temp->visitor_name);
            printf("Update Visitor's Name To : ");          //display statement
            scanf("%[^\n]%*c", visitor.visitor_name);     //taking user input for visitor name
            returned_value=nameToValidate(visitor.visitor_name);
            if(returned_value==0){
           
               
               v_enterModifiedData(temp);
               break;
            } 
            strcpy(temp->visitor_name, visitor.visitor_name);
            printf("\n\n\tVISITOR DATA HAS BEEN UPDATED......\n");
            break;
            
            
        case EMAILIDVISITOR:
            printf("Current Visitor's Email ID : %s\n", temp->email_id);
            while (getchar() != '\n');
            printf("Update Visitor's Email Id To : ");      //display statement
            scanf("%s", visitor.email_id);           //taking user input for email id
            returned_value=emailToValidate(visitor.email_id);
            if(returned_value==0){
           
               
               v_enterModifiedData(temp);
               break;
           } 
            strcpy(temp->email_id, visitor.email_id);
            printf("\n\n\tVISITOR DATA HAS BEEN UPDATED......\n");
            break;
            
            
        case PHONENUMBERVISITOR:
            printf("Current Visitor's Phone Number : %ld\n", temp->phone_no);
            printf("Update Visitor's Phone Number To : ");     //display statement
            scanf("%ld", &visitor.phone_no);      //taking user input for phone no
            returned_value=phoneNoToValidate(visitor.phone_no);
            if(returned_value==0){
           
               
               v_enterModifiedData(temp);
               break;
           }
            temp->phone_no = visitor.phone_no;
            printf("\n\n\tVISITOR DATA HAS BEEN UPDATED......\n");
            break;
            
            
        case BACKTOPREVIOUSMENUFROMVISITOR:
            visitorDetails_menu();
            break;
            
            
        case EXITFROMVISITOR:
            return;
            
        default:
            printf("INVALID CHOICE");
    }

}//enterModifiedData()






//This function will list all the visitor names registered in the database.
void displayPan(v_node *head) {
    v_node *temp = head;
    if (temp == NULL) {
        printf("\n\n\tNO DATA TO DISPLAY\n");
        return;
    } else {
        while (temp != NULL) {
            printf("%s\n", temp->pan_id);
            temp = temp->next;
        }
    }

}//displayPan()

























