/****************************
** employee_classes.h
** Employee Management 2
** Patrick Xie, 4/12/2011,
****************************/
#ifndef EMPLOYEE_CLASSES_H
#define EMPLOYEE_CLASSES_H

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Employee {
public:
	Employee(string fname, string lname, double sal);
	string get_firstname() const;
	string get_lastname() const;
	double get_salary() const;
	virtual void print();
protected:
	string firstname;
	string lastname;
	double salary;
};

class Manager : public Employee{
public:
	Manager(string fname, string lname, double sal, string stor);
	string get_store() const;
	virtual void print();
private:
	string store;	
};

class Peon : public Employee{
public:
	Peon(string fname, string lname, double sal, int hours);
	int get_hours() const;
	virtual void print();
private:
	int hours;
};

class Trainer : public Employee{
public:
	Trainer(string fname, string lname, double sal, string sub);
	string get_subject() const;
	virtual void print();
private:
	string subject;
};





















#endif