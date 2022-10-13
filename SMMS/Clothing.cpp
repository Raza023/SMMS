#include "Clothing.h"
#include <iostream>
#include <string>
using namespace std;


Clothing::Clothing() :Product()
{
	cloth_size = "";
	cloth_type = "";
	brand = "";
	color = "";
}
bool Clothing::setBrand(string br)
{
	if (br == "")
	{
		return false;
	}
	else
	{
		for (int i = 0; i < br.length(); i++)
		{
			if (br[i] >= 97 && br[i] <= 122)
			{
				br[i] -= 32;
			}
		}

		brand = br;
		return true;
	}
}
bool Clothing::setSize(string siz)
{
	if (siz == "")
	{
		return false;
	}
	else
	{
		for (int i = 0; i < siz.length(); i++)
		{
			if (siz[i] >= 97 && siz[i] <= 122)
			{
				siz[i] -= 32;
			}
		}

		cloth_size = siz;
		return true;
	}
}
bool Clothing::setColor(string col)
{
	if (col == "")
	{
		return false;
	}
	else
	{
		for (int i = 0; i < col.length(); i++)
		{
			if (col[i] >= 97 && col[i] <= 122)
			{
				col[i] -= 32;
			}
		}

		color = col;
		return true;
	}
}
bool Clothing::setCloth_type(string type)
{
	if (type == "")
	{
		return false;
	}
	else
	{
		for (int i = 0; i < type.length(); i++)
		{
			if (type[i] >= 97 && type[i] <= 122)
			{
				type[i] -= 32;
			}
		}

		cloth_type = type;
		return true;
	}
}
string Clothing::getBrand()
{
	return brand;
}
string Clothing::getSize()
{
	return cloth_size;
}
string Clothing::getColor()
{
	return color;
}
string Clothing::getCloth_type()
{
	return cloth_type;
}

