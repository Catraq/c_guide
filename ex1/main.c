#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define EMPLOYEE_INFO_NAME_MAX_LENGTH 255


struct employee_info
{
	uint8_t 	name[EMPLOYEE_INFO_NAME_MAX_LENGTH];
      	uint32_t 	salary;	

};


int 
employee_info_submit(struct employee_info *p)
{
	printf("Emplyee name: ");
	fgets(p->name, EMPLOYEE_INFO_NAME_MAX_LENGTH, stdin);
	p->name[strcspn(p->name, "\n")] = 0;

	printf("Emplyee salary: ");
	int result = scanf("%d", &p->salary);
	if(result != 1){
		return -1;	
	}

	return 0;
}

void
employee_info_display(struct employee_info *p)
{
	printf("Employee name: %s \n", p->name);
	printf("Employee salary: %u \n", p->salary);
}


int main(int args, char *argv[])
{
	struct employee_info employee;
	int result = employee_info_submit(&employee);
	if(result < 0)
	{
		printf("Failed parsing employee info. \n");
		return -1;
	}

	employee_info_display(&employee);


	return 0;
}
