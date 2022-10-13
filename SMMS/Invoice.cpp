#include "Invoice.h"
#include<iostream>
using namespace std;

Invoice::Invoice()
{
	for (int i = 0; i < 20; i++)
	{
		P_Quantity[i] = 0.0;
		p_disc[i] = 0.0;
		p_id[i] = "";
		p_totalPrice[i] = 0.0;
	}
	totalBill = 0.0;
	ifstream get;
	get.open("invoiceid.txt");
	get >> invoiceid;
	time_t now = time(0);
	date_time = ctime(&now);
	h = NULL;
	e = NULL;
	c = NULL;
	get.close();

}

void Invoice::InvoiceforHomeAppliances()
{
	int t = 20;
	h = new HomeAppliances[t];
	int i = 0;
	ofstream ai;
	
	char ch;
	ifstream get;
	get.open("invoiceid.txt");
	get >> invoiceid;
	get.close();
	do
	{
		ai.open("Invoice.txt", ios::app);
		string c_name;
		string c_contact;
		if (i == 0)
		{
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t Customer Name : ";
			getline(cin, c_name);
			while (C.setname(c_name) == false)
			{
				cout << "\n\t\t\t\t\t\t\t\t\t\t\t Please Enter Correct Name : ";
				getline(cin, c_name);
			}
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t Customer Contact No. : ";
			getline(cin, c_contact);
			while (C.setcontact_no(c_contact) == false)
			{
				cout << "\n\t\t\t\t\t\t\t\t\t\t\t Please Enter Correct Contact No. : ";
				getline(cin, c_contact);
			}
		}
	JUMP:
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t Enter Product ID : ";
		getline(cin, p_id[i]);
		for (int j = 0; j < p_id[i].length(); j++)
		{
			if (p_id[i][j] >= 97 && p_id[i][j] <= 122)
			{
				p_id[i][j] -= 32;
			}
		}
		HomeAppliances h1;
		if (h[i].search_id(p_id[i]))
		{
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t Product Quantity : ";
			cin >> P_Quantity[i];
			h[i] = h1.getProduct(p_id[i]);
			if (h[i].getPro_stock() >= P_Quantity[i])
			{
				cout << "\n\t\t\t\t\t\t\t\t\t\t\t Discount% on Product : ";
				cin >> p_disc[i];
				while (p_disc[i] < 0 || p_disc[i]>99)
				{
					cout << "\n\t\t\t\t\t\t\t\t\t\t\t Please Enter valid Discount% : ";
					cin >> p_disc[i];
				}
				if (i == 0)
				{
					ai << endl << invoiceid << endl << date_time << C.getname() << endl << C.getcontact_no();
					ofstream uin;
					uin.open("invoiceid.txt");
					uin << invoiceid + 1;
					uin.close();
				}
				p_totalPrice[i] = ((P_Quantity[i] * h[i].getPro_unitprice()) - ((p_disc[i] / 100) * ((P_Quantity[i] * h[i].getPro_unitprice()))));
				totalBill += p_totalPrice[i];
				ai << endl << p_id[i] << endl << h[i].getPro_name() << endl << h[i].getManufacturer() << endl << h[i].getWarrenty() << endl << P_Quantity[i] << endl << p_disc[i] << endl << h[i].getPro_unitprice() << endl << p_totalPrice[i];
				ai.close();
				h1.updateStock(p_id[i], P_Quantity[i]);
			}
			else
			{
				if (h[i].getPro_stock() > 0)
				{
					cout << "\n\t\t\t\t\t\t\t\t\t\t\t Sorry, The Available Quantity is Only " << h[i].getPro_stock() << endl;
					cin.ignore();
					goto JUMP;
				}
				else {
					cout << "\n\t\t\t\t\t\t\t\t\t\t\t Sorry, The Product is Out Of Stock " << endl;
					cin.ignore();
					goto JUMP;
				}

			}
		}
		else
		{
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t That Product NOT EXIST...\n";
			goto JUMP;
		}
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t Want to add another Product : (y/n) : ";
		cin >> ch;
		while (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N') {
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t Enter valid Choice : ";
			cin >> ch;
		}

		i++;

		cin.ignore();
		if ((i == t && (ch != 'n' || ch == 'N')) || (i < t && (ch == 'n' || ch == 'N')) || (i == t && (ch == 'y' || ch == 'Y')) || (i == t && (ch == 'n' || ch == 'N')))
		{
			system("CLS");
			cout << endl << endl;
			for (int s = 0; s < i; s++)
			{
				if (s == 0)
				{
					cout << "\t\t\t\t\t\t\tInvoice ID: " << left << setw(5) << invoiceid << "\t\t" << date_time << endl;
					cout << "\t\t\t---------------------------------------------------------------------------------------------------------------------------------\n\n";
					cout << "\t\t\t" << left << setw(14) << "ID" << left << setw(20) << "Name" << left << setw(20) << "Manufacturer" << left << setw(20) << "Warrenty" << left << setw(14) << "Quantity" << left << setw(14) << "Disc." << left << setw(14) << "Unit. Price" << left << setw(14) << "Total P.Price\n";
					cout << "\t\t\t---------------------------------------------------------------------------------------------------------------------------------\n\n";
				}
				cout << "\t\t\t" << left << setw(14) << p_id[s] << left << setw(20) << h[s].getPro_name()
					<< left << setw(20) << h[s].getManufacturer() << left << setw(20) << h[s].getWarrenty()
					<< left << setw(14) << P_Quantity[s] << left << setw(14) << p_disc[s]
					<< left << setw(14) << h[s].getPro_unitprice()
					<< left << setw(14) << p_totalPrice[s] << endl;
			}
			cout << "\n\n\t\t\t\t\t\t\t\t\t\t" << "TOTAL BILL: " << totalBill << endl << endl;
		}
	} while (i != t && ch != 'n');
	ai.open("invoice.txt", ios::app);
	while (i < t)
	{
		ai << endl << "." << endl << "." << endl << "." << endl << "." << endl << 0.0 << endl << 0.0 << endl << 0.0 << endl << 0.0;
		i++;
	}
	ai << endl << totalBill;
	ai.close();
	delete[] h;
	h = NULL;
}
void Invoice::showALLInvoiceofHomeAppliances()
{
	ifstream view;
	int counter = 0;
	totalBill = 0;
	view.open("invoice.txt", ios::in);
	if (!view)
	{
		cout << "\n\t\t\t\t No data in the file of Home Appliance Invoice..." << endl;
	}
	else
	{
		int i = 0;
		int t = 20;
		h = new HomeAppliances[t];
		do
		{
			char c;
			c = view.get();
			counter++;
			if (counter == 1)
			{
				cout << "\t\t\tINVOICE DATA\n\n";
			}
			for (i = 0; i < t; i++)
			{
				if (i == 0)
				{
					view >> invoiceid;
					view.ignore();
					getline(view, date_time);
					string nam, contact;
					getline(view, nam);
					C.setname(nam);
					getline(view, contact);
					C.setcontact_no(contact);
				}
				getline(view, p_id[i]);
				string p_name;
				getline(view, p_name);
				h[i].setPro_name(p_name);
				string p_manufacturer;
				getline(view, p_manufacturer);
				h[i].setManufacturer(p_manufacturer);
				string warenty;
				getline(view, warenty);
				h[i].setWarrenty(warenty);
				view >> P_Quantity[i];
				view >> p_disc[i];
				float p;
				view >> p;
				h[i].setPro_unitprice(p);
				view >> p_totalPrice[i];
				view.ignore();
			}
			view >> totalBill;
			if (counter >= 1)
			{
				cout << "\t\t\t\t\t\t\tInvoice ID: " << left << setw(5) << invoiceid << "\t\t" << date_time << endl;
				cout << "\t\t\t\t\t\t\t" << "CUS. NAME : " << left << setw(20) << C.getname() << "\t" << C.getcontact_no() << endl;
				cout << "\t\t\t---------------------------------------------------------------------------------------------------------------------------------\n\n";
				cout << "\t\t\t" << left << setw(14) << "ID" << left << setw(20) << "Name" << left << setw(20) << "Manufacturer" << left << setw(20) << "Warrenty" << left << setw(14) << "Quantity" << left << setw(14) << "Disc." << left << setw(14) << "Unit. Price" << left << setw(14) << "Total P.Price\n";
				cout << "\t\t\t---------------------------------------------------------------------------------------------------------------------------------\n\n";
			}
			for (int i = 0; i < t; i++)
			{
				if (p_id[i] != ".")
				{
					cout << "\t\t\t" << left << setw(14) << p_id[i] << left << setw(20) << h[i].getPro_name()
						<< left << setw(20) << h[i].getManufacturer() << left << setw(20) << h[i].getWarrenty()
						<< left << setw(14) << P_Quantity[i] << left << setw(14) << p_disc[i]
						<< left << setw(14) << h[i].getPro_unitprice()
						<< left << setw(14) << p_totalPrice[i] << endl;
				}
				if (i == t - 1)
				{
					cout << "\n\n\t\t\t\t\t\t\t\t\t\t" << "TOTAL BILL: " << totalBill << endl << endl;
				}
			}
		} while (!view.eof());
		delete[] h;
		h = NULL;
	}
	view.close();
}
bool Invoice::searchInvoiceofHomeAppliances(int id)
{
	ifstream view;
	int counter = 0;
	view.open("invoice.txt", ios::in);
	if (!view)
	{
		cout << "\n\t\t\t\t No data in the file of Home Appliance Invoice..." << endl;
	}
	else
	{
		int t = 20;
		h = new HomeAppliances[t];
		int i = 0;
		do
		{
			char c;
			c = view.get();
			counter++;
			if (counter == 1)
			{
				cout << "\t\t\tINVOICE DATA\n\n";
			}
			for (i = 0; i < t; i++)
			{
				if (i == 0)
				{
					view >> invoiceid;
					view.ignore();
					getline(view, date_time);
					string nam, contact;
					getline(view, nam);
					C.setname(nam);
					getline(view, contact);
					C.setcontact_no(contact);

				}
				getline(view, p_id[i]);
				string p_name;
				getline(view, p_name);
				h[i].setPro_name(p_name);
				string p_manufacturer;
				getline(view, p_manufacturer);
				h[i].setManufacturer(p_manufacturer);
				string warenty;
				getline(view, warenty);
				h[i].setWarrenty(warenty);
				view >> P_Quantity[i];
				view >> p_disc[i];
				float p;
				view >> p;
				h[i].setPro_unitprice(p);
				view >> p_totalPrice[i];
				view.ignore();
			}
			view >> totalBill;
			if (counter >= 1 && id == invoiceid)
			{
				cout << "\t\t\t\t\t\t\tInvoice ID: " << left << setw(5) << invoiceid << "\t\t" << date_time << endl;
				cout << "\t\t\t\t\t\t\t" << "CUS. NAME : " << left << setw(20) << C.getname() << "\t" << C.getcontact_no() << endl;
				cout << "\t\t\t---------------------------------------------------------------------------------------------------------------------------------\n\n";
				cout << "\t\t\t" << left << setw(14) << "ID" << left << setw(20) << "Name" << left << setw(20) << "Manufacturer" << left << setw(20) << "Warrenty" << left << setw(14) << "Quantity" << left << setw(14) << "Disc." << left << setw(14) << "Unit. Price" << left << setw(14) << "Total P.Price\n";
				cout << "\t\t\t---------------------------------------------------------------------------------------------------------------------------------\n\n";
			}
			if (id == invoiceid)
			{
				for (int i = 0; i < t; i++)
				{
					if (p_id[i] != ".")
					{
						cout << "\t\t\t" << left << setw(14) << p_id[i] << left << setw(20) << h[i].getPro_name()
							<< left << setw(20) << h[i].getManufacturer() << left << setw(20) << h[i].getWarrenty()
							<< left << setw(14) << P_Quantity[i] << left << setw(14) << p_disc[i]
							<< left << setw(14) << h[i].getPro_unitprice()
							<< left << setw(14) << p_totalPrice[i] << endl;
					}
					if (i == t - 1)
					{
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t" << "TOTAL BILL: " << totalBill << endl << endl;
						delete[] h;
						h = NULL;
						view.close();
						return true;
					}
				}
			}
		} while (!view.eof());
		delete[] h;
		h = NULL;
	}
	view.close();
	return false;
}
bool Invoice::deleteInvoiceFromHomeAppliances(int id)
{
	ifstream deli;
	deli.open("invoice.txt", ios::in);
	if (!deli)
	{
		cout << "\n\t\t\t\t No data in the file of Home Appliance Invoice..." << endl;
		return false;
	}
	else
	{
		int counter = 0, record = 0;
		ofstream delo;
		delo.open("tempInvoiceHA.txt", ios::app);
		if (!deli)
		{
			cout << "\n\t\t\t\t No data in the file of Home Appliance Invoice..." << endl;
		}
		else
		{
			int t = 20;
			h = new HomeAppliances[t];
			int i = 0;
			char c;
			c = deli.get();
			while (!deli.eof())
			{
				for (i = 0; i < t; i++)
				{
					if (i == 0)
					{
						deli >> invoiceid;
						deli.ignore();
						getline(deli, date_time);
						string nam, contact;
						getline(deli, nam);
						C.setname(nam);
						getline(deli, contact);
						C.setcontact_no(contact);
					}
					getline(deli, p_id[i]);
					string p_name;
					getline(deli, p_name);
					h[i].setPro_name(p_name);
					string p_manufacturer;
					getline(deli, p_manufacturer);
					h[i].setManufacturer(p_manufacturer);
					string warenty;
					getline(deli, warenty);
					h[i].setWarrenty(warenty);
					deli >> P_Quantity[i];
					deli >> p_disc[i];
					float p;
					deli >> p;
					h[i].setPro_unitprice(p);
					deli >> p_totalPrice[i];
					deli.ignore();
				}
				record++;
				deli >> totalBill;
				int i = 0;
				if (id != invoiceid)
				{
					for (int s = 0; s < t; s++)
					{
						if (p_id[s] != ".")
						{
							if (s == 0)
							{
								delo << endl << invoiceid << endl << date_time << endl << C.getname() << endl << C.getcontact_no();
							}
							delo << endl << p_id[s] << endl << h[s].getPro_name() << endl << h[s].getManufacturer() << endl << h[s].getWarrenty() << endl << P_Quantity[s] << endl << p_disc[s] << endl << h[s].getPro_unitprice() << endl << p_totalPrice[s];
						}
						else
						{
							delo << endl << "." << endl << "." << endl << "." << endl << "." << endl << 0.0 << endl << 0.0 << endl << 0.0 << endl << 0.0;
						}
					}
					delo << endl << totalBill;
				}
				if (id == invoiceid)
				{
					counter = 1;
				}
			}
			deli.close();
			delo.close();
			remove("invoice.txt");
			rename("tempInvoiceHA.txt", "invoice.txt");
			if (counter == 0)
			{
				delete[] h;
				h = NULL;
				return false;
			}
			else if (counter == 1 && record ==1)
			{
				remove("invoice.txt");
				delete[] h;
				h = NULL;
				return true;
			}
			else
			{
				delete[] h;
				h = NULL;
				return true;
			}
		}
		deli.close();
	}
}


