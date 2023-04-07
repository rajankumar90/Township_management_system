//header file
/* this is the file containing function prototype, global declarations */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"admin_details.h"
#include"admin_menu.h"
#include"validation.h"




/*this function defines the size of "username" and "password and calls acceptAdminCredentials() to accept the admin credentials, adminWriteCredentials() to write the data into the file and adminReadCredentials() to read data from the file*/
void adminLogin();

void acceptCheckAdminCredentials(char*,char*);//this function accepts username and password from admin for login into the portal


