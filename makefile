all: menu

menu:  Township_client.o main_menu_def.o admin_login_def.o admin_details_def.o admin_details_def.o admin_menu_def.o emp_details_def.o emp_menu_def.o owner_details_def.o house_details_def.o house_owner_history_def.o validation_def.o visit_details.o visitor_details.o tenant_def.o tenant_history_def.o
	gcc main_menu.h main_menu_def.c admin_login.h admin_login_def.c admin_details.h admin_details_def.c admin_menu.h admin_menu_def.c emp_details.h emp_details_def.c emp_menu.h emp_menu_def.c owner_details.h owner_details_def.c house_details.h house_details_def.c house_owner_history.h house_owner_history_def.c visit_details.h visit_details.c visitor_details.h visitor_details.c tenant_def.c tenant.h tenant_history.h tenant_history_def.c validation.h validation_def.c Township_client.c -o menu
	
main_menu_def.o: main_menu_def.c
	gcc -c main_menu.h main_menu_def.c
	
admin_login_def.o: admin_login_def.c
	gcc -c admin_login.h admin_login_def.c
	
admin_details_def.o: admin_details_def.c
	gcc -c admin_details.h admin_details_def.c
	
admin_menu_def.o: admin_menu_def.c
	gcc -c admin_menu.h admin_menu_def.c
	
emp_details_def.o: emp_details_def.c
	gcc -c emp_details.h emp_details_def.c
         
emp_menu_def.o: emp_menu_def.c
	gcc -c emp_menu.h emp_menu_def.c  
         
owner_details_def.o: owner_details_def.c
	gcc -c owner_details.h owner_details_def.c   
         
house_details_def.o: house_details_def.c
	gcc -c house_details.h house_details_def.c 
         
house_owner_history_def.o: house_owner_history_def.c
	gcc -c house_owner_history.h house_owner_history_def.c 
	
visitor_details_def.o: visitor_details_def.c
	gcc -c visitor_details.h visitor_details_def.c	
	
visit_details_def.o: visit_details_def.c
	gcc -c visit_details.h visit_details_def.c	
	
tenant_def.o: tenant_def.c
	gcc -c tenant.h tenant_def.c
	
tenant_history_def.o: tenant_history_def.c
	gcc -c tenant_history.h tenant_history_def.c		
	
	
validation_def.o: validation_def.c
	gcc -c validation.h validation_def.c	                             
			
	
Township_client.o: Township_client.c
	gcc -c main_menu.h Township_client.c
	
	
	


	
			
