#include <stdio.h>
#include <string.h>

#define SSIZE 20

typedef struct {
	char name[SSIZE];
	char addr[4*SSIZE];
	char SSN[10];
	short age;
	char gender;
	char department[SSIZE];
	float salary;
} Employee;

void display_employee(Employee e){
	printf("Name = %s\nAddress = %s\nSSN = %s\nAge = %d\nGender = %c\ndepartment = %s\nsalary = %.2f\n",\
			e.name, e.addr, e.SSN, e.age, e.gender, e.department, e.salary);
}
int change_addr(Employee * e, const char *naddr){
	strcpy(e->addr, naddr);
	return 0;
}

int revise_salary(Employee* e, float nsalary){
	e->salary = nsalary;
	return 0;
}

int mod_deptmt(Employee * e, const char* ndeptmt){
	strcpy(e->department, ndeptmt);
	return 0;
}



		
int main(){
	Employee a = {"James", "1000 North 4th Street", "23432455", 22, 'm',\
		"Health", 2000.0f};
	change_addr(&a, "2000 South Road");
	display_employee(a);
}

