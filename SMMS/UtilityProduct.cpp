#include "UtilityProduct.h"
UtilityProducts::UtilityProducts() :Product()
{
	mfg_date = "";
	expiry_date = "";
}

bool UtilityProducts::set_mfg_date(string date)
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
				if (date[1] >= 48 && date[1] <= 57)      //0-9
				{
					if (date[3] == '0')
					{
						if (date[4] >= '1'&&date[4] <= '9')
						{
							if ((date[6] >= '0'&&date[6] <= '9') && (date[7] >= '0'&&date[7] <= '9') && (date[8] >= '0'&&date[8] <= '9') && (date[9] >= '0'&&date[9] <= '9'))
							{
								mfg_date = date;
								return true;
							}
						}
						else
						{
							return false;
						}
					}
					else if (date[3] == '1')
					{
						if (date[4] == '0' || date[4] == '1' || date[4] == '2')
						{
							if ((date[6] >= '0'&&date[6] <= '9') && (date[7] >= '0'&&date[7] <= '9') && (date[8] >= '0'&&date[8] <= '9') && (date[9] >= '0'&&date[9] <= '9'))
							{
								mfg_date = date;
								return true;
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
								mfg_date = date;
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
								mfg_date = date;
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
bool UtilityProducts::set_expiry_date(string date)
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
								expiry_date = date;
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
								expiry_date = date;
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
								expiry_date = date;
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
								expiry_date = date;
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
string UtilityProducts::get_mfg_date()
{
	return mfg_date;
}
string UtilityProducts::get_expiry_date()
{
	return expiry_date;
}
void UtilityProducts::displayPro()
{
	cout << endl << "\t\t" << left << setw(15) << pro_id << setw(30) << pro_name
		<< setw(21) << mfg_date << setw(21) << expiry_date
		<< setw(15) << pro_unitprice
		<< setw(18) << pro_stock << endl;

}

bool UtilityProducts::getProductinfo()
{
	string id, name, mfg, exp;
	float s;
	double pr;
	char c;
	GETID:
	do
	{
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

	do
	{
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t Product Name : ";
		getline(cin, name);
	} while (setPro_name(name) == false);

	cout << "\n\t\t\t\t\t\t\t\t\t\t\t Manufacture Date : ";
	getline(cin, mfg);

	while (set_mfg_date(mfg) == false)
	{
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t Invalid format." << endl;
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t Enter again (dd/mm/yyyy) : ";
		getline(cin, mfg);
	}


	cout << "\n\t\t\t\t\t\t\t\t\t\t\t Expiry Date : ";
	getline(cin, exp);

	while (set_expiry_date(exp) == false)
	{
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t Invalid format." << endl;
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t Enter again (dd/mm/yyyy) : ";
		getline(cin, exp);
	}

	do
	{
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t Price : ";
		cin >> pr;
	} while (setPro_unitprice(pr) == false);

	do
	{
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t Quantity : ";
		cin >> s;
	} while (setPro_stock(s) == false);
	cin.ignore();
	return true;
}
bool UtilityProducts::additem()
{
	ofstream add;
	add.open("Eatable.txt", ios::app);         //we want to add at the end so using append, We cannot move the pointer. It will be only at end.
	if (getProductinfo() == true)
	{
		add << endl << pro_id << endl << pro_name << endl << mfg_date << endl << expiry_date << endl << pro_unitprice << endl << pro_stock;
		add.close();
		return true;
	}
	else {
		return false;
	}

}

bool UtilityProducts::search_Product(string search)
{
	ifstream view;
	int check = 0;
	view.open("Eatable.txt", ios::in);
	if (!view)
	{
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t Utility Products File Not Exist...";
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
			getline(view, mfg_date);
			getline(view, expiry_date);
			view >> pro_unitprice;
			view >> pro_stock;
			if (search == pro_id || search == pro_name)
			{
				check++;
				if (check == 1)
				{
					cout << "\n\t\t" << left << setw(15) << "Product ID" << setw(30) << "Product Name"
						<< setw(21) << "Manufacture Date" << setw(21) << "Expiry Date"
						<< setw(15) << "Unit Price"
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
bool UtilityProducts::search_id(string id)
{
	ifstream view;
	int check = 0;
	view.open("Eatable.txt", ios::in);
	if (!view)
	{
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t Utility Products File Not Exist...";
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
			getline(view, mfg_date);
			getline(view, expiry_date);
			view >> pro_unitprice;
			view >> pro_stock;
			if (id == pro_id)
			{
				view.close();
				return true;
			}
			view.ignore();
		}
	}
	view.close();
	return false;
}

bool UtilityProducts::update_Product(string id)
{
	fstream update;
	update.open("Eatable.txt");
	if (!update)
	{
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t Utility Products File Not Exist...";
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
			getline(update, mfg_date);
			getline(update, expiry_date);
			update >> pro_unitprice;
			update >> pro_stock;
			update.ignore();
			if (id == pro_id)
			{
				check = 1;
				update.close();
				UtilityProducts h;

				h.pro_id = pro_id;
				h.pro_stock = pro_stock;
				h.pro_unitprice = pro_unitprice;
				h.expiry_date = expiry_date;
				h.mfg_date = mfg_date;
				h.pro_name = pro_name;

				cout << "\t\t\t\t\t\t\t\t\t\t  Which INFO you want to update :\n";
				cout << "\t\t\t\t\t\t\t\t\t\t 1.PRODUCT ID\n";
				cout << "\t\t\t\t\t\t\t\t\t\t 2.PRODUCT NAME\n";
				cout << "\t\t\t\t\t\t\t\t\t\t 3.PRODUCT PRICE\n";
				cout << "\t\t\t\t\t\t\t\t\t\t 4.PRODUCT MFG_DATE\n";
				cout << "\t\t\t\t\t\t\t\t\t\t 5.PRODUCT EXP_DATE\n";
				cout << "\t\t\t\t\t\t\t\t\t\t 6.PRODUCT STOCK\n";
				cout << "\t\t\t\t\t\t\t\t\t\t 7.UPDATE ALL\n";
				int c;
				cout << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\t Enter Choice : ";
				cin >> c;
				while (c > 7 || c < 1) {
					cout << "\t\t\t\t\t\t\t\t\t\t Enter VALID CHOICE : ";
					cin >> c;
				}
				cin.ignore();
				if (c == 1)
				{
					string nid;
					cout << "\n\t\t\t\t\t\t\t\t\t\t\t Enter NEW ID : ";
					getline(cin, nid);
					delete_item(id);
					if (search_id(nid))
					{
						cout << "\n\t\t\t\t\t\t\t\t\t\t\t ENTERED ID IS ALREADY PRESENT\n";
						ofstream a;
						a.open("Eatable.txt", ios::app);
						a.seekp(0);
						a << endl << h.pro_id << endl << h.pro_name << endl << h.mfg_date << endl << h.expiry_date << endl << h.pro_unitprice << endl << h.pro_stock;
						a.close();
						system("pause");
						return false;
					}
					else
					{
						ofstream a;
						a.open("Eatable.txt", ios::app);
						a.seekp(0);
						a << endl << nid << endl << h.pro_name << endl << h.mfg_date << endl << h.expiry_date << endl << h.pro_unitprice << endl << h.pro_stock;
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
					a.open("Eatable.txt", ios::app);
					a.seekp(0);////////////////////////////////////////////////////////////////////////
					a << endl << h.pro_id << endl << name << endl << h.mfg_date << endl << h.expiry_date << endl << h.pro_unitprice << endl << h.pro_stock;
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
					a.open("Eatable.txt", ios::app);
					a.seekp(0);
					a << endl << h.pro_id << endl << h.pro_name << endl << h.mfg_date << endl << h.expiry_date << endl << h.pro_unitprice << endl << h.pro_stock;
					a.close();
					return true;
				}
				else if (c == 4)
				{
					string mfg;
					cout << "\n\t\t\t\t\t\t\t\t\t\t\t Enter NEW MFG_DATE OF PRODUCT (dd/mm/yyyy) : ";
					getline(cin, mfg);
					while (h.set_mfg_date(mfg) == false)
					{
						cout << "\n\t\t\t\t\t\t\t\t\t\t\t Enter valid Date : ";
						getline(cin, mfg);
					}
					delete_item(id);
					ofstream a;
					a.open("Eatable.txt", ios::app);
					a.seekp(0);
					a << endl << h.pro_id << endl << h.pro_name << endl << h.mfg_date << endl << h.expiry_date << endl << h.pro_unitprice << endl << h.pro_stock;
					a.close();
					return true;
				}
				else if (c == 5)
				{
					string w;
					cout << "\n\t\t\t\t\t\t\t\t\t\t\t SET NEW EXP_DATE OF PRODUCT (dd/mm/yyyy) : ";
					getline(cin, w);
					while (h.set_expiry_date(w) == false)
					{
						cout << "\n\t\t\t\t\t\t\t\t\t\t\t Enter valid Date : ";
						getline(cin, w);
					}
					delete_item(id);
					ofstream a;
					a.open("Eatable.txt", ios::app);
					a.seekp(0);
					a << endl << h.pro_id << endl << h.pro_name << endl << h.mfg_date << endl << h.expiry_date << endl << h.pro_unitprice << endl << h.pro_stock;
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
						cout << "\n\t\t\t\t\t\t\t\t\t\t\t ENTER VALID STOCK : ";
						cin >> s;
					}
					h.pro_stock += s;
					delete_item(id);
					ofstream a;
					a.open("Eatable.txt", ios::app);
					a.seekp(0);
					a << endl << h.pro_id << endl << h.pro_name << endl << h.mfg_date << endl << h.expiry_date << endl << h.pro_unitprice << endl << h.pro_stock;
					a.close();
					return true;
				}
				else if (c == 7)
				{
					check = 1;
					update.close();/////////////////////////////////////////////////////////////////
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
bool UtilityProducts::delete_item(string id)
{
	ifstream deli;
	deli.open("Eatable.txt", ios::in);
	if (!deli)
	{
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t Utility Products File Not Exist...";
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
		delo.open("tempEA.txt", ios::app);
		if (!deli)
		{
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t Utility Products File Not Exist...";
		}
		else
		{
			char c;
			c = deli.get();
			while (!deli.eof())
			{
				getline(deli, pro_id);
				getline(deli, pro_name);
				getline(deli, mfg_date);
				getline(deli, expiry_date);
				deli >> pro_unitprice;
				deli >> pro_stock;
				deli.ignore();
				if (id != pro_id)
				{
					delo << endl << pro_id << endl << pro_name << endl << mfg_date << endl << expiry_date << endl << pro_unitprice << endl << pro_stock;
				}
				if (id == pro_id)
				{
					counter = 1;
				}
			}
			deli.close();
			delo.close();
			remove("Eatable.txt");
			rename("tempEA.txt", "Eatable.txt");
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
bool UtilityProducts::show_limited_stock(float s)
{
	if (s < 0)
	{
		return false;
	}
	ifstream view;
	int check = 0;
	view.open("Eatable.txt", ios::in);
	if (!view)
	{
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t Utility Products File Not Exist...";
	}
	else
	{
		char c;
		c = view.get();
		while (!view.eof())
		{
			getline(view, pro_id);
			getline(view, pro_name);
			getline(view, mfg_date);
			getline(view, expiry_date);
			view >> pro_unitprice;
			view >> pro_stock;
			if (s >= pro_stock)
			{
				check++;
				if (check == 1)
				{
					cout << "\t\t" << left << setw(15) << "Product ID" << setw(30) << "Product Name"
						<< setw(21) << "Manufacture Date" << setw(21) << "Expiry Date"
						<< setw(15) << "Unit Price"
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
bool UtilityProducts::show_all_items()
{
	ifstream view;
	int counter = 0;
	view.open("Eatable.txt", ios::in);
	if (!view)
	{
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t Utility Products File Not Exist...";
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
					<< setw(21) << "Manufacture Date" << setw(21) << "Expiry Date"
					<< setw(15) << "Unit Price"
					<< setw(18) << "Product Stock" << endl;
			}
			getline(view, pro_id);
			getline(view, pro_name);
			getline(view, mfg_date);
			getline(view, expiry_date);
			view >> pro_unitprice;
			view >> pro_stock;
			displayPro();
			view.ignore();
		}
	}
	view.close();
	return true;
}

bool UtilityProducts::updateStock(string id, float s)
{
	fstream update;
	update.open("Eatable.txt");
	if (!update)
	{
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t Utility Products File Not Exist...";
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
			getline(update, mfg_date);
			getline(update, expiry_date);
			update >> pro_unitprice;
			update >> pro_stock;
			update.ignore();
			if (id == pro_id)
			{
				check = 1;
				update.close();
				UtilityProducts u;
				u.pro_id = pro_id;
				u.pro_stock = pro_stock;
				u.pro_unitprice = pro_unitprice;
				u.mfg_date = mfg_date;
				u.expiry_date = expiry_date;
				u.pro_name = pro_name;
				if (pro_stock >= s)
				{
					u.pro_stock -= s;
					delete_item(id);
					ofstream a;
					a.open("Eatable.txt", ios::app);
					a.seekp(0);
					a << endl << u.pro_id << endl << u.pro_name << endl << u.mfg_date << endl << u.expiry_date << endl << u.pro_unitprice << endl << u.pro_stock;
					a.close();
					return true;
				}
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

UtilityProducts UtilityProducts::getProduct(string id)
{
	ifstream view;
	view.open("Eatable.txt", ios::in);
	if (!view)
	{
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t Utility Products File Not Exist...";
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
			getline(view, mfg_date);
			getline(view, expiry_date);
			view >> pro_unitprice;
			view >> pro_stock;
			if (id == pro_id)
			{
				view.close();
				return *this;
			}
			view.ignore();
		}
	}
	view.close();
	return *this;
}

UtilityProducts::~UtilityProducts()
{
	mfg_date = "";
	expiry_date = "";
}
