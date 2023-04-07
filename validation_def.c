#include"validation.h"


/*this is a function to validate name of the user where it takes a name as parameter which is of string type and checks whether the name contains only alphabets and space and returns flag as 1 if true by printing the name as valid.But, if it contains any other special or alphanumeric character flag returns false(0) with an error message. */
int nameToValidate(char *name)
{
   int i,flag=0;
   char c[100];
   
   
   
   
      i=0;
      while(name[i] != '\0')  //checks until it encounters a null character to end the string
      {
      
        if(name[i]!=' ')   //checks if a character in the string contains space
        {
          if((name[i]>='A'&& name[i]<='Z') || (name[i]>='a' && name[i]<='z'))   //checks if the character is alphabet or not
          {
             c[i]=name[i];
             flag=1;       
          }  
          
          
          
          else
          {
             
             flag=0;
             break;
          }//else
          
          
        }//if
        
        else
            c[i]+=' '; 
            
        i++;
      }//while
      
       c[i]='\0';
   
       
      
          
          if(flag==0)
              printf("\n\t\tInvalid name!!It must contain alphabets only..!!!\n");
              
          
      return flag;    
      
          
}//nameToValidate()




/*function to validate pan number by accepting pan number as argument and if the length of pan is 10 then it will enter into other check points like whether the pan number contains both alphabets and numbers at particular position  */
int panToValidate(char *pan)
{

  int i,flag=0;
  
  if(strlen(pan)!=10)  //to check if length of pan number is 10 or not
      printf("\n\t\tPlease Enter correct Pan no..\n");
      
  else
  {
  
    for(i=0; pan[i]!='\0'; i++) //loop that will run unless a null character is encountered to define end of string
    {
    
      if((i<5) || (i==9))
      {
      
        if(!isalpha(pan[i]))  //it checks whether the entered character is alphabet or not
        {
            //printf("\n\t\tIncorrect Pan number\n");
             flag=0;
             break;
             
        }//if
        
        else
            flag=1;
        
        
          
      }//if
      
      else if(i>=5 && i<9)   //it checks whether the entered character is digit or not
      {
      
         if(!isdigit(pan[i]))
         { 
             flag=0;
             //printf("\n\t\tIncorrect Pan number\n");
             break;
         }//if
         
         else
            flag=1;
         
      
      }//else if
      
      
      else
      {
         printf("\n\t\tRe-enter valid pan number\n");
         
      }//else
    
    
    }//for
    
    if(flag==0)
         printf("\n\t\tIncorrect pan number\n");  //if flag=1,then it displays the message that the entered pan number is correct
  
  }//else
  
   return flag;

}//panToValidate()




/*function to validate email of the user.It takes "email" as a string and checks if the email contains alphabet,'@','.' or not and prints valid if entered data contains these specified characters */
int emailToValidate(char *email)
{


    int i=1,checkat=0,checkdot=0,flag=0;
    if(strlen(email)>50)
        printf("\n\t\tPlease enter correct mail_id\n");
    
    else
    {
   
           if(!((email[0]>='a' && email[0]<='z') || (email[0]>='A' && email[0]<='Z')))
                printf("\n\t\tEmail_id is incorrect\n");
                
                
           else
           {
             
             //to check if '@' is present or not in the email
             while(email[i]!='\0')
             {
             
                if(email[i]=='@')
                {
                  checkat=1;
                  break;
                }
                
                else
                  i++;
             
             }
             
             
             //to check if '.' is present or not in the email
             if(checkat==1)
             {
             
             
                while(email[i]!='\0')
                {
                
                   if(email[i]=='.')
                   {
                   
                     checkdot=1;
                     break;
                   
                   }
                   else
                     i++;
                
                }//while
             
             }//if
             
             
             //checks if entered character is alphabet or digit or not
             if(checkdot==1)
             {
             
                for(; email[i]!='\0'; i++)
                {
             
              
                    if((isalpha(email[i])) || (isdigit(email[i])))
                        flag=1;
                    
                    else
                        flag=0;
                    
                }//for  
                    
            }//if
           
           
           
           
          }//else
          
             /*if(flag==1 && checkat==1 && checkdot==1)
               printf("\nValid email\n");*/
             if(flag==0)
               printf("\n\t\tInvalid email...it must contain '@' and '.'\n");    
           
             
    }//else
    
    return flag;

}//emailToValidate()



/*function to validate phone number.This function takes phone number as argument whose return type is long int. This function checks whether the entered phone number is of 10 digits or not and then checks if the phone number starts with 7,8,9 or not. */
int phoneNoToValidate(long int phone)
{
    int i=0,flag=0;
    char phone_string[11];
    sprintf(phone_string, "%ld", phone); //to convert long int to string
    
    if(strlen(phone_string)!=10)
          printf("\n\t\tPlease enter valid phone number...\n");
          
    else
    {
       if(phone_string[i]=='7' || phone_string[i]=='8' || phone_string[i]=='9')
       {
           for(i=1; phone_string[i]!='\0'; i++)
           {
              if(isdigit(phone_string[i]))
              {
                 //printf("\nvalid phone number");
                 flag=1;
              }//if
              
              else
                 flag=0;
                 
              
           }//for
           
           
           if(flag==0)
              printf("\n\t\tphone number is invalid\n");
           
           
       
       }//if
       
       
       else
          printf("\n\t\tInvalid phone number\n");       
    
    }//else
        
    return flag;

}//phoneToValidate()



