#include"emp_menu.h"

void WelcomeTitleLogin() {//function defination inside it will call WelcomeScreen,Title,LoginScreen function

	//WelcomeScreen();  //call employee screen
	//Title();	  //call title function
	LoginScreen();	  //call LoginScreen function
}


/* ******************************Welcome Screen********************************* */
void WelcomeScreen(){  //function for welcome screen

	printf("\n\n\n\n\t\t\t\t#########################################");
	printf("\n\t\t\t\t#\t\tWELCOME TO\t\t#");
	printf("\n\t\t\t\t#     TOWNSHIP MANAGEMENT SYSTEM        #");
	printf("\n\t\t\t\t#########################################");
}


/* ******************************Title Screen********************************* */
void Title(){  ////function defination for title function

	printf("\n\n\t\t-------------------------------------------------------------------------");
	printf("\n\t\t\t\t           SUNFLOWER TOWN        ");
	printf("\n\t\t--------------------------------------------------------------------------\n");
}


/* ******************************Login Screen********************************* */
//function defination for login and registration
void LoginScreen() {

	login_register_menu();
	//call Menu function
}


void Menu() {  //menu function to choose in which field you want to visit and showing

	visitor_det visitor;
	v_node *head=NULL;
	
	int choose;  //initialising a variable to choose one option
	
	system("clear");
	printf("--------------------------------------------------------------\n");
	printf("----------------WELCOME TO THE EMPLOYEE MENU------------------\n");
        printf("--------------------------------------------------------------\n");
	printf("\n\t\t1 : LIST-VISITOR-DETAILS\n");
	printf("\n\t\t2 : ADD-VISITOR-DETAILS\n");
	printf("\n\t\t3 : MODIFY-VISITOR\n");
	printf("\n\t\t4 : ADD-VISIT-ENTRY\n");
	printf("\n\t\t5 : DISPLAY-VISIT\n");
	printf("\n\t\t6 : LIST-OWNER\n");
	printf("\n\t\t7 : LIST-TENANT\n");
	printf("\n\t\t8 : LOGOUT-EMP\n");
	printf("\n\t\t0 : EXIT-EMPLOYEE\n");
	printf("\n\t\tENTER YOUR CHOICE : "); //taking choice from user
	scanf("%d",&choose);
	printf("\n");
	switch(choose)
	{
		case LISTVISITORDETAIL:
			printf("\n--------------------VISITOR DETAIALS-----------------\n");
                        printf("------------------------------------------------------\n\n");
			v_displayVisitorDetails();
			getchar();
                        printf("\nPress Enter to continue...................");
                        getchar();
                        Menu();
			break;
			
		case ADDVISITORDETAIL:
			
			addvisitorDetails();
			getchar();
                        printf("\nPress Enter to continue...................");
                        getchar();
                        Menu();
			break;
			
		case MODIFYVISITORS:
			
			modifyvisitorDetails(visitor,head);
			getchar();
                        printf("\nPress Enter to continue...................");
                        getchar();
                        Menu();
			break;
			
		case ADDVISITENTRIES:
			
			addVisitEntry();
			getchar();
                        printf("\nPress Enter to continue...................");
                        getchar();
                        Menu();
			break;
			
		case DISPLAYVISITENTRIES:
			
			printf("\n--------------------VISIT ENTRIES-------------------\n");
                        printf("------------------------------------------------------\n\n");
			displayVisit();
			getchar();
                        printf("\nPress Enter to continue...................");
                        getchar();
                        Menu();
			break;
			
		case LISTOWNERDET:
			printf("\n--------------------OWNER DETAIALS-----------------\n");
                        printf("------------------------------------------------------\n\n");
			listOwnerdetails();		   //fuction call for ListOwner
			getchar();
                        printf("\nPress Enter to continue...................");
                        getchar();
                        Menu();
			break;
			
		case LISTTENANTDET:
			printf("\n--------------------TENANT DETAIALS-----------------\n");
                        printf("------------------------------------------------------\n\n");
		        listtenanatdetails();
		        getchar();
                        printf("\nPress Enter to continue...................");
                        getchar();
                        Menu();
			break;
			
		case LOGOUTFROMEMP:
			main_menu();		   //fuction call to Logout
			break;
			
		case EXITEMPLOYEE:
			Exit();		   //fuction call to Exit
			break;

		default:			   //for invalid entry
			printf("\t\tInvalid entry.please enter right option :)");
			getchar();
                        printf("\nPress Enter to continue...................");
                        getchar();
                        Menu();  
			
	}//switch
}//Menu()




