#include <iostream>
#include <string>
#include"Customer.h"
using namespace std;
Customer::Customer()
{
	name = "";
	contact_no = "";
}
bool Customer::setname(string nam)
{
	int count = 0;
	if (nam == "" || nam[0] == ' ')
	{
		return false;
	}
	else 
	{
		for (int i = 0; i < nam.length(); i++)
		{
			if (nam[i] >= 97 && nam[i] <= 122)
			{
				nam[i] -= 32;
			}
		}

		for (int i = 0; i < nam.length(); i++)
		{
			if ((nam[i] >= 'A' && nam[i] <= 'Z') || (nam[i] >= 'a' && nam[i] <= 'z') || (nam[i] == ' '))
			{
				count++;
			}
			else 
			{
				return false;
			}
		}
		if (count == nam.length())
		{
			name = nam;
			return true;
		}
		else 
		{
			return false;
		}
	}
}
	

bool Customer::setcontact_no(string cont_no)
{
	int count = 0;
	if (cont_no == "" || cont_no.length() != 11)
	{
		return false;
	}
	else {
		for (int i = 0; i < cont_no.length(); i++)
		{
			if ((cont_no[i] >= '0' && cont_no[i] <= '9'))
			{
				count++;
			}
			else {
				return false;
			}
		}
		if (count == 11)
		{
			contact_no = cont_no;
			return true;
		}
		else {
			return false;
		}
	}
}
string Customer::getname()
{
	return name;
}
string Customer::getcontact_no()
{
	return contact_no;
}
Customer::~Customer()
{
	name = "";
	contact_no = "";
}
