/****************************
** employee_classes.cpp
** Employee Management 2
** Patrick Xie, 4/12/2011,
****************************/
#include "employee_classes.h"

//Employee Constructor
Employee::Employee(string fname, string lname, double sal){
	firstname = fname;
	lastname = lname;
	salary = sal;
}
string Employee::get_firstname() const {
	return firstname;
}
string Employee::get_lastname() const {
	return lastname;
}
double Employee::get_salary() const {
	return salary;
}
//prints statement for employees
void Employee::print(){
	cout<< firstname << " " << lastname << " is an employee who earns $" 
		<< fixed << setprecision(2) << salary << " a year.\n\n";
}

//Manager constructor derived from employee class
Manager :: Manager(string fname, string lname, double sal, string stor)
:Employee(fname, lname, sal){
	store = stor;
}
string Manager::get_store() const {
	return store;
}
//prints statement for managers
void Manager::print(){
	cout<< firstname << " " << lastname << " is the manager of the " 
		<< store << " store and earns $" <<fixed << setprecision(2) 
		<< salary << " a year.\n\n";
}

//Peon constructor derived from employee class
Peon::Peon(string fname, string lname, double sal, int hour)
:Employee(fname, lname, sal){
	hours = hour;
}
int Peon::get_hours() const{
	return hours;
}
//prints statement for peons
void Peon::print(){
	cout<< firstname << " " << lastname << " is a peon who works " 
		<< hours << " a day and earns $" << fixed << setprecision(2)
		<< salary << " a year.\n\n";
}

//Trainer constructor derived from employee class
Trainer::Trainer(string fname, string lname, double sal, string sub)
:Employee(fname, lname, sal){
	subject = sub;
}
string Trainer::get_subject() const{
	return subject;
}
//prints statement for trainers
void Trainer::print(){
	cout<< firstname << " " << lastname << " teaches " << subject 
		<< " and earns $" << fixed << setprecision(2) << salary 
		<< " a year.\n\n";
}