bool Clothing::getProductinfo()
{
	string id, name, br, siz, col, type;
	double pr;
	float s;
	char c;
	GETID:
	do {
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
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t Cloth Brand : ";
		getline(cin, br);
	} while (setBrand(br) == false);

	do {
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t Size : ";
		getline(cin, siz);
	} while (setSize(siz) == false);

	do {
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t Color : ";
		getline(cin, col);
	} while (setColor(col) == false);

	do {
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t Type : ";
		getline(cin, type);
	} while (setCloth_type(type) == false);
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

void Clothing::displayPro()
{
	cout << endl << "\t\t" <<  left << setw(15) << pro_id << setw(30) << pro_name
		<< setw(18) << brand << setw(21) << cloth_size
		<< setw(21) << color << setw(15) << cloth_type << setw(16) << pro_unitprice
		<< setw(18) << pro_stock << endl;
}

bool Clothing::additem()
{
	ofstream add;
	add.open("Clothing.txt", ios::app);
	if (getProductinfo() == true)
	{
		add << endl << pro_id << endl << pro_name << endl << brand << endl << cloth_size << endl << color << endl << cloth_type << endl << pro_unitprice << endl << pro_stock;
		add.close();
		return true;
	}
	else {
		return false;
	}

}

bool Clothing::search_Product(string search)
{
	ifstream view;
	int check = 0;
	view.open("Clothing.txt", ios::in);
	if (!view)
	{
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t Clothing File Not Exist...";
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
			getline(view, brand);
			getline(view, cloth_size);
			getline(view, color);
			getline(view, cloth_type);
			view >> pro_unitprice;
			view >> pro_stock;
			if (search == pro_id || search == pro_name || search == brand || search == color || search == cloth_type) {
				check++;
				if (check == 1)
				{
					cout << "\t\t" << left << setw(15) << "Product ID" << setw(30) << "Product Name"
						<< setw(18) << "Product Brand" << setw(21) << "Cloth Size"
						<< setw(21) << "Cloth Color" << setw(15) << "Cloth Type" << setw(15) << "Unit Price"
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

bool Clothing::search_id(string id)
{
	ifstream view;
	int check = 0;
	view.open("Clothing.txt", ios::in);
	if (!view)
	{
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t Clothing File Not Exist...";
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
			getline(view, brand);
			getline(view, cloth_size);
			getline(view, color);
			getline(view, cloth_type);
			view >> pro_unitprice;
			view >> pro_stock;
			int counter = 0;
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
Clothing Clothing::getProduct(string id) {
	ifstream view;
	int check = 0;
	view.open("Clothing.txt", ios::in);
	if (!view)
	{
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t Clothing File Not Exist...";
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
			getline(view, brand);
			getline(view, cloth_size);
			getline(view, color);
			getline(view, cloth_type);
			view >> pro_unitprice;
			view >> pro_stock;
			int counter = 0;
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
bool Clothing::update_Product(string id)
{
	fstream update;
	update.open("Clothing.txt");
	if (!update)
	{
		cout << "\n\t\t\t\t\t\t\t\t\t\t Clothing File Not Exist...";
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
			getline(update, brand);
			getline(update, cloth_size);
			getline(update, color);
			getline(update, cloth_type);
			update >> pro_unitprice;
			update >> pro_stock;
			update.ignore();
			if (id == pro_id)
			{
				check = 1;
				update.close();
				Clothing h;
				h.pro_id = pro_id;
				h.pro_name = pro_name;
				h.pro_unitprice = pro_unitprice;
				h.pro_stock = pro_stock;
				h.brand = brand;
				h.cloth_size = cloth_size;
				h.color = color;
				h.cloth_type = cloth_type;
				cout << "\t\t\t\t\t\t\t\t\t\t Which INFO you want to update :\n";
				cout << "\t\t\t\t\t\t\t\t\t\t 1.PRODUCT ID\n";
				cout << "\t\t\t\t\t\t\t\t\t\t 2.PRODUCT NAME\n";
				cout << "\t\t\t\t\t\t\t\t\t\t 3.PRODUCT PRICE\n";
				cout << "\t\t\t\t\t\t\t\t\t\t 4.PRODUCT BRAND\n";
				cout << "\t\t\t\t\t\t\t\t\t\t 5.PRODUCT SIZE\n";
				cout << "\t\t\t\t\t\t\t\t\t\t 6.PRODUCT STOCK\n";
				cout << "\t\t\t\t\t\t\t\t\t\t 7.PRODUCT TYPE\n";
				cout << "\t\t\t\t\t\t\t\t\t\t 8.PRODUCT COLOR\n";
				cout << "\t\t\t\t\t\t\t\t\t\t 9.UPDATE ALL\n";
				int c;
				cout << "\n\t\t\t\t\t\t\t\t\t\t\t Enter Choice : ";
				cin >> c;
				while (c > 9 || c < 1) {
					cout << "\n\t\t\t\t\t\t\t\t\t\t\t Enter VALID CHOICE : \n";
					cin >> c;
				}
				cin.ignore();
				if (c == 1)
				{
					string nid;
					cout << "\t\t\t\t\t\t\t\t\t\t SET NEW ID : ";
					getline(cin, nid);
					delete_item(id);
					if (search_id(nid))
					{
						cout << "\t\t\t\t\t\t\t\t\t\t ENTERED ID IS ALREADY PRESENT\n";
						ofstream a;
						a.open("Clothing.txt", ios::app);
						a.seekp(0);
						a << endl << h.pro_id << endl << h.pro_name << endl << h.brand << endl << h.cloth_size << endl << h.color << endl << h.cloth_type << endl << h.pro_unitprice << endl << h.pro_stock;
						a.close();
						return false;
					}
					else
					{
						ofstream a;
						a.open("Clothing.txt", ios::app);
						a.seekp(0);
						a << endl << nid << endl << h.pro_name << endl << h.brand << endl << h.cloth_size << endl << h.color << endl << h.cloth_type << endl << h.pro_unitprice << endl << h.pro_stock;
						a.close();
						return true;
					}
				}
				else if (c == 2)
				{
					string name;
					cout << "\t\t\t\t\t\t\t\t\t\t SET NEW NAME OF PRODUCT : ";
					getline(cin, name);
					while (name == "")
					{
						getline(cin, name);
					}
					delete_item(id);
					ofstream a;
					a.open("Clothing.txt", ios::app);
					a.seekp(0);
					a << endl << h.pro_id << endl << name << endl << h.brand << endl << h.cloth_size << endl << h.color << endl << h.cloth_type << endl << h.pro_unitprice << endl << h.pro_stock;					a.close();
					return true;
				}
				else if (c == 3)
				{
					double price;
					cout << "\t\t\t\t\t\t\t\t\t\t SET NEW PRICE : ";
					cin >> price;
					while (price <= 0)
					{
						cout << "\t\t\t\t\t\t\t\t\t\t Enter Valid Price : ";
						cin >> price;
					}
					h.pro_unitprice = price;
					delete_item(id);
					ofstream a;
					a.open("Clothing.txt", ios::app);
					a.seekp(0);
					a << endl << h.pro_id << endl << h.pro_name << endl << h.brand << endl << h.cloth_size << endl << h.color << endl << h.cloth_type << endl << h.pro_unitprice << endl << h.pro_stock;					a.close();
					return true;
				}
				else if (c == 4)
				{
					string b;
					cout << "\t\t\t\t\t\t\t\t\t\t SET NEW BRAND OF PRODUCT : ";
					getline(cin, b);
					while (h.setBrand(b) == false)
					{
						getline(cin, b);
					}
					delete_item(id);
					ofstream a;
					a.open("Clothing.txt", ios::app);
					a.seekp(0);
					a << endl << h.pro_id << endl << h.pro_name << endl << h.brand << endl << h.cloth_size << endl << h.color << endl << h.cloth_type << endl << h.pro_unitprice << endl << h.pro_stock;
					a.close();
					return true;
				}
				else if (c == 5)
				{
					string w;
					cout << "\t\t\t\t\t\t\t\t\t\t SET NEW SIZE OF PRODUCT : ";
					getline(cin, w);
					while (h.setSize(w) == false)
					{
						getline(cin, w);
					}
					delete_item(id);
					ofstream a;
					a.open("Clothing.txt", ios::app);
					a.seekp(0);
					a << endl << h.pro_id << endl << h.pro_name << endl << h.brand << endl << h.cloth_size << endl << h.color << endl << h.cloth_type << endl << h.pro_unitprice << endl << h.pro_stock;
					a.close();
					return true;
				}
				else if (c == 6)
				{
					float s;
					cout << "\t\t\t\t\t\t\t\t\t\t ENTER NEW STOCK : ";
					cin >> s;
					while (s < 0)
					{
						cout << "\t\t\t\t\t\t\t\t\t\t ENTER VALID STOCK : ";
						cin >> s;
					}
					h.pro_stock += s;
					delete_item(id);
					ofstream a;
					a.open("Clothing.txt", ios::app);
					a.seekp(0);
					a << endl << h.pro_id << endl << h.pro_name << endl << h.brand << endl << h.cloth_size << endl << h.color << endl << h.cloth_type << endl << h.pro_unitprice << endl << h.pro_stock;					a.close();
					a.close();
					return true;
				}
				else if (c == 7)
				{
					string c;
					cout << "\t\t\t\t\t\t\t\t\t\t SET NEW TYPE OF PRODUCT : ";
					getline(cin, c);
					while (h.setCloth_type(c) == false)
					{
						getline(cin, c);
					}
					delete_item(id);
					ofstream a;
					a.open("Clothing.txt", ios::app);
					a.seekp(0);
					a << endl << h.pro_id << endl << h.pro_name << endl << h.brand << endl << h.cloth_size << endl << h.color << endl << h.cloth_type << endl << h.pro_unitprice << endl << h.pro_stock;
					a.close();
					return true;
				}
				else if (c == 8)
				{
					string c;
					cout << "\t\t\t\t\t\t\t\t\t\t SET NEW COLOR OF PRODUCT : ";
					getline(cin, c);
					while (h.setColor(c) == false)
					{
						getline(cin, c);
					}
					delete_item(id);
					ofstream a;
					a.open("Clothing.txt", ios::app);
					a.seekp(0);
					a << endl << h.pro_id << endl << h.pro_name << endl << h.brand << endl << h.cloth_size << endl << h.color << endl << h.cloth_type << endl << h.pro_unitprice << endl << h.pro_stock;
					a.close();
					return true;
				}
				else if (c == 9)
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

bool Clothing::delete_item(string id)
{
	ifstream deli;
	deli.open("Clothing.txt", ios::in);
	if (!deli)
	{
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t Clothing File Not Exist...";
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
		delo.open("tempCH.txt", ios::app);
		if (!deli)
		{
			cout << "\nClothing File Not Exist...";
		}
		else
		{
			char c;
			c = deli.get();
			while (!deli.eof())
			{
				getline(deli, pro_id);
				getline(deli, pro_name);
				getline(deli, brand);
				getline(deli, cloth_size);
				getline(deli, color);
				getline(deli, cloth_type);
				deli >> pro_unitprice;
				deli >> pro_stock;
				deli.ignore();
				if (id != pro_id)
				{
					delo << endl << pro_id << endl << pro_name << endl << brand << endl << cloth_size << endl << color << endl << cloth_type << endl << pro_unitprice << endl << pro_stock;
				}
				if (id == pro_id)
				{
					counter = 1;
				}
			}
			deli.close();
			delo.close();
			remove("Clothing.txt");
			rename("tempCH.txt", "Clothing.txt");  
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

bool Clothing::show_limited_stock(float s)
{
	if (s < 0) {
		return false;
	}
	ifstream view;
	int check = 0;
	view.open("Clothing.txt", ios::in);
	if (!view)
	{
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t Clothing File Not Exist...";
	}
	else
	{
		char c;
		c = view.get();
		while (!view.eof())
		{
			getline(view, pro_id);
			getline(view, pro_name);
			getline(view, brand);
			getline(view, cloth_size);
			getline(view, color);
			getline(view, cloth_type);
			view >> pro_unitprice;
			view >> pro_stock;
			if (s >= pro_stock) {
				check++;
				if (check == 1)
				{
					cout << "\t\t" << left << setw(15) << "Product ID" << setw(30) << "Product Name"
						<< setw(18) << "Product Brand" << setw(21) << "Cloth Size"
						<< setw(21) << "Cloth Color" << setw(15) << "Cloth Type" << setw(15) << "Unit Price"
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

bool Clothing::show_all_items()
{
	ifstream view;
	int counter = 0;
	view.open("Clothing.txt", ios::in);
	if (!view)
	{
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t Clothing File Not Exist...";
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
				cout << "\t\t" << left << setw(15) << "Product ID" << setw(30) << "Product Name"
					<< setw(18) << "Product Brand" << setw(21) << "Cloth Size"
					<< setw(21) << "Cloth Color" << setw(15) << "Cloth Type" << setw(15) << "Unit Price"
					<< setw(18) << "Product Stock" << endl;
			}
			getline(view, pro_id);
			getline(view, pro_name);
			getline(view, brand);
			getline(view, cloth_size);
			getline(view, color);
			getline(view, cloth_type);
			view >> pro_unitprice;
			view >> pro_stock;
			displayPro();
			view.ignore();
		}
	}
	view.close();
	return true;
}




bool Clothing::updateStock(string id, float s)
{
	fstream update;
	update.open("Clothing.txt");
	if (!update)
	{
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t Clothing File Not Exist...";
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
			getline(update, brand);
			getline(update, cloth_size);
			getline(update, color);
			getline(update, cloth_type);
			update >> pro_unitprice;
			update >> pro_stock;
			update.ignore();
			if (id == pro_id)
			{
				check = 1;
				update.close();
				Clothing c;
				c.pro_id = pro_id;
				c.pro_stock = pro_stock;
				c.pro_unitprice = pro_unitprice;
				c.brand = brand;
				c.cloth_size = cloth_size;
				c.pro_name = pro_name;
				c.color = color;
				c.cloth_type = cloth_type;
				if (pro_stock >= s)
				{
					c.pro_stock -= s;
					delete_item(id);
					ofstream a;
					a.open("Clothing.txt", ios::app);
					a.seekp(0);
					a << endl << c.pro_id << endl << c.pro_name << endl << c.brand << endl << c.cloth_size << endl << c.color << endl << c.cloth_type << endl << c.pro_unitprice << endl << c.pro_stock;
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

Clothing::~Clothing()
{
	cloth_size = "";
	cloth_type = "";
	brand = "";
	color = "";
}