void Invoice::InvoiceforClothing()
{
	int i = 0;
	ofstream ai;
	char ch;
	int t = 20;
	c = new Clothing[t];
	
	ifstream get;
	get.open("invoiceid.txt");
	get >> invoiceid;
	get.close();

	do
	{
		ai.open("invoiceC.txt", ios::app);
		string c_name;
		string c_contact;
		if (i == 0)
		{
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t Customer Name : ";
			getline(cin, c_name);

			while (C.setname(c_name) == false)
			{
				cout << "\n\t\t\t\t\t\t\t\t\t\t\t Please Enter Correct Name : ";
				getline(cin, c_name);

			}
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t Customer Contact No. : ";
			getline(cin, c_contact);
			while (C.setcontact_no(c_contact) == false)
			{
				cout << "\n\t\t\t\t\t\t\t\t\t\t\t Please Enter Correct Contact No. : ";
				getline(cin, c_contact);
			}
		}
	JUMP:
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t Enter Product ID : ";
		getline(cin, p_id[i]);
		for (int j = 0; j < p_id[i].length(); j++)
		{
			if (p_id[i][j] >= 97 && p_id[i][j] <= 122)
			{
				p_id[i][j] -= 32;
			}
		}
		Clothing cl;
		if (c[i].search_id(p_id[i]))
		{
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t Product Quantity : ";
			cin >> P_Quantity[i];
			c[i] = cl.getProduct(p_id[i]);
			if (c[i].getPro_stock() >= P_Quantity[i])
			{
				cout << "\n\t\t\t\t\t\t\t\t\t\t\t Discount% on Product : ";
				cin >> p_disc[i];
				while (p_disc[i] < 0 || p_disc[i]>99)
				{
					cout << "\n\t\t\t\t\t\t\t\t\t\t\t Please Enter valid Discount% : ";
					cin >> p_disc[i];
				}
				if (i == 0)
				{
					ai << endl << invoiceid << endl << date_time << C.getname() << endl << C.getcontact_no();
					ofstream uin;
					uin.open("invoiceid.txt");
					uin << invoiceid + 1;
					uin.close();
				}
				p_totalPrice[i] = ((P_Quantity[i] * c[i].getPro_unitprice()) - ((p_disc[i] / 100) * ((P_Quantity[i] * c[i].getPro_unitprice()))));
				totalBill += p_totalPrice[i];
				ai << endl << p_id[i] << endl << c[i].getPro_name() << endl << c[i].getBrand() << endl << c[i].getSize() << endl << c[i].getColor() << endl << c[i].getCloth_type() << endl << P_Quantity[i] << endl << p_disc[i] << endl << c[i].getPro_unitprice() << endl << p_totalPrice[i];
				ai.close();
				cl.updateStock(p_id[i], P_Quantity[i]);
			}
			else
			{
				if (c[i].getPro_stock() > 0)
				{
					cout << "\n\t\t\t\t\t\t\t\t\t\t\t Sorry, The Available Quantity is Only " << c[i].getPro_stock() << endl;
					cin.ignore();
					goto JUMP;
				}
				else
				{
					cout << "\n\t\t\t\t\t\t\t\t\t\t\t Sorry, The Product is Out of Stock. " << endl;
					cin.ignore();
					goto JUMP;
				}
			}
		}
		else {
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t That Product NOT EXIT...\n";
			goto JUMP;
		}
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t Want to add another item : (y/n) : ";
		cin >> ch;
		while (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N') {
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t Enter valid Choice : ";
			cin >> ch;
		}

		i++;

		cin.ignore();
		if ((i == t && (ch != 'n' || ch == 'N')) || (i < t && (ch == 'n' || ch == 'N')) || (i == t && (ch == 'y' || ch == 'Y')) || (i == t && (ch == 'n' || ch == 'N')))
		{
			system("CLS");
			cout << endl << endl;
			for (int s = 0; s < i; s++)
			{
				if (s == 0)
				{
					cout << "\t\t\t\t\t\t\tInvoice ID: " << left << setw(5) << invoiceid << "\t\t" << date_time << endl;
					cout << "\t\t\t\t\t\t\t" << "CUS. NAME : " << left << setw(20) << C.getname() << "\t" << C.getcontact_no() << endl;
					cout << "\t------------------------------------------------------------------------------------------------------------------------------------------------------\n";
					cout << "\t" << left << setw(14) << "ID" << left << setw(20) << "Name" << left << setw(20) << "Cloth Brand" << left << setw(14) << "Size" << left << setw(14) << "Color" << left << setw(13) << "Type" << left << setw(14) << "Quantity" << left << setw(14) << "Disc." << left << setw(14) << "Unit. Price" << left << setw(14) << "Total P.Price\n";
					cout << "\t------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
				}
				cout << "\t" << left << setw(14) << p_id[s] << left << setw(20) << c[s].getPro_name()
					<< left << setw(20) << c[s].getBrand() << left << setw(14) << c[s].getSize() << left << setw(14) << c[s].getColor() << left << setw(13) << c[s].getCloth_type()
					<< left << setw(14) << P_Quantity[s] << left << setw(14) << p_disc[s]
					<< left << setw(14) << c[s].getPro_unitprice()
					<< left << setw(14) << p_totalPrice[s] << endl;
			}
			cout << "\n\n\t\t\t\t\t\t\t\t\t\t" << "TOTAL BILL: " << totalBill << endl << endl;
		}
	} while (i != t && ch != 'n');
	ai.open("invoiceC.txt", ios::app);
	while (i < t)
	{
		ai << endl << "." << endl << "." << endl << "." << endl << "." << endl << "." << endl << "." << endl << 0.0 << endl << 0.0 << endl << 0.0 << endl << 0.0;
		i++;
	}
	ai << endl << totalBill;
	ai.close();
	delete[] c;
	c = NULL;
}
void Invoice::showALLInvoiceofClothing()
{

	ifstream view;
	int counter = 0;
	totalBill = 0;
	view.open("invoiceC.txt", ios::in);
	if (!view)
	{
		cout << "\n\t\t\t\t No data in the file of Clothing Invoice..." << endl;
	}
	else
	{
		int t = 20;
		c = new Clothing[t];
		int i = 0;
		do
		{
			char ch;
			ch = view.get();
			counter++;
			if (counter == 1)
			{
				cout << "\t\t\tINVOICE DATA\n\n";
			}
			for (i = 0; i < t; i++)
			{
				if (i == 0)
				{
					view >> invoiceid;
					view.ignore();
					getline(view, date_time);
					string nam, contact;
					getline(view, nam);
					C.setname(nam);
					getline(view, contact);
					C.setcontact_no(contact);

				}
				getline(view, p_id[i]);
				string p_name;
				getline(view, p_name);
				c[i].setPro_name(p_name);
				string p_brand;
				getline(view, p_brand);
				c[i].setBrand(p_brand);
				string cloth_size;
				getline(view, cloth_size);
				c[i].setSize(cloth_size);
				string color;
				getline(view, color);
				c[i].setColor(color);
				string cloth_type;
				getline(view, cloth_type);
				c[i].setCloth_type(cloth_type);
				view >> P_Quantity[i];
				view >> p_disc[i];
				float p;
				view >> p;
				c[i].setPro_unitprice(p);
				view >> p_totalPrice[i];
				view.ignore();
			}
			view >> totalBill;
			if (counter >= 1)
			{
				cout << "\t\t\t\t\t\t\tInvoice ID: " << left << setw(5) << invoiceid << "\t\t" << date_time << endl;
				cout << "\t\t\t\t\t\t\t" << "CUS. NAME : " << left << setw(20) << C.getname() << "\t" << C.getcontact_no() << endl;
				cout << "\t------------------------------------------------------------------------------------------------------------------------------------------------------\n";
				cout << "\t" << left << setw(14) << "ID" << left << setw(20) << "Name" << left << setw(20) << "Cloth Brand" << left << setw(14) << "Size" << left << setw(14) << "Color" << left << setw(13) << "Type" << left << setw(14) << "Quantity" << left << setw(14) << "Disc." << left << setw(14) << "Unit. Price" << left << setw(14) << "Total P.Price\n";
				cout << "\t------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
			}
			for (int i = 0; i < t; i++)
			{
				if (p_id[i] != ".")
				{

					cout << "\t" << left << setw(14) << p_id[i] << left << setw(20) << c[i].getPro_name()
						<< left << setw(20) << c[i].getBrand() << left << setw(14) << c[i].getSize() << left << setw(14) << c[i].getColor() << left << setw(13) << c[i].getCloth_type()
						<< left << setw(14) << P_Quantity[i] << left << setw(14) << p_disc[i]
						<< left << setw(14) << c[i].getPro_unitprice()
						<< left << setw(14) << p_totalPrice[i] << endl;
				}
				if (i == t - 1)
				{
					cout << "\n\n\t\t\t\t\t\t\t\t\t\t" << "TOTAL BILL: " << totalBill << endl << endl;
				}
			}
		} while (!view.eof());
		delete[] c;
		c = NULL;
	}

	view.close();
}
bool Invoice::searchInvoiceforClothing(int id)
{
	ifstream view;
	int counter = 0;
	view.open("invoiceC.txt", ios::in);
	if (!view)
	{
		cout << "\n\t\t\t\t No data in the file of Clothing Invoice..." << endl;
	}
	else
	{
		int t = 20;
		c = new Clothing[t];
		int i = 0;
		do
		{
			char ch;
			ch = view.get();
			counter++;
			if (counter == 1)
			{
				cout << "\t\t\tINVOICE DATA\n\n";
			}
			for (i = 0; i < t; i++)
			{
				if (i == 0)
				{
					view >> invoiceid;
					view.ignore();
					getline(view, date_time);
					string nam, contact;
					getline(view, nam);
					C.setname(nam);
					getline(view, contact);
					C.setcontact_no(contact);

				}
				getline(view, p_id[i]);
				string p_name;
				getline(view, p_name);
				c[i].setPro_name(p_name);
				string p_brand;
				getline(view, p_brand);
				c[i].setBrand(p_brand);
				string cloth_size;
				getline(view, cloth_size);
				c[i].setSize(cloth_size);
				string color;
				getline(view, color);
				c[i].setColor(color);
				string cloth_type;
				getline(view, cloth_type);
				c[i].setCloth_type(cloth_type);
				view >> P_Quantity[i];
				view >> p_disc[i];
				float p;
				view >> p;
				c[i].setPro_unitprice(p);
				view >> p_totalPrice[i];
				view.ignore();
			}
			view >> totalBill;
			if (counter >= 1 && id == invoiceid)
			{
				cout << "\t\t\t\t\t\t\tInvoice ID: " << left << setw(5) << invoiceid << "\t\t" << date_time << endl;
				cout << "\t\t\t\t\t\t\t" << "CUS. NAME : " << left << setw(20) << C.getname() << "\t" << C.getcontact_no() << endl;
				cout << "\t------------------------------------------------------------------------------------------------------------------------------------------------------\n";
				cout << "\t" << left << setw(14) << "ID" << left << setw(20) << "Name" << left << setw(20) << "Cloth Brand" << left << setw(14) << "Size" << left << setw(14) << "Color" << left << setw(13) << "Type" << left << setw(14) << "Quantity" << left << setw(14) << "Disc." << left << setw(14) << "Unit. Price" << left << setw(14) << "Total P.Price\n";
				cout << "\t------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
			}
			if (id == invoiceid)
			{
				for (int i = 0; i < t; i++)
				{
					if (p_id[i] != ".")
					{
						cout << "\t" << left << setw(14) << p_id[i] << left << setw(20) << c[i].getPro_name()
							<< left << setw(20) << c[i].getBrand() << left << setw(14) << c[i].getSize() << left << setw(14) << c[i].getColor() << left << setw(13) << c[i].getCloth_type()
							<< left << setw(14) << P_Quantity[i] << left << setw(14) << p_disc[i]
							<< left << setw(14) << c[i].getPro_unitprice()
							<< left << setw(14) << p_totalPrice[i] << endl;
					}
					if (i == t - 1)
					{
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t" << "TOTAL BILL: " << totalBill << endl << endl;
						delete[] c;
						c = NULL;
						view.close();
						return true;
					}
				}
			}
		} while (!view.eof());
		delete[] c;
		c = NULL;
	}
	view.close();
	return false;
}
bool Invoice::deleteInvoiceFromClothing(int id)
{
	ifstream deli;
	deli.open("invoiceC.txt", ios::in);
	if (!deli)
	{
		cout << "\n\t\t\t\t No data in the file of Clothing Invoice..." << endl;
		return false;
	}
	else
	{
		int counter = 0, record = 0;
		ofstream delo;
		delo.open("tempInvoiceHA.txt", ios::app);
		if (!deli)
		{
			cout << "\n Invoice File Not Exist...";
		}
		else
		{
			int i = 0;
			char c1;
			int t = 20;
			c = new Clothing[t];
			c1 = deli.get();
			while (!deli.eof())
			{
				for (i = 0; i < t; i++)
				{
					if (i == 0)
					{
						deli >> invoiceid;
						deli.ignore();
						getline(deli, date_time);
						string nam, contact;
						getline(deli, nam);
						C.setname(nam);
						getline(deli, contact);
						C.setcontact_no(contact);

					}
					getline(deli, p_id[i]);
					string p_name;
					getline(deli, p_name);
					c[i].setPro_name(p_name);
					string p_brand;
					getline(deli, p_brand);
					c[i].setBrand(p_brand);
					string cloth_size;
					getline(deli, cloth_size);
					c[i].setSize(cloth_size);
					string color;
					getline(deli, color);
					c[i].setColor(color);
					string cloth_type;
					getline(deli, cloth_type);
					c[i].setCloth_type(cloth_type);

					deli >> P_Quantity[i];
					deli >> p_disc[i];
					float p;
					deli >> p;
					c[i].setPro_unitprice(p);
					deli >> p_totalPrice[i];
					deli.ignore();
				}
				record++;
				deli >> totalBill;
				int i = 0;
				if (id != invoiceid)
				{
					for (int s = 0; s < t; s++)
					{
						if (p_id[s] != ".")
						{
							if (s == 0)
							{
								delo << endl << invoiceid << endl << date_time << endl << C.getname() << endl << C.getcontact_no();
							}
							delo << endl << p_id[s] << endl << c[s].getPro_name() << endl << c[s].getBrand() << endl << c[s].getSize() << endl << c[s].getColor() << endl << c[s].getCloth_type() << endl << P_Quantity[s] << endl << p_disc[s] << endl << c[i].getPro_unitprice() << endl << p_totalPrice[s];

						}
						else
						{
							delo << endl << "." << endl << "." << endl << "." << endl << "." << endl << "." << endl << "." << endl << 0.0 << endl << 0.0 << endl << 0.0 << endl << 0.0;
						}
					}
					delo << endl << totalBill;
				}
				if (id == invoiceid)
				{
					counter = 1;
				}
			}
			deli.close();
			delo.close();
			remove("invoiceC.txt");
			rename("tempInvoiceHA.txt", "invoiceC.txt");
			if (counter == 0)
			{
				delete[] c;
				c = NULL;
				return false;
			}
			else if (counter ==1 && record  == 1)
			{
				remove("invoiceC.txt");
				delete[] c;
				c = NULL;
				return true;
			}
			else {
				delete[] c;
				c = NULL;
				return true;
			}
		}
		deli.close();
	}
}

