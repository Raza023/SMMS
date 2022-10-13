#include "Admin.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;


Admin::Admin()
{
	Name = "";
	admin_id = "";
	strcpy(password, "");////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	contact_no = "";
	position = "";
}
bool Admin::set_name(string name)
{
	int count = 0;
	if (name == "" || name[0] == ' ')
	{
		return false;
	}
	else 
	{
		for (int i = 0; i < name.length(); i++)
		{
			if (name[i] >= 97 && name[i] <= 122)
			{
				name[i] -= 32;
			}
		}

		for (int i = 0; i < name.length(); i++)
		{
			if ((name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= 'a' && name[i] <= 'z') || (name[i] == ' '))
			{
				count++;
			}
			else 
			{
				return false;
			}
		}
		if (count == name.length())
		{
			Name = name;
			return true;
		}
		else 
		{
			return false;
		}
	}
}
bool Admin::set_admin_id(string id)
{
	if (id == "")
	{
		return false;
	}
	else
	{
		admin_id = id;
		return true;
	}
}
bool Admin::set_password(const char* pass)
{
	if (pass == NULL)
	{
		return false;
	}
	else
	{
		int i = 0;
		for (i = 0; i < 10 && pass[i] != '\0'; i++)
		{
			password[i] = pass[i];
		}
		password[i] = '\0';
		return true;
	}
}
bool Admin::set_contact_no(string c_no)
{
	int count = 0;
	if (c_no == "" || c_no.length() != 11)
	{
		return false;
	}
	else 
	{
		for (int i = 0; i < c_no.length(); i++)
		{
			if ((c_no[i] >= '0' && c_no[i] <= '9'))
			{
				count++;
			}
			else 
			{
				return false;
			}
		}
		if (count == 11)
		{
			contact_no = c_no;
			return true;
		}
		else 
		{
			return false;
		}
	}
}
bool Admin::set_position(string pos)
{
	int count = 0;
	if (pos == "" || pos[0] == ' ')
	{
		return false;
	}
	else 
	{
		for (int i = 0; i < pos.length(); i++)
		{
			if (pos[i] >= 97 && pos[i] <= 122)
			{
				pos[i] -= 32;                           //to upper
			}
		}

		for (int i = 0; i < pos.length(); i++)
		{
			if ((pos[i] >= 'A' && pos[i] <= 'Z') || (pos[i] >= 'a' && pos[i] <= 'z') || (pos[i] == ' '))
			{
				count++;
			}
			else
			{
				return false;
			}
		}
		if (count == pos.length())
		{
			position = pos;
			return true;
		}
		else 
		{
			return false;
		}
	}
}
string Admin::getName()
{
	return Name;
}
string Admin::getAdmin_id()
{
	return admin_id;
}
char* Admin::getPassword()
{
	return password;
}
string Admin::getContact_no()
{
	return contact_no;
}
string Admin::getPosition()
{
	return position;
}
void Admin::getAdmininfo()
{
	string name, id, c_no, pos;
	char pass[10], a;
	int i = 0;

	do
	{
		cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t NAME : ";
		getline(cin, name);
	} while (set_name(name) == false);

	do
	{
		USERNAME:
		cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t USERNAME : ";
		getline(cin, id);
		if (searchUser(id) == true)
		{
			cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t Username already used" << endl;
			goto USERNAME;
		}
	} while (set_admin_id(id) == false);

	do
	{
	START:
		cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t Enter PASSWORD of 3 - 6 Digits :  ";
		for (i = 0;;)
		{
			a = _getch();//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))///////////////no special character//////
			{
				pass[i] = a;
				++i;
				cout << "*";
			}
			if (a == '\b' && i >= 1)
			{
				cout << "\b";
				--i;
			}
			if (a == '\r')
			{
				pass[i] = '\0';
				break;
			}
		}
		if (i < 3 || i > 6)
		{
			cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t Minimum 3 and Maximum 6 digits needed. " << endl;
			cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t Enter again..." << endl;
			
			goto START;
		}
	} while (set_password(pass) == false);

	do
	{
		cout << endl << "\n\n\t\t\t\t\t\t\t\t\t\t\t Contact Number : ";
		getline(cin, c_no);
	} while (set_contact_no(c_no) == false);

	do
	{
		cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t Position : ";
		getline(cin, pos);
	} while (set_position(pos) == false);
}
bool Admin::add_admin()
{
	getAdmininfo();
	ofstream add;
	add.open("Admin.txt", ios::app);
	add << endl << Name << endl << admin_id << endl << password << endl << contact_no << endl << position;
	add.close();
	return true;
}

