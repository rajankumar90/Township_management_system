//Definition File
//This file uses function to accept admin details from users and concept of file handling to store data in a file

#include"admin_details.h"



/*this is a function which accepts admin details such as admin_id, username and password and writes the data into the disk  */
void acceptAdminDetails(){

    admin aptr; //creating a structure variable/object to access its member variables
    int returned_value=0,valid=0,j=1,id;
    
    aptr.admin_id = autoIncrementAdmin(j); //to increment id value automatically
           id = aptr.admin_id;
           j++;
    
    
    while(getchar()!='\n');            //flushes the input buffer
    printf("\nEnter username:: ");
    fgets(aptr.username,20,stdin);    //takes username as input during run-time 
    
    //the null character is assigned to mark the end of the string i.e "username" in this case
    aptr.username[strlen(aptr.username)-1]= '\0'; 
    returned_value=usernameToValidate(aptr.username); //to check whether the entered username contains aplhabets only
    if(returned_value==0){
        
           printf("\n\t\tUsername length must not exceed 30 charcters!!!\n\t\tIt must start with an alphabet!!!\n");
           getchar();
           acceptAdminDetails(); //calls the function unless username is validated
           
     }//if
    
    
    while(getchar()!='\n');            //flushes the input buffer    
    printf("\nEnter password:: ");
    scanf("%s",aptr.password);        //takes password as input from user(admin).
    
    //to check whether user enetered password contains alphabets,digits ond alphanumeric character  
    returned_value=passwordToValidate(aptr.password); 
    if(returned_value==0){
        
           printf("\n\t\tPassword length must be more than 8!! \n\t\tPassword must conatin atleast one Uppercase,Lowecase,Digit,'@','#','$','%','&'!!\n");
           getchar();
           
           acceptAdminDetails(); //calls the function unless password is validated
           
    }//if
    
    
    //to write into the file
    FILE *fptr; //creating file pointer
    fptr=fopen("admin_details.txt","w");  //opens existing file or creates a new file if not existing
    if(fptr==NULL) {                     //if file not existing then fopen returns null
    
    
      printf("\nFile not available...");
      exit(0);
    
    }//if
    
        
        
    //writes the data of admin into the admin_details.txt    
    fprintf(fptr,"%d,%s,%s\n",aptr.admin_id,aptr.username,aptr.password);   
    
    
    fclose(fptr);  //closes the file

    adminDetailsRead(); //this function reads the data from the existing file and prints the details
    

}//acceptAdminDetails()


/*function to auto-increment id where it takes a count parameter of int type and returns it added with id value to increment id value when new data is inserted to the file*/
int autoIncrementAdmin(int count){
	FILE *fptr;
	fptr=fopen("admin_details.txt","r"); //opens and reads the existing file
	
	int id = 1000;
	admin adm; 
	
	//reads the data line by line from the existing file unless end of file is encountered
	while(fscanf(fptr,"%d,%[^,],%[^,]\n",&adm.admin_id,adm.username,adm.password)  != -1 ) //EOF = -1
	{
	        id=adm.admin_id;
	}	
	fclose(fptr);  //closes the file
	return id+count;
	
}//autoIncrementAdmin()


/*this function reads the data of admin from the txt-file and prints in the console*/
void adminDetailsRead(){

     admin aptr;
     FILE *fptr;
    
     fptr=fopen("admin_details.txt","r");  //opens existing file or creates a new file if not existing
     if(fptr==NULL) {                    //if file not existing then fopen returns null
    
    
      printf("\nFile not available...");
      exit(0);
    
    }//if
    
    
    
    
    //to read from file line by line unless EOF is encountered
    while(fscanf(fptr,"%d,%[^,],%s\n",&aptr.admin_id,aptr.username,aptr.password)!= -1){  //checks if EOF=-1
    
       printf("%d,%s,%s",aptr.admin_id,aptr.username,aptr.password);
       
    }//while
    
    
    
    
    fclose(fptr);   //closes the file

    

}//adminDetailsRead()