/*This is a function to validate username which takes "username" as a string type argument and checks whether the username contains alphabet,digit,'@' or not.If any of them is found in the string it prints the string as valid.Moreover,the username must start with an alphabet only and returns flag value. */
int usernameToValidate(char *username)
{
   int i,flag=0;
   if(strlen(username)>30)
        printf("\n\n\t\t\t\t\tThe username is too big..\n");
        
   else
   {
      
        for(i=1; username[i]!='\0'; i++)
        {
          if(isalpha(username[0]))
          {
          
            if((isalpha(username[i])) || (isdigit(username[i])) || username[i]=='@') //to check if username contains alphabet,digit and '@'
                 flag=1;
            
          }
          
          else
              flag=0; 
                
       
          
        }//for
        
         
         
         if(flag==0)
           printf("\n\t\tInvalid username\n");
        
         
        
     
     
     
           
   }//else
   

   return flag;

}//usernameToValidate()



/*This is a function to validate password which take "password" as a string paramater and checks whether the length of the password is greater than 8 and checks if the entered password contains atleast one lowercase,uppercase,digit and alphanumeric character or not and returns flag value*/
int passwordToValidate(char *password)
{
  int i,flag=0;
  int upper_case_count=0;
  int lower_case_count=0;
  int digit_count=0,alphanumeric_count=0;
  if(strlen(password)>=8)  //checks whether the length of password is 8 or greater than 8 or not
  {
  
     for(i=0; password[i]!='\0'; i++)
     {
       if(password[i]>='a' && password[i]<='z') //checks if password contains lowercase alphabet or not and counts if found
            upper_case_count++;
            
       else if(password[i]>='A' && password[i]<='Z') //checks if password contains uppercase alphabet or not and counts if found
            lower_case_count++;
            
       else if(password[i]>='0' && password[i]<='9') //checks if password contains digit or not and counts if found
            digit_count++;
            
       //checks if password contains alphanumeric character or not and counts if found
       else if(password[i]=='@' || password[i]=='#' || password[i]=='$' || password[i]=='%' || password[i]=='&' )
            alphanumeric_count++;
            
       else
       {
           printf("\n\t\tEnter valid password\n");
           break;
       }
           
     }//for
     
     
     //checks if atleast one of every character is present or not
     if(upper_case_count >0 && lower_case_count >0 && digit_count >0 && alphanumeric_count >0) 
        flag=1;
        
     else
        flag=0;
     
     
         
     if(flag==0)
         printf("\n\t\tPassword must contain a uppercase, lowercase, digit and alphanumeric character\n");
  
  }//if
  
  else
     printf("\n\t\tPassword must be of minimum 8 characters\n");
     
   return flag;  
  

}//passwordToValidate()



/*This is a function which takes "id" as integer parameter to check if the length of the id is 4 or not*/
int idToValidate(int id)
{
   int flag=0;
   char idString[5];
   sprintf(idString,"%d",id); //converts id of int type to string type
   if(strlen(idString)==4) //checks if the length of id is 4 or not
      flag=1;
      
   else
      flag=0;
   
   
     
   if(flag==0)
     printf("\n\t\tPlease enter valid id\n");
   
   return flag;
    
}//idToValidate()

/*function to validate date which takes date,month,year as integer parameters and checks whether user entered date is in the format of dd/mm/yyyy or not and if the entered date,month,year are valid or not*/
int dateToValidate(int date,int month,int year)
{
  
     int check_odd_month=0,check_even_month=0,check_leap_month=0,flag=0;
     
     if((year >= 1900 && year <=9999) || (month >= 1 && month <=12))
     {
  
        //checks if the odd numbered months ends with 31 days or not 
        if((date >=1 && date <=31) && (month ==1 || month ==3 || month ==5 || month ==7 || month ==8 || month ==10 || month ==12))
           check_odd_month=1;
          
           
        //checks if the even numbered months(except February) ends with 30 days or not    
        else if((date >=1 && date <=30) && (month == 4 || month == 6 || month == 9 || month == 11)) 
           check_even_month=1; 
         
         //checks if February ends with 28 days(in case of normal years) or 29 days(in case of leap years)  
        else if((date == 28 || date == 29) && (month == 2))
           check_leap_month=1;
           
        else
           printf("\n\t\tInValid date\n");
     }
              
     if(check_odd_month==1 || check_even_month==1 || check_leap_month==1)
         flag=1; //if condition is true increments flag by 1
         
     else 
         flag=0;
         
         
     
     if(flag==0)
         printf("\n\t\tPlease!! enter valid date\n");
         
     
    return flag;
  
}//dateToValidate()
