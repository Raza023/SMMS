#pragma once
#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include<cstring>
using namespace std;

class Admin
{
private:
	string Name;
	string admin_id;
	char password[10];
	string contact_no;
	string position;
public:
	Admin();
	bool set_name(string );
	bool set_admin_id(string );
	bool set_password(const char*);
	bool set_contact_no(string);
	bool set_position(string);
	string getName();
	string getAdmin_id();
	char* getPassword();
	string getContact_no();
	string getPosition();

	bool add_admin();
	void getAdmininfo();     //
	bool login();
	bool show_all_admin();
	bool delete_admin(string);
	bool update_admin(string);
	bool search_admin(string);
	bool searchUser(string);         //
	bool matchForAdmin();
	~Admin();

};

#endif // !ADMIN_H