void Exit(){  //function defination for exit function


	Title(); //calling title function
	printf("\n\n\n\t\t\t THANKYOU FOR VISITING :)\n");
	exit(0); //exit from menu
	
}




//login,register menu
void login_register_menu() { //function defination for login register menu

	int choice;   //initialising choice 
	//printf("\n\t\t   WELCOME TO LOGIN AND REGISTRATION PROCESS\n");
	system("clear");
	printf("-----------------------------------------------------------\n");
	printf("----------------CHOSE FROM THE BELOW MENU------------------\n");
        printf("-----------------------------------------------------------\n");
	printf("\n\t\t\t1 : Login\n");
	printf("\n\t\t\t2 : Register\n");
	printf("\n\t\t\t0 : Exit\n");
	printf("\n\t\t\tENTER YOUR CHOICE : ");
	//printf("\t\t\tchoose from 1 or 2:");  //taking choice from user in which field they want to go
	scanf("%d",&choice);
	switch(choice)
	{
		case LOGINEMP:
			logine();        //calling login function
			break;
		case REGISTEREMP:
			regster();	 //calling register function
			break; 
		
		case EXITEMP:
			Exit();	 //calling exit function
			break;

		default:		//for invalid entry
			printf("\t\tInvalid entry.please enter right option:)");
			getchar();
                        printf("\nPress Enter to continue...................");
                        getchar();
                        login_register_menu();  
			
	}//switch
}//login_register_menu()


void logine() {  //here the user can login by entering validate

	//system("clear");
	printf("-----------------------------------------------------------\n");
	printf("----------------WELCOME TO THE LOGIN MENU------------------\n");
        printf("-----------------------------------------------------------\n");
	
	//initialising variables
	char loginid[20];     //loginid
	char pasword[20];     //password
	int returned_value=0;
	
	// entering credentials for login
	printf("\n\t\tEnter Login ID : ");   
	scanf("%s",loginid);
	returned_value=usernameToValidate(loginid);
        if(returned_value==0){
           
               
               logine(); //calling login function 
               
        } //if
	
	printf("\n\t\tEnter Password : ");
	scanf("%s",pasword);
	returned_value=passwordToValidate(pasword);
	if(returned_value==0){
           
               
               getchar();
               logine(); //calling login function 
               
        }//if   
	
	FILE *fp;     //taken file pointer to opent the file
	fp=fopen("employee_details.txt","r");      //open file in read mode
	
	if(fp==NULL){
		printf("\n\t\t\tFile not available.....");
		   
	}//if
	
	struct Employee login;  //intialising variable for structure
	
	int v=0;//initialising variable 
	
	//read the data from the file until the EOF is not encountered
	while(fscanf(fp,"%d,%[^,],%[^,],%ld,%[^,],%s",&login.eid_pk,login.emp_name,login.email_id,&login.emp_phone_no,login.login_id,login.password)!=EOF)  {
		
		//check if user entered loginid and password are correct or not
		if((strcmp(login.login_id,loginid)==0)&&(strcmp(login.password,pasword)==0)) 
		{
			
		  		 printf("Login successful\n");
		  		 v=1;
		  		 Menu(); //calling menu function
		  		 break;
		 }//if
		
	}//while
	if (v==0){
		printf("\n\t\tINCORRECT PASSWORD\n\t\t\n\n");
		getchar();
		printf("\t\tPRESS ENTER TO RETRY...........");
		getchar();
		login_register_menu();
	}//if
	fclose(fp);//closing the file
}