bool Admin::login()
{
	int tries = 3;
LOGIN:
	char a, id[20], pass[10];
	int i = 0;
	
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t---------------------------------" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t       ADMINISTRATOR LOGIN" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t---------------------------------" << endl;
	
	do
	{
		cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t  USERNAME : ";
		cin.getline(id, 20);//////////////////////////////////////////////////////////////////////////////
	} while (set_admin_id(id) == false);

	do
	{
		cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t  PASSWORD : ";
		for (i = 0;;)
		{
			a = _getch();
			if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9')) /////////////////////no special char//////////////////////////
			{
				pass[i] = a;
				++i;
				cout << "*";
			}
			if (a == '\b' && i >= 1)
			{
				cout << "\b";
				--i;
			}
			if (a == '\r')
			{
				pass[i] = '\0';
				break;
			}
		}
	} while (set_password(pass) == false);

	ofstream add;                             //jo last time hoa tha login
	add.open("AdminLogin.txt");
	add << admin_id << endl << password;
	add.close();
//------------------------------------matching record---------------------------------
	ifstream view;
	int check = 0;
	string pass1;
	int counter = 0;
	view.open("Admin.txt", ios::in);
	if (!view)
	{
		cout << "\nAdmin File Not Exist...";
	}
	else
	{
		char c;
		c = view.get();
		Admin a;
		ifstream login;
		string user, pass2;
		login.open("AdminLogin.txt", ios::in);

		while (!login.eof())
		{
			getline(login, user);
			getline(login, pass2);
		}
		login.close();
		
		while (!view.eof())
		{
			check++;
			getline(view, Name);
			getline(view, admin_id);
			getline(view, pass1);
			getline(view, contact_no);
			getline(view, position);
			
			if (user == admin_id && pass2 == pass1)
			{
				counter++;
			}
		}
	}
	view.close();
	if (counter == 1)
	{
		return true;
	}
	else
	{
		if (tries > 0)
		{
			char choice;
			cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t You Entered wrong Credentials..." << endl;
			if (tries == 1)
			{
				cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t You have " << tries << " try left..." << endl;
			}
			else
			{
				cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t You have " << tries << " tries left..." << endl;
			}

			cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t Want to enter again (y/n) : ";
			cin >> choice;
			while(choice!='y'&&choice!='Y'&&choice!='n'&&choice!='N')
			{
				cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t Please enter correct choice (y/n): ";
				cin >> choice;
			}
			if (choice == 'y'||choice == 'Y')
			{
				system("cls");
				tries--;
				cin.ignore();
				goto LOGIN;
			}
			else
			{
				system("cls");
				cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t Happy ending...." << endl;
				exit(0);
			}
		}
		return false;
	}
}
bool Admin::matchForAdmin()
{
	ifstream view;
	int check = 0;
	string pass1;
	int counter = 0;
	view.open("Admin.txt", ios::in);
	if (!view)
	{
		cout << "\nAdmin File Not Exist...";
	}
	else
	{
		char c;
		c = view.get();
		Admin a;
		ifstream login;
		string user, pass2;
		login.open("AdminLogin.txt", ios::in);

		while (!login.eof())
		{
			getline(login, user);
			getline(login, pass2);
		}
		login.close();

		while (!view.eof())
		{
			check++;
			getline(view, Name);
			getline(view, admin_id);
			getline(view, pass1);
			getline(view, contact_no);
			getline(view, position);

			if (user == admin_id && pass2 == pass1 && (position == "MANAGER" || position == "PRESIDENT"))
			{
				counter++;
			}
		}
	}
	view.close();
	if (counter == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Admin::show_all_admin()
{
	ifstream view;
	int counter = 0;
	string pass;
	view.open("Admin.txt", ios::in);
	if (!view)
	{
		cout << "\n Admin File Not Exist...";
	}
	else
	{
		char c;
		c = view.get();
		while (!view.eof())
		{
			int i = 0;
			counter++;
			if (counter == 1)
			{
				cout << "\t\t\t\t\t\t\t" << left << setw(35) << "Name" << setw(25) << "Admin ID" << setw(35) << "Contact Number" << setw(15) << "Position" << endl;
			}
			getline(view, Name);
			getline(view, admin_id);
			getline(view, pass);
			getline(view, contact_no);
			getline(view, position);
			cout << endl << "\t\t\t\t\t\t\t" << left << setw(35) << Name << setw(25) << admin_id ;
			cout << setw(35) << contact_no << setw(15) << position << endl;
		}
	}
	view.close();
	if (counter == 0)
	{
		return false;
	}
	else 
	{
		return true;
	}
}
bool Admin::delete_admin(string id)
{
	ifstream deli;
	string pass;
	deli.open("Admin.txt", ios::in);
	if (!deli)
	{
		cout << "\n Admin File Not Exist...";
	}
	else
	{
		int counter = 0;
		ofstream delo;
		delo.open("tempAdmin.txt", ios::app);
		if (!deli)
		{
			cout << "\n Admin File Not Exist...";
		}
		else
		{
			char c;
			c = deli.get();////////////////////////////////////////////////////////////////
			while (!deli.eof())
			{
				getline(deli, Name);
				getline(deli, admin_id);
				getline(deli, pass);
				getline(deli, contact_no);
				getline(deli, position);
				if (id != admin_id)
				{
					delo << endl << Name << endl << admin_id << endl << pass << endl << contact_no << endl << position;
				}
				if (id == admin_id)
				{
					counter = 1;
				}
			}
			deli.close();
			delo.close();
			remove("Admin.txt");
			rename("tempAdmin.txt", "Admin.txt");
			if (counter == 0)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		deli.close();
	}

}
bool Admin::update_admin(string id)
{
	fstream update;
	string pass;
	update.open("Admin.txt", ios::in | ios::out | ios::ate);//////////////////////////////////////////////
	update.seekg(0);
	if (!update)
	{
		cout << "\nAdmin File Not Exist...";
		return false;
	}
	else
	{
		char c;
		c = update.get();////////////////////////////////
		int check = 0;
		while (!update.eof())
		{
			getline(update, Name);
			getline(update, admin_id);
			getline(update, pass);
			getline(update, contact_no);
			getline(update, position);
			update.ignore();
			if (id == admin_id)
			{
				check = 1;
				update.close();
				delete_admin(id);
				add_admin();
			}
		}
		if (check == 0) 
		{
			return false;
		}
		else 
		{
			return true;
		}
	}
}
bool Admin::search_admin(string search)
{
	ifstream view;
	int check = 0, counter = 0;
	string pass, name;
	view.open("Admin.txt", ios::in);
	if (!view)
	{
		cout << "\nAdmin File Not Exist...";
	}
	else
	{
		char c;
		c = view.get();
		while (!view.eof())
		{
			getline(view, name);
			getline(view, admin_id);
			getline(view, pass);
			getline(view, contact_no);
			getline(view, position);
			
			if (search == name || search == admin_id ) 
			{
				check++;
				if (check == 1)
				{
					cout << "\t\t\t\t\t\t\t" << left << setw(25) << "Name" << setw(25) << "Admin ID" << setw(35) << "Contact Number" << setw(15) << "Position" << endl;
				}
				cout << endl << "\t\t\t\t\t\t\t" << left << setw(25) << name << setw(25) << admin_id;
				cout << setw(35) << contact_no << setw(15) << position << endl;
				counter = 1;
			}
		}
	}
	view.close();
	if (counter == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Admin::searchUser(string user)
{
	ifstream view;
	int counter = 0;
	string pass, name;
	view.open("Admin.txt", ios::in);
	if (!view)
	{
		cout << "\nAdmin File Not Exist...";
	}
	else
	{
		char c;
		c = view.get();
		while (!view.eof())
		{
			getline(view, name);
			getline(view, admin_id);
			getline(view, pass);
			getline(view, contact_no);
			getline(view, position);
			
			if (user == admin_id ) 
			{
				counter = 1;
			}
			view.ignore();
		}
	}
	view.close();
	if (counter == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
Admin::~Admin()
{
	Name = "";
	admin_id = "";
	strcpy(password, "");
	contact_no = "";
	position = "";
}
