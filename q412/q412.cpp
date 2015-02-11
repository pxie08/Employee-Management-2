/****************************
** employee_classes.h
** Employee Management 2
** Patrick Xie, 4/12/2011,
****************************/
#include <iostream>
#include "employee_classes.h"
#include <string>
#include <fstream>
#include <map>
#include <iomanip>
//#include <algorithm>
#include <sstream>

using namespace std;

string int_to_string(int inum){
	stringstream si; //creates stringstream
	si << inum; //adds number to stream
	return si.str(); //return value in stream in string
}
string double_to_string(double dnum){
	stringstream sd; //creates stringstream
	sd << dnum; //adds number to stream
	return sd.str(); //return value in stream in string
}

int main(){

	ifstream fin;
	string filename;
	map<string, Employee*> employee_map;
	char type;
	string fname;
	string lname;
	double sal;
	string stor;
	int hour;
	string sub;
	int response;
	int ecount;
	int scount = 0; //store count
	int subcount = 0; // subject cout
	int hcount = 0; //hours count
	int salcount = 0; //salary count

	//prompt user for file name 
	cout<< "Enter file name: ";
	cin>> filename;
	fin.open(filename.c_str());
	
	//tells user there was problem opening the text file
	if(fin.fail())
		cout<<"Fail\n\n";

	//loop that inputs different object pointers into employee_map
	while(fin >> type){
		if(type == 'E'){
			fin>> fname >> lname >> sal;
			Employee* e = new Employee(fname, lname, sal);
			employee_map[(*e).get_firstname()+(*e).get_lastname()] = e;
			//salary
			ecount = employee_map.count(double_to_string((*e).get_salary()));
			if(ecount == 1){
				salcount ++;
				employee_map[double_to_string((*e).get_salary())+int_to_string(salcount)] = e;
			}
			if(ecount == 0)
				employee_map[double_to_string((*e).get_salary())] = e;
			ecount = 0;
		}
		if(type == 'M'){
			fin >> fname >> lname >> sal >> stor;
			Manager* m = new Manager(fname, lname, sal, stor);
			employee_map[(*m).get_firstname()+(*m).get_lastname()] = m;
			//salary
			ecount = employee_map.count(double_to_string((*m).get_salary()));
			if(ecount == 1){
				salcount ++;
				employee_map[double_to_string((*m).get_salary())+int_to_string(salcount)] = m;
			}
			if(ecount == 0)
				employee_map[double_to_string((*m).get_salary())] = m;
			ecount = 0;
			//store
			ecount = employee_map.count((*m).get_store());
			if(ecount == 1){
				scount ++;
				employee_map[(*m).get_store()+int_to_string(scount)] = m;
			}
			if(ecount == 0)
				employee_map[(*m).get_store()] = m;
			ecount = 0;

		}
		if(type == 'P'){
			fin >> fname >> lname >> sal >> hour;
			Peon* p = new Peon(fname, lname, sal, hour);
			employee_map[(*p).get_firstname()+(*p).get_lastname()] = p;
			// hours
			ecount = employee_map.count((*p).get_hours());
			if(ecount == 1){
				hcount ++;
				employee_map[(*p).get_hours()+hcount] = p;
			}
			if(ecount == 0)
				employee_map[(*p).get_hours()] = p;
			ecount = 0;
		}
		if(type == 'T'){
			fin >> fname >> lname >> sal >> sub;
			Trainer* t = new Trainer(fname, lname, sal, sub);
			employee_map[(*t).get_firstname()+(*t).get_lastname()] = t;
			//subject
			ecount = employee_map.count((*t).get_subject());
			if(ecount == 1){
				subcount ++;
				employee_map[(*t).get_subject()+int_to_string(subcount)] = t;
			}
			if(ecount == 0)
				employee_map[(*t).get_subject()] = t;
			ecount = 0;
		}
	}
	do{
		cout<< "1.) Look up employee by name.\n"
			<< "2.) Look up employee by salary.\n"
			<< "3.) Look up employee by store name.\n"
			<< "4.) Look up employee by hours worked.\n"
			<< "5.) Look up employee by subject taught.\n"
			<< "6.) Quit.\n"
			<< "Enter your choice: ";
		cin >> response;
		cout<< "\n";
		switch(response){
		case 1:
			cout << "Enter name of employee: ";
			cin >> fname >> lname;
			//Assuming that user will type in a first name and last name,
			//ecount will equal to the number of objects with name the user
			//typed in. if none will tell user it does not exist.
			ecount = employee_map.count(fname+lname);
			if(ecount == 1)
				(*employee_map[fname+lname]).print();
			else
				cout<< "This name does not exist.\n\n";
			break;
		case 2:
			cout << "Enter salary of employee: ";
			cin >> sal;
			ecount = employee_map.count(double_to_string(sal));
			if(ecount == 1 && salcount == 0)
				(*employee_map[double_to_string(sal)]).print();
			if(ecount == 1 && salcount > 0){
				(*employee_map[double_to_string(sal)]).print();
				for(int i = 1 ; i <= salcount; i ++)
					(*employee_map[double_to_string(sal)+int_to_string(i)]).print();
			}
			break;
		case 3:
			cout << "Enter store name: ";
			cin >> stor;
			ecount = employee_map.count(stor);
			if(ecount == 1 && scount == 0)
				(*employee_map[stor]).print();
			if(ecount == 1 && scount > 0){
				(*employee_map[stor]).print();
				for(int i = 1 ; i <= scount; i ++)
					(*employee_map[stor+int_to_string(i)]).print();
			}
		else
			cout<< "This store does not exist.\n\n";
			break;
		case 4:
			cout << "Enter hours:";

			break;
		case 5:
			cout << "Enter subject: ";

			break;
		case 6:
			break;
		default:
			cout << "This option does not exist, please try again.\n\n";
			break;
		}
	}while(response !=6);

/*
		cout << "Enter employee name: ";
		cin >> fname >> lname;
		//Assuming that user will type in a first name and last name,
		//ecount will equal to the number of objects with name the user
		//typed in. if none will tell user it does not exist.
		
		ecount = employee_map.count(fname+lname);
		if(ecount == 1)
			(*employee_map[fname+lname]).print();
		else
			cout<< "This name does not exist.\n\n";
		

		cout << "Enter Store: ";
		cin >> stor;
		ecount = employee_map.count(stor);
		if(ecount == 1 && scount == 0)
			(*employee_map[stor]).print();
		if(ecount == 1 && scount > 0){
			(*employee_map[stor]).print();
			for(int i = 1 ; i <= scount; i ++)
				(*employee_map[stor+int_to_string(i)]).print();
		}
		else
			cout<< "This store does not exist.\n\n";


		cout << "Find another employee (y/n)? ";
		cin >> response;
	}while(response == "Y" || response == "y");
*/

	fin.close();
	return 0;
}