//registration form
void regster(){ //Here the user can use regsitration process 

	struct Employee rgstr;  //intialising variable for structure
	int returned_value=0,id,j=1;
	//system("clear");
	printf("-----------------------------------------------------------------\n");
	printf("----------------WELCOME TO REGISTRATION PROCESS------------------\n");
        printf("-----------------------------------------------------------------\n");
	
	fflush(stdin);  //clear the buffer/stream
	
	/*taking details from user*/ 
	rgstr.eid_pk = autoIncrementEmployee(j); 
           id = rgstr.eid_pk;
           j++;
      
       
	printf("\n\t\tName: ");
	while(getchar()!='\n');
	scanf("%[^\n]s",rgstr.emp_name);
	returned_value=nameToValidate(rgstr.emp_name);
	
        if(returned_value==0)
           regster();
        
          
        
	printf("\n\t\tEmail-ID: ");
	while(getchar()!='\n');
	scanf("%s",rgstr.email_id);
	returned_value=emailToValidate(rgstr.email_id);
        if(returned_value==0)
           regster();
               
        	
	
	
  	printf("\n\t\tPhone number: ");
  	while(getchar()!='\n');
	scanf("%ld",&rgstr.emp_phone_no);
	returned_value=phoneNoToValidate(rgstr.emp_phone_no);
        if(returned_value==0){
           
               
               regster();
               
        }//if 	
	
	printf("\n\t\tUser Name To Login: ");
	while(getchar()!='\n');
	scanf("%s",rgstr.login_id);
	returned_value=usernameToValidate(rgstr.login_id);
        if(returned_value==0){
           
               
               regster(); //calling register function
              
        }//if 	
	
	printf("\n\t\tPassword: ");
	while(getchar()!='\n');
	scanf("%s",rgstr.password);
	returned_value=passwordToValidate(rgstr.password);
	if(returned_value==0){
           
               
               regster(); //calling register function
               
        } //if
	
	FILE *fp;   //opening the file
	fp = fopen("employee_details.txt","a");     //opening file ,here we can write our details which will get appended to the file
	//write the data into the file
	fprintf(fp,"%d,%s,%s,%ld,%s,%s\n",rgstr.eid_pk,rgstr.emp_name,rgstr.email_id,rgstr.emp_phone_no,rgstr.login_id,rgstr.password);
	fclose(fp);  //closing the file
	j=1;
	logine();  //calling login function
}//regester


/*function to auto-increment id where it takes a count parameter of int type and returns it added with id value to increment id value when new data is inserted to the file*/
int autoIncrementEmployee(int count)
{

        struct Employee em;  //intialising variable for structure
	FILE *fptr;
	fptr=fopen("employee_details.txt","r");
	
	int id = 1000;
	
	while(fscanf(fptr,"%d,%[^,],%[^,],%ld,%[^,],%s\n",&em.eid_pk, em.emp_name, em.email_id, &em.emp_phone_no, em.login_id, em.password)  != -1 ) //EOF = -1
        {  
             id=em.eid_pk;
        }	
	fclose(fptr);
	return id+count;
}//autoIncrementEmployee();



/*to display owner details by reading the data from owner detail file*/
void listOwnerdetails(){
     char *sptr;
     FILE *fptr;
     sptr = (char*)malloc(150 * sizeof(char));
     
     fptr = fopen("owner_details.txt" ,"r");
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
     

}//listOwnerdetails()



/*to display tenant details by reading data from tenant details file*/
void listtenanatdetails()
{
     char *sptr;
     FILE *fptr;
     sptr = (char*)malloc(150 * sizeof(char));
     
     fptr = fopen("tenant_details.txt" ,"r");
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
     

}//listtenantdetails()




