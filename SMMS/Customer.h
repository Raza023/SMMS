#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED
#include<string>
#include<iostream>
using namespace std;
class Customer
{
private:
	string name;
	string contact_no;

public:
	
	Customer();
	bool setname(string nam);
	bool setcontact_no(string cont_no);
	string getname();
	string getcontact_no();
	~Customer();
};

#endif // CUSTOMER_H_INCLUDED