void Invoice::InvoiceforUtlityProduct()
{
	int i = 0;
	ofstream ai;
	char ch;
	int t = 20;
	e = new UtilityProducts[t];
	totalBill = 0;
	ifstream get;
	get.open("invoiceid.txt");
	get >> invoiceid;
	get.close();

	do
	{
		ai.open("InvoiceUP.txt", ios::app);
		string c_name;
		string c_contact;
		if (i == 0)
		{
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t Customer Name : ";
			getline(cin, c_name);

			while (C.setname(c_name) == false)
			{
				cout << "\n\t\t\t\t\t\t\t\t\t\t\t Please Enter Correct Name : ";
				getline(cin, c_name);

			}
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t Customer Contact No. : ";
			getline(cin, c_contact);
			while (C.setcontact_no(c_contact) == false)
			{
				cout << "\n\t\t\t\t\t\t\t\t\t\t\t Please Enter Correct Contact No. : ";
				getline(cin, c_contact);
			}
		}
	JUMP:
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t Product ID : ";
		getline(cin, p_id[i]);
		for (int j = 0; j < p_id[i].length(); j++)
		{
			if (p_id[i][j] >= 97 && p_id[i][j] <= 122)
			{
				p_id[i][j] -= 32;
			}
		}
		UtilityProducts e1;
		if (e[i].search_id(p_id[i]))
		{
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t Product Quantity : ";
			cin >> P_Quantity[i];
			e[i] = e1.getProduct(p_id[i]);
			if (e[i].getPro_stock() >= P_Quantity[i])
			{
				cout << "\n\t\t\t\t\t\t\t\t\t\t\t Discount% on Product : ";
				cin >> p_disc[i];
				while (p_disc[i] < 0 || p_disc[i]>99)
				{
					cout << "\n\t\t\t\t\t\t\t\t\t\t\t Please Enter valid Discount% : ";
					cin >> p_disc[i];
				}
				if (i == 0)
				{
					ai << endl << invoiceid << endl << date_time ;
					ai << C.getname() << endl << C.getcontact_no();
					ofstream uin;
					uin.open("invoiceid.txt");
					uin << invoiceid + 1;
					uin.close();
				}
				p_totalPrice[i] = ((P_Quantity[i] * e[i].getPro_unitprice()) - ((p_disc[i] / 100) * (P_Quantity[i] * e[i].getPro_unitprice())));
				totalBill += p_totalPrice[i];
				ai << endl << p_id[i] << endl << e[i].getPro_name() << endl << e[i].get_mfg_date() << endl << e[i].get_expiry_date() << endl << P_Quantity[i] << endl << p_disc[i] << endl << e[i].getPro_unitprice() << endl << p_totalPrice[i];
				ai.close();
				e1.updateStock(p_id[i], P_Quantity[i]);
			}
			else
			{
				if (e[i].getPro_stock() > 0)
				{
					cout << "\n\t\t\t\t\t\t\t\t\t\t\t Sorry, The Available Quantity is Only " << e[i].getPro_stock() << endl;
					cin.ignore();
					goto JUMP;
				}
				else {
					cout << "\n\t\t\t\t\t\t\t\t\t\t\t Sorry, The Product is Out Stock " << endl;
					cin.ignore();
					goto JUMP;
				}

			}
		}
		else
		{
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t That Product NOT EXIST...\n";
			goto JUMP;
		}
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t Want to add another item : (y/n) : ";
		cin >> ch;
		while (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N') {
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t Enter valid Choice : ";
			cin >> ch;
		}

		i++;

		cin.ignore();
		if ((i == t && (ch != 'n' || ch == 'N')) || (i < t && (ch == 'n' || ch == 'N')) || (i == t && (ch == 'y' || ch == 'Y')) || (i == t && (ch == 'n' || ch == 'N')))
		{
			system("CLS");
			cout << endl << endl;
			for (int s = 0; s < i; s++)
			{
				if (s == 0)
				{
					cout << "\t\t\t\t\t\t\tInvoice ID: " << left << setw(5) << invoiceid << "\t\t" << date_time << endl;
					cout << "\t\t\t------------------------------------------------------------------------------------------------------------\n\n";
					cout << "\t\t\t" << left << setw(14) << "ID" << left << setw(20) << "Name" << left << setw(20) << "EXP date" << left << setw(14) << "Quantity" << left << setw(14) << "Disc." << left << setw(14) << "Unit. Price" << left << setw(14) << "Total P.Price\n\n";
					cout << "\t\t\t------------------------------------------------------------------------------------------------------------\n\n";
				}
				cout<< "\t\t\t" 
					<< left << setw(14) << p_id[s] 
					<< left << setw(20) << e[s].getPro_name()
					<< left << setw(20) << e[s].get_expiry_date()
					<< left << setw(14) << P_Quantity[s] 
					<< left << setw(14) << p_disc[s]
					<< left << setw(14) << e[s].getPro_unitprice()
					<< left << setw(14) << p_totalPrice[s] << endl;
			}
			cout << "\n\n\t\t\t\t\t\t\t\t\t\t" << "TOTAL BILL: " << totalBill << endl << endl;
		}
	} while (i != t && ch != 'n');
	ai.open("InvoiceUP.txt", ios::app);
	while (i < t)
	{
		ai << endl << "." << endl << "." << endl << "." << endl << "." << endl << 0.0 << endl << 0.0 << endl << 0.0 << endl << 0.0;
		i++;
	}
	ai << endl << totalBill;
	ai.close();
	delete[] e;
	e = NULL;
}
bool Invoice::deleteInvoiceFromUtlityProduct(int id)
{
	ifstream deli;
	deli.open("InvoiceUP.txt", ios::in);
	if (!deli)
	{
		cout << "\n\t\t\t\t No data in the file of Utility Invoice..." << endl;
		return false;
	}
	else
	{
		int counter = 0, record = 0;
		ofstream delo;
		delo.open("tempInvoiceUP.txt", ios::app);
		if (!deli)
		{
			cout << "\n\t\t\t\t No data in the file of Utility Product..." << endl;
		}
		else
		{
			int t = 20;
			e = new UtilityProducts[t];
			int i = 0;
			char c;
			c = deli.get();
			while (!deli.eof())
			{
				for (i = 0; i < t; i++)
				{
					if (i == 0)
					{
						deli >> invoiceid;
						deli.ignore();
						getline(deli, date_time);
						
						string nam, contact;
						getline(deli, nam);
						C.setname(nam);
						getline(deli, contact);
						C.setcontact_no(contact);
					}
					getline(deli, p_id[i]);
					string p_name;
					getline(deli, p_name);
					e[i].setPro_name(p_name);
					string p_mfg;
					getline(deli, p_mfg);
					e[i].set_mfg_date(p_mfg);
					string exp;
					getline(deli, exp);
					e[i].set_expiry_date(exp);
					deli >> P_Quantity[i];
					deli >> p_disc[i];
					float p;
					deli >> p;
					e[i].setPro_unitprice(p);
					deli >> p_totalPrice[i];
					deli.ignore();
				}
				record++;
				deli >> totalBill;
				int i = 0;
				if (id != invoiceid)
				{
					for (int s = 0; s < t; s++)
					{
						if (p_id[s] != ".")
						{
							if (s == 0)
							{
								delo << endl << invoiceid << endl << date_time << endl << C.getname() << endl << C.getcontact_no();
							}
							delo << endl << p_id[s] << endl << e[s].getPro_name() << endl << e[s].get_mfg_date() << endl << e[s].get_expiry_date() << endl << P_Quantity[s] << endl << p_disc[s] << endl << e[s].getPro_unitprice() << endl << p_totalPrice[s];
						}
						else
						{
							delo << endl << "." << endl << "." << endl << "." << endl << "." << endl << 0.0 << endl << 0.0 << endl << 0.0 << endl << 0.0;
						}
					}
					delo << endl << totalBill;
				}
				if (id == invoiceid)
				{
					counter = 1;
				}
			}
			deli.close();
			delo.close();
			remove("InvoiceUP.txt");
			rename("tempInvoiceUP.txt", "InvoiceUP.txt");
			if (counter == 0)
			{
				delete[] e;
				e = NULL;
				deli.close();
				return false;
			}
			else if (counter == 1 && record == 1)
			{
				remove("InvoiceUP.txt");
				delete[] e;
				e = NULL;
				deli.close();
				return true;
			}
			else
			{
				delete[] e;
				e = NULL;
				deli.close();
				return true;
			}
		}
		deli.close();
	}
}
bool Invoice::searchInvoiceofUtlityProduct(int id)
{
	ifstream view;
	int counter = 0;
	view.open("InvoiceUP.txt", ios::in);
	if (!view)
	{
		cout << "\n\t\t\t\t No data in the file of Utility Invoice..." << endl;
	}
	else
	{
		int t = 20;
		e = new UtilityProducts[t];
		int i = 0;
		do
		{
			char c;
			c = view.get();
			counter++;
			if (counter == 1)
			{
				cout << "\t\t\tINVOICE DATA\n\n";
			}
			for (i = 0; i < t; i++)
			{
				if (i == 0)
				{
					view >> invoiceid;
					view.ignore();
					getline(view, date_time);
					string nam, contact;
					getline(view, nam);
					C.setname(nam);
					getline(view, contact);
					C.setcontact_no(contact);

				}
				getline(view, p_id[i]);
				string p_name;
				getline(view, p_name);
				e[i].setPro_name(p_name);
				string p_mfg;
				getline(view, p_mfg);
				e[i].set_mfg_date(p_mfg);
				string exp;
				getline(view, exp);
				e[i].set_expiry_date(exp);
				view >> P_Quantity[i];
				view >> p_disc[i];
				float p;
				view >> p;
				e[i].setPro_unitprice(p);
				view >> p_totalPrice[i];
				view.ignore();
			}
			view >> totalBill;
			if (counter >= 1 && id == invoiceid)
			{
				cout << "\t\t\t\t\t\t\tInvoice ID: " << left << setw(5) << invoiceid << "\t\t" << date_time << endl;
				cout << "\t\t\t\t\t\t\t" << "CUS. NAME : " << left << setw(20) << C.getname() << "\t" << C.getcontact_no() << endl;
				cout << "\t\t\t------------------------------------------------------------------------------------------------------------\n\n";
				cout << "\t\t\t" << left << setw(14) << "ID" << left << setw(20) << "Name" << left << setw(20) << "EXP date" << left << setw(14) << "Quantity" << left << setw(14) << "Disc." << left << setw(14) << "Unit. Price" << left << setw(14) << "Total P.Price\n\n";
				cout << "\t\t\t------------------------------------------------------------------------------------------------------------\n\n";
			}
			if (id == invoiceid)
			{
				for (int i = 0; i < t; i++)
				{
					if (p_id[i] != ".")
					{
						cout << "\t\t\t" << left << setw(14) << p_id[i] << left << setw(20) << e[i].getPro_name()
							<< left << setw(20) << e[i].get_expiry_date()
							<< left << setw(14) << P_Quantity[i] << left << setw(14) << p_disc[i]
							<< left << setw(14) << e[i].getPro_unitprice()
							<< left << setw(14) << p_totalPrice[i] << endl;
					}
					if (i == t - 1)
					{
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t" << "TOTAL BILL: " << totalBill << endl << endl;
						delete[] e;
						e = NULL;
						view.close();
						return true;
					}
				}
			}
		} while (!view.eof());
		delete[] e;
		e = NULL;
	}
	view.close();
	return false;
}
void Invoice::showALLInvoiceofUtlityProduct()
{
	ifstream view;
	int counter = 0;
	view.open("InvoiceUP.txt", ios::in);
	if (!view)
	{
		cout << "\n\t\t\t\t No data in the file of Utility Invoice..." << endl;
	}
	else
	{
		int t = 20;
		e = new UtilityProducts[t];
		int i = 0;
		do
		{
			char c;
			c = view.get();
			counter++;
			if (counter == 1)
			{
				cout << "\t\t\tINVOICE DATA\n\n";
			}
			for (i = 0; i < t; i++)
			{
				if (i == 0)
				{
					view >> invoiceid;
					view.ignore();
					getline(view, date_time);
					
					string nam, contact;
					getline(view, nam);
					C.setname(nam);
					getline(view, contact);
					C.setcontact_no(contact);

				}
				getline(view, p_id[i]);
				string p_name;
				getline(view, p_name);
				e[i].setPro_name(p_name);
				string p_mfg;
				getline(view, p_mfg);
				e[i].set_mfg_date(p_mfg);
				string exp;
				getline(view, exp);
				e[i].set_expiry_date(exp);
				view >> P_Quantity[i];
				view >> p_disc[i];
				float p;
				view >> p;
				e[i].setPro_unitprice(p);
				view >> p_totalPrice[i];
				view.ignore();
			}
			view >> totalBill;
			if (counter >= 1)
			{
				cout << "\t\t\t\t\t\t\tInvoice ID: " << left << setw(5) << invoiceid << "\t\t" << date_time << endl;
				cout << "\t\t\t\t\t\t\t" << "CUS. NAME : " << left << setw(20) << C.getname() << "\t" << C.getcontact_no() << endl;
				cout << "\t\t\t------------------------------------------------------------------------------------------------------------\n\n";
				cout << "\t\t\t" << left << setw(14) << "ID" << left << setw(20) << "Name" << left << setw(20) << "EXP date" << left << setw(14) << "Quantity" << left << setw(14) << "Disc." << left << setw(14) << "Unit. Price" << left << setw(14) << "Total P.Price\n\n";
				cout << "\t\t\t------------------------------------------------------------------------------------------------------------\n\n";
			}
			for (int i = 0; i < t; i++)
			{
				if (p_id[i] != ".")
				{
					cout << "\t\t\t" << left << setw(14) << p_id[i] << left << setw(20) << e[i].getPro_name()
						<< left << setw(20) << e[i].get_expiry_date()
						<< left << setw(14) << P_Quantity[i] << left << setw(14) << p_disc[i]
						<< left << setw(14) << e[i].getPro_unitprice()
						<< left << setw(14) << p_totalPrice[i] << endl;
				}
				if (i == t - 1)
				{
					cout << "\n\n\t\t\t\t\t\t\t\t\t\t" << "TOTAL BILL: " << totalBill << endl << endl;
				}
			}
		} while (!view.eof());
		delete[] e;
		e = NULL;
	}
	view.close();
}

Invoice::~Invoice()
{
	if (h != NULL)
	{
		delete[] h;
		h = NULL;
	}
	if (c != NULL)
	{
		delete[] c;
		c = NULL;
	}
	if (e != NULL)
	{
		delete[] e;
		e = NULL;
	}
}
