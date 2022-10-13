#include "HomeAppliances.h"
#include <iostream>
using namespace std;

HomeAppliances::HomeAppliances() :Product()
{
	manufacturer = "";
	manufacture_date = "";
	warrenty = "";
}
bool HomeAppliances::setManufacturer(string manufac)
{
	if (manufac == "")
	{
		return false;
	}
	else {
		for (int i = 0; i < manufac.length(); i++)
		{
			if (manufac[i] >= 97 && manufac[i] <= 122)
			{
				manufac[i] -= 32;
			}
		}

		manufacturer = manufac;
		return true;
	}
}
bool HomeAppliances::setManufacture_date(string date)
{
	if (date.length() != 10)
	{
		return false;
	}
	else
	{
		if (date[2] == '/' && date[5] == '/')
		{
			if ((date[0] == '0' || date[0] == '1' || date[0] == '2'))
			{
				if (date[1] >= 48 && date[1] <= 57)
				{
					if (date[3] == '0')
					{
						if (date[4] >= '1'&&date[4] <= '9')
						{
							if ((date[6] >= '0'&&date[6] <= '9') && (date[7] >= '0'&&date[7] <= '9') && (date[8] >= '0'&&date[8] <= '9') && (date[9] >= '0'&&date[9] <= '9'))
							{
								manufacture_date = date;
								return true;
							}
						}
					}
					else if (date[3] == '1')
					{
						if (date[4] == '0' || date[4] == '1' || date[4] == '2')
						{
							if ((date[6] >= '0'&&date[6] <= '9') && (date[7] >= '0'&&date[7] <= '9') && (date[8] >= '0'&&date[8] <= '9') && (date[9] >= '0'&&date[9] <= '9'))
							{
								manufacture_date = date;
								return true;
							}
							else
							{
								return false;
							}
						}
						else {
							return false;
						}
					}
					else
					{
						return false;
					}
				}
			}
			else if (date[0] == '3')
			{
				if (date[1] == 48 || date[1] == 49)
				{
					if (date[3] == '0')
					{
						if (date[4] >= '1'&&date[4] <= '9')
						{
							if ((date[6] >= '0'&&date[6] <= '9') && (date[7] >= '0'&&date[7] <= '9') && (date[8] >= '0'&&date[8] <= '9') && (date[9] >= '0'&&date[9] <= '9'))
							{
								manufacture_date = date;
								return true;
							}
						}
					}
					else if (date[3] == '1')
					{
						if (date[4] == '0' || date[4] == '1' || date[4] == '2')
						{
							if ((date[6] >= '0'&&date[6] <= '9') && (date[7] >= '0'&&date[7] <= '9') && (date[8] >= '0'&&date[8] <= '9') && (date[9] >= '0'&&date[9] <= '9'))
							{
								manufacture_date = date;
								return true;
							}
							else
							{
								return false;
							}
						}
						else {
							return false;
						}
					}
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else {
				return false;
			}
		}
		else
		{
			return false;
		}
	}
}
bool HomeAppliances::setWarrenty(string w)
{
	if (w == "")
	{
		return false;
	}
	else
	{
		for (int i = 0; i < w.length(); i++)
		{
			if (w[i] >= 97 && w[i] <= 122)
			{
				w[i] -= 32;
			}
		}

		warrenty = w;
		return true;
	}
}
string HomeAppliances::getManufacturer()
{
	return manufacturer;
}
string HomeAppliances::getManufacture_date()
{
	return manufacture_date;
}
string HomeAppliances::getWarrenty()
{
	return warrenty;
}
bool  HomeAppliances::getProductinfo()
{
	string id, name, mfgdate, warrenty, manufactrer;
	float s;
	double pr;
	GETID:
	do {
		char c;
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t Product ID : ";
		getline(cin, id);
		if (search_id(id) == true)
		{
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t Product ID alrady Exist." << endl;
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t Want to Add item (y/n) : ";
			cin >> c;
			while (c != 'y' && c != 'Y' && c != 'n' && c != 'N')
			{
				cout << "\n\t\t\t\t\t\t\t\t\t\t\t Enter Valid Choice : ";
				cin >> c;
			}
			if (c == 'y' || c == 'Y')
			{
				cin.ignore();
				goto GETID;
			}
			else
			{
				return false;
			}
		}
	} while (setPro_id(id) == false);

	do {
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t Product Name : ";
		getline(cin, name);
	} while (setPro_name(name) == false);


	do {
		cout << " \n\t\t\t\t\t\t\t\t\t\t\t Manufacturer : ";
		getline(cin, manufactrer);
	} while (setManufacturer(manufactrer) == false);

	cout << "\n\t\t\t\t\t\t\t\t\t\t\t Manufacture Date (dd/mm/yyyy) : ";
	getline(cin, mfgdate);

	while (setManufacture_date(mfgdate) == false) 
	{
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t Invalid date format" << endl;
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t Enter again (dd/mm/yyyy) : ";
		getline(cin, mfgdate);
	} 

	do {
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t Warrenty : ";
		getline(cin, warrenty);
	} while (setWarrenty(warrenty) == false);

	do {
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t Price : ";
		cin >> pr;
	} while (setPro_unitprice(pr) == false);

	do {
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t Quantity : ";
		cin >> s;
	} while (setPro_stock(s) == false);
	cin.ignore();
	return true;
}
bool HomeAppliances::additem()
{
	ofstream add;
	add.open("HomeAppliances.txt", ios::app);
	if (getProductinfo() == true)
	{
		add << endl << pro_id << endl << pro_name << endl << manufacturer << endl << manufacture_date << endl << warrenty << endl << pro_unitprice << endl << pro_stock;
		add.close();
		return true;
	}
	else
	{
		return false;
	}

}
HomeAppliances HomeAppliances::getProduct(string id) {
	ifstream view;
	view.open("HomeAppliances.txt", ios::in);
	if (!view)
	{
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t HomeAppliances File Not Exist...";
		return *this;
	}
	else
	{
		for (int i = 0; i < id.length(); i++)
		{
			if (id[i] >= 97 && id[i] <= 122)
			{
				id[i] -= 32;
			}
		}

		char c;
		c = view.get();
		while (!view.eof())
		{
			getline(view, pro_id);
			getline(view, pro_name);
			getline(view, manufacturer);
			getline(view, manufacture_date);
			getline(view, warrenty);
			view >> pro_unitprice;
			view >> pro_stock;
			if (id == pro_id) {
				view.close();
				return *this;
			}
			view.ignore();
		}
	}
	view.close();
	return *this;
}
bool HomeAppliances::search_Product(string search)
{
	ifstream view;
	int check = 0;
	view.open("HomeAppliances.txt", ios::in);
	if (!view)
	{
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t HomeAppliances File Not Exist...";
	}
	else
	{
		for (int i = 0; i < search.length(); i++)
		{
			if (search[i] >= 97 && search[i] <= 122)
			{
				search[i] -= 32;
			}
		}

		char c;
		c = view.get();
		while (!view.eof())
		{
			getline(view, pro_id);
			getline(view, pro_name);
			getline(view, manufacturer);
			getline(view, manufacture_date);
			getline(view, warrenty);
			view >> pro_unitprice;
			view >> pro_stock;
			if (search == pro_id || search == pro_name || search == manufacturer) {
				check++;
				if (check == 1)
				{
					cout << "\n\t\t" << left << setw(15) << "Product ID" << setw(30) << "Product Name"
						<< setw(18) << "Product Brand" << setw(21) << "Manufacture Date"
						<< setw(21) << "Product Warrenty" << setw(15) << "Unit Price"
						<< setw(18) << "Product Stock" << endl;
				}
				displayPro();
			}
			view.ignore();
		}
	}
	view.close();
	if (check == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool HomeAppliances::search_id(string id) {
	ifstream view;
	view.open("HomeAppliances.txt", ios::in);
	if (!view)
	{
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t HomeAppliances File Not Exist...";
		return false;
	}
	else
	{
		for (int i = 0; i < id.length(); i++)
		{
			if (id[i] >= 97 && id[i] <= 122)
			{
				id[i] -= 32;
			}
		}

		char c;
		c = view.get();
		while (!view.eof())
		{
			getline(view, pro_id);
			getline(view, pro_name);
			getline(view, manufacturer);
			getline(view, manufacture_date);
			getline(view, warrenty);
			view >> pro_unitprice;
			view >> pro_stock;
			if (id == pro_id) {
				view.close();
				return true;
			}
			view.ignore();
		}
	}
	view.close();
	return false;
}
bool HomeAppliances::update_Product(string id)
{
	fstream update;
	update.open("HomeAppliances.txt");
	if (!update)
	{
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t HomeAppliances File Not Exist...";
		return false;
	}
	else
	{
		for (int i = 0; i < id.length(); i++)
		{
			if (id[i] >= 97 && id[i] <= 122)
			{
				id[i] -= 32;
			}
		}

		char c;
		c = update.get();
		int check = 0;
		while (!update.eof())
		{
			getline(update, pro_id);
			getline(update, pro_name);
			getline(update, manufacturer);
			getline(update, manufacture_date);
			getline(update, warrenty);
			update >> pro_unitprice;
			update >> pro_stock;
			update.ignore();
			if (id == pro_id)
			{
				check = 1;
				update.close();
				HomeAppliances h;
				h.pro_id = pro_id;
				h.pro_stock = pro_stock;
				h.pro_unitprice = pro_unitprice;
				h.manufacturer = manufacturer;
				h.manufacture_date = manufacture_date;
				h.pro_name = pro_name;
				h.warrenty = warrenty;
				cout << "\t\t\t\t\t\t\t\t\t\t Which INFO you want to update :\n";
				cout << "\t\t\t\t\t\t\t\t\t\t 1.PRODUCT ID\n";
				cout << "\t\t\t\t\t\t\t\t\t\t 2.PRODUCT NAME\n";
				cout << "\t\t\t\t\t\t\t\t\t\t 3.PRODUCT PRICE\n";
				cout << "\t\t\t\t\t\t\t\t\t\t 4.PRODUCT MFG_DATE\n";
				cout << "\t\t\t\t\t\t\t\t\t\t 5.PRODUCT WARRENTY\n";
				cout << "\t\t\t\t\t\t\t\t\t\t 6.PRODUCT STOCK\n";
				cout << "\t\t\t\t\t\t\t\t\t\t 7.PRODUCT MANUFACTURER\n";
				cout << "\t\t\t\t\t\t\t\t\t\t 8.UPDATE ALL\n";
				int c;
				cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t Enter Choice : ";
				cin >> c;
				while (c > 8 || c < 1) {
					cout << "\n\t\t\t\t\t\t\t\t\t\t\t Enter VALID CHOICE : ";
					cin >> c;
				}
				cin.ignore();
				if (c == 1)
				{
					string nid;
					cout << "\n\t\t\t\t\t\t\t\t\t\t\t Enter NEW ID: ";
					getline(cin, nid);
					delete_item(id);
					if (search_id(nid))
					{
						cout << "\t\t\t\t\t\t\t\t\t\t\t ENTERED ID IS ALREADY PRESENT\n";
						ofstream a;
						a.open("HomeAppliances.txt", ios::app);
						a.seekp(0);
						a << endl << h.pro_id << endl << h.pro_name << endl << h.manufacturer << endl << h.manufacture_date << endl << h.warrenty << endl << h.pro_unitprice << endl << h.pro_stock;
						a.close();
						system("pause");
						return false;
					}
					else
					{
						ofstream a;
						a.open("HomeAppliances.txt", ios::app);
						a.seekp(0);
						a << endl << nid << endl << h.pro_name << endl << h.manufacturer << endl << h.manufacture_date << endl << h.warrenty << endl << h.pro_unitprice << endl << h.pro_stock;
						a.close();
						return true;
					}
				}
				else if (c == 2)
				{
					string name;
					cout << "\n\t\t\t\t\t\t\t\t\t\t\t Enter NEW NAME OF PRODUCT : ";
					getline(cin, name);
					while (name == "")
					{
						getline(cin, name);
					}
					delete_item(id);
					ofstream a;
					a.open("HomeAppliances.txt", ios::app);
					a.seekp(0);
					a << endl << h.pro_id << endl << name << endl << h.manufacturer << endl << h.manufacture_date << endl << h.warrenty << endl << h.pro_unitprice << endl << h.pro_stock;
					a.close();
					return true;
				}
				else if (c == 3)
				{
					double price;
					cout << "\n\t\t\t\t\t\t\t\t\t\t\t Enter new price : ";
					cin >> price;
					while (price <= 0)
					{
						cout << "\n\t\t\t\t\t\t\t\t\t\t\t Enter Valid Price : ";
						cin >> price;
					}
					h.pro_unitprice = price;
					delete_item(id);
					ofstream a;
					a.open("HomeAppliances.txt", ios::app);
					a.seekp(0);
					a << endl << h.pro_id << endl << h.pro_name << endl << h.manufacturer << endl << h.manufacture_date << endl << h.warrenty << endl << h.pro_unitprice << endl << h.pro_stock;
					a.close();
					return true;
				}
				else if (c == 4)
				{
					string mfg;
					cout << "\n\t\t\t\t\t\t\t\t\t\t\t Enter NEW MFG_DATE OF PRODUCT (dd/mm/yyyy) : ";
					getline(cin, mfg);
					while (h.setManufacture_date(mfg) == false)
					{
						cout << "\n\t\t\t\t\t\t\t\t\t\t\t Enter valid Date : ";
						getline(cin, mfg);
					}
					delete_item(id);
					ofstream a;
					a.open("HomeAppliances.txt", ios::app);
					a.seekp(0);
					a << endl << h.pro_id << endl << h.pro_name << endl << h.manufacturer << endl << h.manufacture_date << endl << h.warrenty << endl << h.pro_unitprice << endl << h.pro_stock;
					a.close();
					return true;
				}
				else if (c == 5)
				{
					string w;
					cout << "\n\t\t\t\t\t\t\t\t\t\t\t Enter NEW WARRENTY OF PRODUCT : ";
					getline(cin, w);
					while (h.setWarrenty(w) == false)
					{
						getline(cin, w);
					}
					delete_item(id);
					ofstream a;
					a.open("HomeAppliances.txt", ios::app);
					a.seekp(0);
					a << endl << h.pro_id << endl << h.pro_name << endl << h.manufacturer << endl << h.manufacture_date << endl << h.warrenty << endl << h.pro_unitprice << endl << h.pro_stock;
					a.close();
					return true;
				}
				else if (c == 6)
				{
					float s;
					cout << "\n\t\t\t\t\t\t\t\t\t\t\t ENTER NEW STOCK : ";
					cin >> s;
					while (s < 0)
					{
						cout << "ENTER VALID STOCK : ";
						cin >> s;
					}
					h.pro_stock += s;
					delete_item(id);
					ofstream a;
					a.open("HomeAppliances.txt", ios::app);
					a.seekp(0);
					a << endl << h.pro_id << endl << h.pro_name << endl << h.manufacturer << endl << h.manufacture_date << endl << h.warrenty << endl << h.pro_unitprice << endl << h.pro_stock;
					a.close();
					return true;
				}
				else if (c == 7)
				{
					string man;
					cout << "\n\t\t\t\t\t\t\t\t\t\t\t Set NEW MANUFACTURER OF PRODUCT : ";
					getline(cin, man);
					while (h.setManufacturer(man) == false)
					{
						getline(cin, man);
					}
					delete_item(id);
					ofstream a;
					a.open("HomeAppliances.txt", ios::app);
					a.seekp(0);
					a << endl << h.pro_id << endl << h.pro_name << endl << h.manufacturer << endl << h.manufacture_date << endl << h.warrenty << endl << h.pro_unitprice << endl << h.pro_stock;
					a.close();
					return true;
				}
				else if (c == 8)
				{
					check = 1;
					update.close();
					delete_item(id);
					additem();
					return true;
				}
			}
		}
		if (check == 0)
		{
			return false;
		}
		else {
			return true;
		}
	}
}
bool HomeAppliances::delete_item(string id)
{
	ifstream deli;
	deli.open("HomeAppliances.txt", ios::in);
	if (!deli)
	{
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t HomeAppliances File Not Exist...";
	}
	else
	{
		for (int i = 0; i < id.length(); i++)
		{
			if (id[i] >= 97 && id[i] <= 122)
			{
				id[i] -= 32;
			}
		}

		int counter = 0;
		ofstream delo;
		delo.open("tempHA.txt", ios::app);
		if (!deli)
		{
			cout << "\nHomeAppliances File Not Exist...";
		}
		else
		{
			char c;
			c = deli.get();
			while (!deli.eof())
			{
				getline(deli, pro_id);
				getline(deli, pro_name);
				getline(deli, manufacturer);
				getline(deli, manufacture_date);
				getline(deli, warrenty);
				deli >> pro_unitprice;
				deli >> pro_stock;
				deli.ignore();
				if (id != pro_id)
				{
					delo << endl << pro_id << endl << pro_name << endl << manufacturer << endl << manufacture_date << endl << warrenty << endl << pro_unitprice << endl << pro_stock;
				}
				if (id == pro_id)
				{
					counter = 1;
				}
			}
			deli.close();
			delo.close();
			remove("HomeAppliances.txt");
			rename("tempHA.txt", "HomeAppliances.txt");
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

void HomeAppliances::displayPro()
{
	cout << endl << "\t\t" << left << setw(15) << pro_id << setw(30) << pro_name
		<< setw(18) << manufacturer << setw(21) << manufacture_date
		<< setw(21) << warrenty << setw(15) << pro_unitprice
		<< setw(18) << pro_stock << endl;
}
bool HomeAppliances::updateStock(string id, float s)
{
	fstream update;
	update.open("HomeAppliances.txt", ios::in | ios::out | ios::ate);
	update.seekg(0);
	if (!update)
	{
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t HomeAppliances File Not Exist...";
		return false;
	}
	else
	{
		for (int i = 0; i < id.length(); i++)
		{
			if (id[i] >= 97 && id[i] <= 122)
			{
				id[i] -= 32;
			}
		}

		char c;
		c = update.get();
		int check = 0;
		while (!update.eof())
		{
			getline(update, pro_id);
			getline(update, pro_name);
			getline(update, manufacturer);
			getline(update, manufacture_date);
			getline(update, warrenty);
			update >> pro_unitprice;
			update >> pro_stock;
			update.ignore();
			if (id == pro_id)
			{
				check = 1;
				update.close();
				HomeAppliances h;
				h.pro_id = pro_id;
				h.pro_stock = pro_stock;
				h.pro_unitprice = pro_unitprice;
				h.manufacturer = manufacturer;
				h.manufacture_date = manufacture_date;
				h.pro_name = pro_name;
				h.warrenty = warrenty;
				if (pro_stock >= s) {
					h.pro_stock -= s;
					delete_item(id);
					ofstream a;
					a.open("HomeAppliances.txt", ios::app);
					a << endl << h.pro_id << endl << h.pro_name << endl << h.manufacturer << endl << h.manufacture_date << endl << h.warrenty << endl << h.pro_unitprice << endl << h.pro_stock;
					a.close();
					return true;
				}
			}
		}
		if (check == 0) {
			return false;
		}
		else {
			return true;
		}

	}
}
bool HomeAppliances::show_all_items()
{
	ifstream view;
	int counter = 0;
	view.open("HomeAppliances.txt", ios::in);
	if (!view)
	{
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t HomeAppliances File Not Exist...";
	}
	else
	{
		char c;
		c = view.get();
		while (!view.eof())
		{
			counter++;
			if (counter == 1)
			{
				cout << "\n\t\t" << left << setw(15) << "Product ID" << setw(30) << "Product Name"
					<< setw(18) << "Product Brand" << setw(21) << "Manufacture Date"
					<< setw(21) << "Product Warrenty" << setw(15) << "Unit Price"
					<< setw(18) << "Product Stock" << endl;
			}
			getline(view, pro_id);
			getline(view, pro_name);
			getline(view, manufacturer);
			getline(view, manufacture_date);
			getline(view, warrenty);
			view >> pro_unitprice;
			view >> pro_stock;
			displayPro();
			view.ignore();
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
bool HomeAppliances::show_limited_stock(float s)
{
	if (s < 0) {
		return false;
	}
	ifstream view;
	int check = 0;
	view.open("HomeAppliances.txt", ios::in);
	if (!view)
	{
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t HomeAppliances File Not Exist...";
	}
	else
	{
		char c;
		c = view.get();
		while (!view.eof())
		{
			getline(view, pro_id);
			getline(view, pro_name);
			getline(view, manufacturer);
			getline(view, manufacture_date);
			getline(view, warrenty);
			view >> pro_unitprice;
			view >> pro_stock;
			if (s >= pro_stock) {
				check++;
				if (check == 1)
				{
					cout << "\n\t\t" << left << setw(15) << "Product ID" << setw(30) << "Product Name"
						<< setw(18) << "Product Brand" << setw(21) << "Manufacture Date"
						<< setw(21) << "Product Warrenty" << setw(15) << "Unit Price"
						<< setw(18) << "Product Stock" << endl;
				}
				displayPro();
			}
			view.ignore();
		}
	}
	view.close();
	if (check == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
HomeAppliances::~HomeAppliances()
{
	manufacturer = "";
	manufacture_date = "";
	warrenty = "";
}
