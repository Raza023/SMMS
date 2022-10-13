#include "Management.h"


Management::Management()
{
	inv = NULL;
	p = NULL;
}

void Management::Interface()
{

	system("Color F0");

	cout << "\n\n\t\t\t First of all Maximize your console screen.\n\n" << endl;
	system("pause");
	
	//PlaySound("1_second", NULL, SND_SYNC);

LOGIN:

	system("cls");
	if (ad.login() == true)
	{
		int ch1;
		do
		{
		MENU:
			system("cls");
			cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t SUPER MARKET MANAGEMENT SYSTEM" << endl;
			cout << "\n\n\n";

			cout << "\t\t\t\t\t\t\t\t\t Enter [1] for Admin   Information." << endl;
			cout << "\t\t\t\t\t\t\t\t\t Enter [2] for Product Information." << endl;
			cout << "\t\t\t\t\t\t\t\t\t Enter [3] for Invoice Information." << endl;
			cout << endl;
			cout << "\t\t\t\t\t\t\t\t\t Enter [4] to  Log Out..." << endl;
			cout << "\t\t\t\t\t\t\t\t\t Enter [5] to  Exit..." << endl;
			cout << "\n\t\t\t\t\t\t\t\t\t Enter choice : ";
			cin >> ch1;
			while (ch1 > 5 || ch1 < 1)
			{
				cout << "\n\t\t\t\t\t\t\t\t\t Please Enter Valid Choice : ";
				cin >> ch1;
			}
			if (ch1 == 1)
			{
			ADMIN:
				system("cls");
				cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t---------------------------" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\t         ADMIN LOG" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\t---------------------------" << endl;
				cout << "\n\n\n";

				cout << "\t\t\t\t\t\t\t\t\t Enter [1] to Add New Admin." << endl;
				cout << "\t\t\t\t\t\t\t\t\t Enter [2] to Update Admin Account." << endl;
				cout << "\t\t\t\t\t\t\t\t\t Enter [3] to Delete Admin Account." << endl;
				cout << "\t\t\t\t\t\t\t\t\t Enter [4] to Search Admin Account." << endl;
				cout << "\t\t\t\t\t\t\t\t\t Enter [5] to Display all Admin Accounts." << endl;
				cout << "\t\t\t\t\t\t\t\t\t Enter [6] to Go back to Main Menu..." << endl;
				cout << "\n\t\t\t\t\t\t\t\t\t Enter Choice : ";
				cin >> ch1;
				while (ch1 > 6 || ch1 < 1)
				{
					cout << "\n\t\t\t\t\t\t\t\t\t Please Enter Valid Choice : ";
					cin >> ch1;
				}
				if (ch1 == 1)
				{
					system("cls");
					cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t     CREATING ADMIN ACCOUNT" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
					cout << "\n\n\n";
					cin.ignore();
					if (ad.matchForAdmin() == true)
					{
						if (ad.add_admin() == true)
						{
							system("cls");
							cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
							cout << "\t\t\t\t\t\t\t\t\t\t\t     CREATING ADMIN ACCOUNT" << endl;
							cout << "\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
							cout << "\n\n\n";
							cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t ACCOUNT SUCCESSFULLY ADDED" << endl;
							cout << "\t\t\t\t\t\t\t\t\t\t\t             :) " << endl;
							system("pause");
							goto ADMIN;
						}
					}
					else
					{
						system("cls");
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t     CREATING ADMIN ACCOUNT" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
						cout << "\n\n\n";
						cout << "\t\t\t\t\t\t\t\t\t\t\t You don't have Authority to Add a new Admin" << endl;
						system("pause");
						goto ADMIN;
					}

				}
				else if (ch1 == 2)
				{
					char ch2;
					system("cls");
					cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t     UPDATING ADMIN ACCOUNT" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
					cout << "\n\n\n";
					cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t Are you Sure to Update Your Account (y/n) : ";
					cin >> ch2;
					while (ch2 != 'y' && ch2 != 'n' && ch2 != 'Y' && ch2 != 'N')
					{
						cout << "\t\t\t\t\t\t\t\t\t\t\t Enter Correct Choice (y/n) : ";
						cin >> ch2;
					}
					if (ch2 == 'y' || ch2 == 'Y')
					{
						cin.ignore();
						ad.update_admin(ad.getAdmin_id());
						system("cls");
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t     UPDATING ADMIN ACCOUNT" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
						cout << "\n\n\n";
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t Account Updated Successfully" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t            :)" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t    "; system("pause");
						goto ADMIN;
					}
					else
					{
						goto ADMIN;
					}
				}
				else if (ch1 == 3)
				{
					char ch3, id[20];
					system("cls");
					cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t     DELETING ADMIN ACCOUNT" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
					cout << "\n\n\n";
					if (ad.matchForAdmin() == true)
					{
						cout << "\t\t\t\t\t\t\t\t\t\t\t USERNAME ID : ";
						cin.ignore();
						cin.getline(id, 20);
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t Are you Sure to Delete this Account (y/n) : ";
						cin >> ch3;
						while (ch3 != 'y' && ch3 != 'n' && ch3 != 'Y' && ch3 != 'N')
						{
							cout << "\t\t\t\t\t\t\t\t\t\t\t Enter Correct Choice (y/n) : ";
							cin >> ch3;
						}
						if (ch3 == 'y' || ch3 == 'Y')
						{
							if (ad.delete_admin(id) == false)
							{
								system("cls");
								cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t\t     DELETING ADMIN ACCOUNT" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
								cout << "\n\n\n";
								cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t Account NOT FOUND" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t\t            :(" << endl;
								cout << "\n\t\t\t\t\t\t\t\t\t\t\t    "; 
								system("pause");
							}
							else
							{
								system("cls");
								cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t\t     DELETING ADMIN ACCOUNT" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
								cout << "\n\n\n";
								cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t Account Deleted Successfully" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t\t            :)" << endl;
								cout << "\n\t\t\t\t\t\t\t\t\t\t\t    "; 
								system("pause");
							}
						}

						ifstream login;
						string user, pass2;
						login.open("AdminLogin.txt", ios::in);

						while (!login.eof())
						{
							getline(login, user);
							getline(login, pass2);
						}
						login.close();
						if (user == id)
						{
							cin.ignore();
							goto LOGIN;
						}
						else
						{
							goto ADMIN;
						}
					}
					else {
						system("cls");
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t     DELETING ADMIN ACCOUNT" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
						cout << "\n\n\n";
						cout << "\t\t\t\t\t\t\t\t\t\t\t You don't have Authority to Delete Admin Account" << endl;
						system("pause");
						goto ADMIN;
					}
				}
				else if (ch1 == 4)
				{
					char s[50];
					system("cls");
					cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t     SEARCHING ADMIN ACCOUNT" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
					cout << "\n\n\n";
					cout << "\t\t\t\t\t\t\t\t\t\t\t Enter Account INFO : ";
					cin.ignore();
					cin.getline(s, 50);
					system("cls");
					cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t     SEARCHING ADMIN ACCOUNT" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
					cout << "\n\n\n";

					if (ad.search_admin(s) == false)
					{
						cout << "\t\t\t\t\t\t\t\t\t\t\t NO DATA FOUND." << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t       :(" << endl;
					}
					cout << "\n\t\t\t\t\t\t\t\t\t\t\t    "; 
					system("pause");
					goto ADMIN;
				}
				else if (ch1 == 5)
				{
					system("cls");
					cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t     DISPLAYING ADMIN ACCOUNT" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
					cout << "\n\n\n";

					if (ad.show_all_admin() == false)
					{
						cout << "\t\t\t\t\t\t\t\t\t\t\t NO DATA FOUND." << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t       :(" << endl;
					}
					cout << "\n\t\t\t\t\t\t\t\t\t\t\t    "; system("pause");
					goto ADMIN;
				}
				else if (ch1 == 6)
				{
					goto MENU;
				}
			}
			else if (ch1 == 2)
			{
			PRODUCT:
				system("cls");
				cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t---------------------------" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\t         PRODUCT MENU" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\t---------------------------" << endl;
				cout << "\n\n\n";

				cout << "\t\t\t\t\t\t\t\t\t Enter [1] for Utility Products." << endl;
				cout << "\t\t\t\t\t\t\t\t\t Enter [2] for Home Appliances." << endl;
				cout << "\t\t\t\t\t\t\t\t\t Enter [3] for Clothing." << endl;
				cout << "\t\t\t\t\t\t\t\t\t Enter [4] to  Move To Main Menu." << endl;
				cout << "\n\t\t\t\t\t\t\t\t\t Enter Choice : ";
				cin >> ch1;
				while (ch1 > 4 || ch1 < 1)
				{
					cout << "\n\t\t\t\t\t\t\t\t\t Please Enter Valid Choice : ";
					cin >> ch1;
				}
				if (ch1 == 1)
				{
				UTILITY:
					p = new UtilityProducts;
					system("cls");
					cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t--------------------------" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t      UTILITY PRODUCTS" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t--------------------------" << endl;
					cout << "\n\n\n";

					cout << "\t\t\t\t\t\t\t\t\t Enter [1] to Add Product." << endl;
					cout << "\t\t\t\t\t\t\t\t\t Enter [2] to Update Product." << endl;
					cout << "\t\t\t\t\t\t\t\t\t Enter [3] to Delete Product." << endl;
					cout << "\t\t\t\t\t\t\t\t\t Enter [4] to Search Product." << endl;
					cout << "\t\t\t\t\t\t\t\t\t Enter [5] to Display Limited Stock Products." << endl;
					cout << "\t\t\t\t\t\t\t\t\t Enter [6] to Display all Products." << endl;
					cout << "\t\t\t\t\t\t\t\t\t Enter [7] to Go back to Product Menu..." << endl;
					cout << "\n\t\t\t\t\t\t\t\t\t Enter Choice : ";
					cin >> ch1;
					while (ch1 > 7 || ch1 < 1)
					{
						cout << "\n\t\t\t\t\t\t\t\t\t Please Enter Valid Choice : ";
						cin >> ch1;
					}
					if (ch1 == 1)
					{
						system("cls");
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t--------------------------------" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t   ADDING NEW UTILITY PRODUCT" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t--------------------------------" << endl;
						cout << "\n\n\n";
						cin.ignore();
						if (p->additem() == true)
						{
							system("cls");
							cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t--------------------------------" << endl;
							cout << "\t\t\t\t\t\t\t\t\t\t\t   ADDING NEW UTILITY PRODUCT" << endl;
							cout << "\t\t\t\t\t\t\t\t\t\t\t--------------------------------" << endl;
							cout << "\n\n\n";
							cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t ITEM SUCCESSFULLY ADDED" << endl;
							cout << "\t\t\t\t\t\t\t\t\t\t\t             :) " << endl;
							system("pause");
							delete p;
							p = NULL;
							goto UTILITY;
						}
						else
						{
							system("cls");
							cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t--------------------------------" << endl;
							cout << "\t\t\t\t\t\t\t\t\t\t\t   ADDING NEW UTILITY PRODUCT" << endl;
							cout << "\t\t\t\t\t\t\t\t\t\t\t--------------------------------" << endl;
							cout << "\n\n\n";
							////////////////////////////////////////////////////////////////////////////
							system("pause");
							delete p;
							p = NULL;
							goto UTILITY;
						}
					}
					else if (ch1 == 2)
					{
						char ch2;
						string id;
						system("cls");
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t   UPDATING UTILITY PRODUCT" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
						cout << "\n\n\n";
						cout << "\t\t\t\t\t\t\t\t\t\t\t Product ID : ";
						cin.ignore();
						getline(cin, id);
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t Are you Sure to Update Utility Product Item (y/n) : ";
						cin >> ch2;
						while (ch2 != 'y' && ch2 != 'n' && ch2 != 'Y' && ch2 != 'N')
						{
							cout << "\t\t\t\t\t\t\t\t\t\t\t Enter Correct Choice (y/n) : ";
							cin >> ch2;
						}
						if (ch2 == 'y' || ch2 == 'Y')
						{
							cin.ignore();
							if (p->update_Product(id) == true)
							{
								system("cls");
								cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t\t   UPDATING UTILITY PRODUCT" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
								cout << "\n\n\n";
								cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t UTILITY PRODUCT Updated Successfully" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t\t            :)" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t\t    "; 
								system("pause");
								delete p;
								p = NULL;
								goto UTILITY;
							}
							else 
							{
								system("cls");
								cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t\t   UPDATING UTILITY PRODUCT" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
								cout << "\n\n\n";
								cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t UTILITY PRODUCT NOT Updated " << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t\t            :(" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t\t    "; 
								system("pause");
								delete p;
								p = NULL;
								goto UTILITY;
							}
						}
						else
						{
							delete p;
							p = NULL;
							goto UTILITY;
						}
					}
					else if (ch1 == 3)
					{
						char ch3;
						string id;
						system("cls");
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t   DELETING UTILITY PRODUCT" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
						cout << "\n\n\n";
						cout << "\t\t\t\t\t\t\t\t\t\t\t Product ID : ";
						cin.ignore();
						getline(cin, id);
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t Are you Sure to Delete this Product (y/n) : ";
						cin >> ch3;
						while (ch3 != 'y' && ch3 != 'n' && ch3 != 'Y' && ch3 != 'N')
						{
							cout << "\t\t\t\t\t\t\t\t\t\t\t Enter Correct Choice (y/n) : ";
							cin >> ch3;
						}
						if (ch3 == 'y' || ch3 == 'Y')
						{
							if (p->delete_item(id) == false)
							{
								system("cls");
								cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t\t   DELETING UTILITY PRODUCT" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
								cout << "\n\n\n";
								cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t Product NOT FOUND" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t\t            :(" << endl;
								cout << "\n\t\t\t\t\t\t\t\t\t\t\t    "; system("pause");
								delete p;
								p = NULL;
								goto UTILITY;
							}
							else
							{
								system("cls");
								cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t\t   DELETING UTILITY PRODUCT" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
								cout << "\n\n\n";
								cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t Product Deleted Successfully" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t\t            :)" << endl;
								cout << "\n\t\t\t\t\t\t\t\t\t\t\t    "; system("pause");
								delete p;
								p = NULL;
								goto UTILITY;
							}
						}
						else
						{
							delete p;
							p = NULL;
							goto UTILITY;
						}
					}
					else if (ch1 == 4)
					{
						string s;
						system("cls");
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t-------------------------------" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t   SEARCHING UTILITY PRODUCT" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t-------------------------------" << endl;
						cout << "\n\n\n";
						cout << "\t\t\t\t\t\t\t\t\t\t\t Enter Product INFO : ";
						cin.ignore();
						getline(cin, s);
						system("cls");
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t-------------------------------" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t   SEARCHING UTILITY PRODUCT" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t-------------------------------" << endl;
						cout << "\n\n\n";

						if (p->search_Product(s) == false)
						{
							cout << "\t\t\t\t\t\t\t\t\t\t\t NO DATA FOUND." << endl;
							cout << "\t\t\t\t\t\t\t\t\t\t\t       :(" << endl;
						}
						cout << "\n\t\t\t\t\t\t\t\t\t\t\t    "; system("pause");
						delete p;
						p = NULL;
						goto UTILITY;
					}
					else if (ch1 == 5)
					{
						float s;
						system("cls");
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t------------------------------------------------" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t  DISPLAYING LIMITED STOCK OF UTILITY PRODUCTS" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t------------------------------------------------" << endl;
						cout << "\n\n\n";

						cout << "\n\t\t\t\t\t\t\t\t\t\t\t Show Products where stock is <= : ";
						cin >> s;
						cout << endl << endl;

						if (p->show_limited_stock(s) == false)
						{
							cout << "\t\t\t\t\t\t\t\t\t\t\t NO DATA FOUND." << endl;
							cout << "\t\t\t\t\t\t\t\t\t\t\t       :(" << endl;
						}
						cout << "\n\t\t\t\t\t\t\t\t\t\t\t    "; system("pause");
						delete p;
						p = NULL;
						goto UTILITY;
					}
					else if (ch1 == 6)
					{
						system("cls");
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t-------------------------------" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t  DISPLAYING UTILITY PRODUCTS" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t-------------------------------" << endl;
						cout << "\n\n\n";

						if (p->show_all_items() == false)
						{
							cout << "\t\t\t\t\t\t\t\t\t\t\t NO DATA FOUND." << endl;
							cout << "\t\t\t\t\t\t\t\t\t\t\t       :(" << endl;
						}
						cout << "\n\t\t\t\t\t\t\t\t\t\t\t    "; system("pause");
						goto UTILITY;
					}
					else if (ch1 == 7)
					{
						delete p;
						p = NULL;
						goto PRODUCT;
					}
				}
				else if (ch1 == 2)
				{
				HOME:
					p = new HomeAppliances;
					system("cls");
					cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t---------------------------" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t      HOME APPLAINCES" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t---------------------------" << endl;
					cout << "\n\n\n";

					cout << "\t\t\t\t\t\t\t\t\t Enter [1] to Add Item." << endl;
					cout << "\t\t\t\t\t\t\t\t\t Enter [2] to Update Item." << endl;
					cout << "\t\t\t\t\t\t\t\t\t Enter [3] to Delete Item." << endl;
					cout << "\t\t\t\t\t\t\t\t\t Enter [4] to Search Item." << endl;
					cout << "\t\t\t\t\t\t\t\t\t Enter [5] to Display Limited Stock Items." << endl;
					cout << "\t\t\t\t\t\t\t\t\t Enter [6] to Display all Items." << endl;
					cout << "\t\t\t\t\t\t\t\t\t Enter [7] to Go back to Product Menu..." << endl;
					cout << "\n\t\t\t\t\t\t\t\t\t Enter Choice : ";
					cin >> ch1;
					while (ch1 > 7 || ch1 < 1)
					{
						cout << "\n\t\t\t\t\t\t\t\t\t Please Enter Valid Choice : ";
						cin >> ch1;
					}
					if (ch1 == 1)
					{
						system("cls");
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t-------------------------------" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t   ADDING NEW HOME APPLIANCE" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t-------------------------------" << endl;
						cout << "\n\n\n";
						cin.ignore();
						if (p->additem() == true)
						{
							system("cls");
							cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t-------------------------------" << endl;
							cout << "\t\t\t\t\t\t\t\t\t\t\t   ADDING NEW HOME APPLIANCE" << endl;
							cout << "\t\t\t\t\t\t\t\t\t\t\t-------------------------------" << endl;
							cout << "\n\n\n";
							cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t ITEM SUCCESSFULLY ADDED" << endl;
							cout << "\t\t\t\t\t\t\t\t\t\t\t             :) " << endl;
							system("pause");
							delete p;
							p = NULL;
							goto HOME;
						}
						else
						{
							system("cls");
							cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t-------------------------------" << endl;
							cout << "\t\t\t\t\t\t\t\t\t\t\t   ADDING NEW HOME APPLIANCE" << endl;
							cout << "\t\t\t\t\t\t\t\t\t\t\t-------------------------------" << endl;
							cout << "\n\n\n";
							system("pause");
							delete p;
							p = NULL;
							goto HOME;
						}
					}
					else if (ch1 == 2)
					{
						char ch2;
						string id;
						system("cls");
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t   UPDATING HOME APPLAIANCE" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
						cout << "\n\n\n";
						cout << "\t\t\t\t\t\t\t\t\t\t\t Product ID : ";
						cin.ignore();
						getline(cin, id);
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t Are you Sure to Update Home Appliance Item (y/n) : ";
						cin >> ch2;
						while (ch2 != 'y' && ch2 != 'n' && ch2 != 'Y' && ch2 != 'N')
						{
							cout << "\t\t\t\t\t\t\t\t\t\t\t Enter Correct Choice (y/n) : ";
							cin >> ch2;
						}
						if (ch2 == 'y' || ch2 == 'Y')
						{

							cin.ignore();
							if (p->update_Product(id) == true)
							{
								system("cls");
								cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t\t   UPDATING HOME APPLAIANCE" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
								cout << "\n\n\n";
								cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t HOME APPLAINCE Updated Successfully" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t\t            :)" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t\t    "; system("pause");
								delete p;
								p = NULL;
								goto HOME;
							}
							else {
								system("cls");
								cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t\t   UPDATING HOME APPLAIANCE" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
								cout << "\n\n\n";
								cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t HOME APPLAINCE NOT Updated" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t\t            :(" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t\t    "; system("pause");
								delete p;
								p = NULL;
								goto HOME;
							}
						}
						else
						{
							delete p;
							p = NULL;
							goto HOME;
						}
					}
					else if (ch1 == 3)
					{
						char ch3;
						string id;
						system("cls");
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t    DELETING HOME APPLIANCE" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
						cout << "\n\n\n";
						cout << "\t\t\t\t\t\t\t\t\t\t\t Product ID : ";
						cin.ignore();
						getline(cin, id);
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t Are you Sure to Delete this Item (y/n) : ";
						cin >> ch3;
						while (ch3 != 'y' && ch3 != 'n' && ch3 != 'Y' && ch3 != 'N')
						{
							cout << "\t\t\t\t\t\t\t\t\t\t\t Enter Correct Choice (y/n) : ";
							cin >> ch3;
						}
						if (ch3 == 'y' || ch3 == 'Y')
						{
							if (p->delete_item(id) == false)
							{
								system("cls");
								cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t\t    DELETING HOME APPLIANCE" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
								cout << "\n\n\n";
								cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t ITEM NOT FOUND" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t\t            :(" << endl;
								cout << "\n\t\t\t\t\t\t\t\t\t\t\t    "; system("pause");
								delete p;
								p = NULL;
								goto HOME;
							}
							else
							{
								system("cls");
								cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t\t    DELETING HOME APPLIANCE" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
								cout << "\n\n\n";
								cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t ITEM Deleted Successfully" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t\t            :)" << endl;
								cout << "\n\t\t\t\t\t\t\t\t\t\t\t    "; system("pause");
								delete p;
								p = NULL;
								goto HOME;
							}
						}
						else
						{
							delete p;
							p = NULL;
							goto HOME;
						}
					}
					else if (ch1 == 4)
					{
						string s;
						system("cls");
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t   SEARCHING HOME APPLIANCE" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
						cout << "\n\n\n";
						cout << "\t\t\t\t\t\t\t\t\t\t\t Enter Product INFO : ";
						cin.ignore();
						getline(cin, s);
						system("cls");
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t   SEARCHING HOME APPLIANCE" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
						cout << "\n\n\n";

						if (p->search_Product(s) == false)
						{
							cout << "\t\t\t\t\t\t\t\t\t\t\t NO DATA FOUND." << endl;
							cout << "\t\t\t\t\t\t\t\t\t\t\t       :(" << endl;
						}
						cout << "\n\t\t\t\t\t\t\t\t\t\t\t    "; system("pause");
						delete p;
						p = NULL;
						goto HOME;
					}
					else if (ch1 == 5)
					{
						float s;
						system("cls");
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t-----------------------------------------------" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t  DISPLAYING LIMITED STOCK OF HOME APPLIANCES" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t-----------------------------------------------" << endl;
						cout << "\n\n\n";

						cout << "\n\t\t\t\t\t\t\t\t\t\t\t Show Products where stock is <= : ";
						cin >> s;
						cout << endl << endl;

						if (p->show_limited_stock(s) == false)
						{
							cout << "\t\t\t\t\t\t\t\t\t\t\t NO DATA FOUND." << endl;
							cout << "\t\t\t\t\t\t\t\t\t\t\t       :(" << endl;
						}
						cout << "\n\t\t\t\t\t\t\t\t\t\t\t    "; system("pause");
						delete p;
						p = NULL;
						goto HOME;
					}
					else if (ch1 == 6)
					{
						system("cls");
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t-------------------------------" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t   DISPLAYING HOME APPLIANCES" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t-------------------------------" << endl;
						cout << "\n\n\n";

						if (p->show_all_items() == false)
						{
							cout << "\t\t\t\t\t\t\t\t\t\t\t NO DATA FOUND." << endl;
							cout << "\t\t\t\t\t\t\t\t\t\t\t       :(" << endl;
						}
						cout << "\n\t\t\t\t\t\t\t\t\t\t\t    "; system("pause");
						delete p;
						p = NULL;
						goto HOME;
					}
					else if (ch1 == 7)
					{
						delete p;
						p = NULL;
						goto PRODUCT;
					}
				}
				else if (ch1 == 3)
				{
				CLOTHING:
					p = new Clothing;
					system("cls");
					cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t-------------------------" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t      CLOTHING ITEMS" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t-------------------------" << endl;
					cout << "\n\n\n";

					cout << "\t\t\t\t\t\t\t\t\t Enter [1] to Add Item." << endl;
					cout << "\t\t\t\t\t\t\t\t\t Enter [2] to Update Item." << endl;
					cout << "\t\t\t\t\t\t\t\t\t Enter [3] to Delete Item." << endl;
					cout << "\t\t\t\t\t\t\t\t\t Enter [4] to Search Item." << endl;
					cout << "\t\t\t\t\t\t\t\t\t Enter [5] to Display Limited Stock Items." << endl;
					cout << "\t\t\t\t\t\t\t\t\t Enter [6] to Display all Items." << endl;
					cout << "\t\t\t\t\t\t\t\t\t Enter [7] to Go back to Product Menu..." << endl;
					cout << "\n\t\t\t\t\t\t\t\t\t Enter Choice : ";
					cin >> ch1;
					while (ch1 > 7 || ch1 < 1)
					{
						cout << "\n\t\t\t\t\t\t\t\t\t Please Enter Valid Choice : ";
						cin >> ch1;
					}
					if (ch1 == 1)
					{
						system("cls");
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t--------------------------------" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t   ADDING NEW CLOTHING ITEM" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t--------------------------------" << endl;
						cout << "\n\n\n";
						cin.ignore();
						if (p->additem() == true)
						{
							system("cls");
							cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t--------------------------------" << endl;
							cout << "\t\t\t\t\t\t\t\t\t\t\t   ADDING NEW CLOTHING ITEM" << endl;
							cout << "\t\t\t\t\t\t\t\t\t\t\t--------------------------------" << endl;
							cout << "\n\n\n";
							cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t ITEM SUCCESSFULLY ADDED" << endl;
							cout << "\t\t\t\t\t\t\t\t\t\t\t             :) " << endl;
							system("pause");
							delete p;
							p = NULL;
							goto CLOTHING;
						}
						else
						{
							system("cls");
							cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t--------------------------------" << endl;
							cout << "\t\t\t\t\t\t\t\t\t\t\t   ADDING NEW CLOTHING ITEM" << endl;
							cout << "\t\t\t\t\t\t\t\t\t\t\t--------------------------------" << endl;
							cout << "\n\n\n";
							system("pause");
							delete p;
							p = NULL;
							goto CLOTHING;
						}
					}
					else if (ch1 == 2)
					{
						char ch2;
						string id;
						system("cls");
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t    UPDATING CLOTHING ITEM" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
						cout << "\n\n\n";
						cout << "\t\t\t\t\t\t\t\t\t\t\t Product ID : ";
						cin.ignore();
						getline(cin, id);
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t Are you Sure to Update CLOTHING Item (y/n) : ";
						cin >> ch2;
						while (ch2 != 'y' && ch2 != 'n' && ch2 != 'Y' && ch2 != 'N')
						{
							cout << "\t\t\t\t\t\t\t\t\t\t\t Enter Correct Choice (y/n) : ";
							cin >> ch2;
						}
						if (ch2 == 'y' || ch2 == 'Y')
						{
							cout << "\n\t\t\t\t\t\t\t\t\t\t\t Enter Detail of New Item" << endl;
							cin.ignore();
							p->update_Product(id);

							system("cls");
							cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
							cout << "\t\t\t\t\t\t\t\t\t\t\t    UPDATING CLOTHING ITEM" << endl;
							cout << "\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
							cout << "\n\n\n";
							cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t CLOTHING Item Updated Successfully" << endl;
							cout << "\t\t\t\t\t\t\t\t\t\t\t            :)" << endl;
							cout << "\t\t\t\t\t\t\t\t\t\t\t    "; system("pause");
							delete p;
							p = NULL;
							goto CLOTHING;
						}
						else
						{
							delete p;
							p = NULL;
							goto CLOTHING;
						}
					}
					else if (ch1 == 3)
					{
						char ch3;
						string id;
						system("cls");
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t   DELETING CLOTHING ITEM" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
						cout << "\n\n\n";
						cout << "\t\t\t\t\t\t\t\t\t\t\t Product ID : ";
						cin.ignore();
						getline(cin, id);
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t Are you Sure to Delete this Product (y/n) : ";
						cin >> ch3;
						while (ch3 != 'y' && ch3 != 'n' && ch3 != 'Y' && ch3 != 'N')
						{
							cout << "\t\t\t\t\t\t\t\t\t\t\t Enter Correct Choice (y/n) : ";
							cin >> ch3;
						}
						if (ch3 == 'y' || ch3 == 'Y')
						{
							if (p->delete_item(id) == false)
							{
								system("cls");
								cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t\t   DELETING CLOTHING ITEM" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
								cout << "\n\n\n";
								cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t Product NOT FOUND" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t\t            :(" << endl;
								cout << "\n\t\t\t\t\t\t\t\t\t\t\t    "; system("pause");
								delete p;
								p = NULL;
								goto CLOTHING;
							}
							else
							{
								system("cls");
								cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t\t   DELETING CLOTHING ITEM" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
								cout << "\n\n\n";
								cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t Product Deleted Successfully" << endl;
								cout << "\t\t\t\t\t\t\t\t\t\t\t            :)" << endl;
								cout << "\n\t\t\t\t\t\t\t\t\t\t\t    "; system("pause");
								delete p;
								p = NULL;
								goto CLOTHING;
							}
						}
						else
						{
							delete p;
							p = NULL;
							goto CLOTHING;
						}
					}
					else if (ch1 == 4)
					{
						string s;
						system("cls");
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t-------------------------------" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t    SEARCHING CLOTHING ITEM" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t-------------------------------" << endl;
						cout << "\n\n\n";
						cout << "\t\t\t\t\t\t\t\t\t\t\t Enter Product INFO : ";
						cin.ignore();
						getline(cin, s);
						system("cls");
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t-------------------------------" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t    SEARCHING CLOTHING ITEM" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t-------------------------------" << endl;
						cout << "\n\n\n";

						if (p->search_Product(s) == false)
						{
							cout << "\t\t\t\t\t\t\t\t\t\t\t NO DATA FOUND." << endl;
							cout << "\t\t\t\t\t\t\t\t\t\t\t       :(" << endl;
						}
						cout << "\n\t\t\t\t\t\t\t\t\t\t\t    "; system("pause");
						delete p;
						p = NULL;
						goto CLOTHING;
					}
					else if (ch1 == 5)
					{
						float s;
						system("cls");
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t------------------------------------------------" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t   DISPLAYING LIMITED STOCK OF CLOTHING ITEMS" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t------------------------------------------------" << endl;
						cout << "\n\n\n";

						cout << "\n\t\t\t\t\t\t\t\t\t\t\t Show Products where stock is <= : ";
						cin >> s;
						cout << endl << endl;

						if (p->show_limited_stock(s) == false)
						{
							cout << "\t\t\t\t\t\t\t\t\t\t\t NO DATA FOUND." << endl;
							cout << "\t\t\t\t\t\t\t\t\t\t\t       :(" << endl;
						}
						cout << "\n\t\t\t\t\t\t\t\t\t\t\t    "; system("pause");
						delete p;
						p = NULL;
						goto CLOTHING;
					}
					else if (ch1 == 6)
					{
						system("cls");
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t-------------------------------" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t   DISPLAYING CLOTHING ITEMS" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t-------------------------------" << endl;
						cout << "\n\n\n";

						if (p->show_all_items() == false)
						{
							cout << "\t\t\t\t\t\t\t\t\t\t\t NO DATA FOUND." << endl;
							cout << "\t\t\t\t\t\t\t\t\t\t\t       :(" << endl;
						}
						cout << "\n\t\t\t\t\t\t\t\t\t\t\t    "; system("pause");
						delete p;
						p = NULL;
						goto CLOTHING;
					}
					else if (ch1 == 7)
					{
						delete p;
						p = NULL;
						goto PRODUCT;
					}

				}
				else if (ch1 == 4)
				{
					goto MENU;
				}
			}
			else if (ch1 == 3)
			{

				int ch;
			INVOICE:

				system("cls");
				cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t--------------------------" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\t     INVOICE MANAGEMENT" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\t--------------------------" << endl;
				cout << "\n\n\n";

				cout << "\t\t\t\t\t\t\t\t\t Enter [1] to Create a Invoice." << endl;
				cout << "\t\t\t\t\t\t\t\t\t Enter [2] to Search the Invoice." << endl;
				cout << "\t\t\t\t\t\t\t\t\t Enter [3] to Delete the Invoice." << endl;
				cout << "\t\t\t\t\t\t\t\t\t Enter [4] to Display all Invoices." << endl;
				cout << "\t\t\t\t\t\t\t\t\t Enter [5] to Move to Main Menu." << endl;
				cout << "\n\t\t\t\t\t\t\t\t\t Enter Choice : ";
				cin >> ch;
				while (ch > 5 || ch < 1)
				{
					cout << "\n\t\t\t\t\t\t\t\t\t Please Enter Valid Choice : ";
					cin >> ch;
				}
				if (ch == 1)
				{
				CREATE:
					system("cls");
					cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t-----------------------------" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t      CREATING INVOICE" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t-----------------------------" << endl;
					cout << "\n\n\n";

					cout << "\t\t\t\t\t\t\t\t\t Enter [1] to Create a Invoice of Utility Product." << endl;
					cout << "\t\t\t\t\t\t\t\t\t Enter [2] to Create a Invoice of Home Appliance." << endl;
					cout << "\t\t\t\t\t\t\t\t\t Enter [3] to Create a Invoice of Clothing." << endl;
					cout << "\t\t\t\t\t\t\t\t\t Enter [4] to Move to Invoice Menu." << endl;
					cout << "\n\t\t\t\t\t\t\t\t\t Enter Choice : ";
					cin >> ch1;
					while (ch1 > 4 || ch1 < 1)
					{
						cout << "\n\t\t\t\t\t\t\t\t\t Please Enter Valid Choice : ";
						cin >> ch1;
					}
					if (ch1 == 1)
					{
						inv = new Invoice;
						system("cls");
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t-------------------------------------" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t CREATING INVOICE OF UTILITY PRODUCT" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t-------------------------------------" << endl;
						cout << "\n\n\n";

						cin.ignore();
						inv->InvoiceforUtlityProduct();
						system("pause");
						delete inv;
						inv = NULL;
						goto CREATE;

					}
					else if (ch1 == 2)
					{
						inv = new Invoice;
						system("cls");
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t------------------------------------" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t CREATING INVOICE OF HOME APPLIANCE" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t------------------------------------" << endl;
						cout << "\n\n\n";

						cin.ignore();
						inv->InvoiceforHomeAppliances();
						system("pause");
						delete inv;
						inv = NULL;
						goto CREATE;
					}
					else if (ch1 == 3)
					{
						inv = new Invoice;
						system("cls");
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t--------------------------------" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t  CREATING INVOICE OF CLOTHING" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t--------------------------------" << endl;
						cout << "\n\n\n";

						cin.ignore();
						inv->InvoiceforClothing();
						system("pause");
						delete inv;
						inv = NULL;
						goto CREATE;
					}
					else if (ch1 == 4)
					{
						goto INVOICE;
					}
				}
				else if (ch == 2)
				{
				SEARCH:
					system("cls");
					cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t-----------------------------" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t      SEARCHING INVOICE" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t-----------------------------" << endl;
					cout << "\n\n\n";

					cout << "\t\t\t\t\t\t\t\t\t Enter [1] to Searching a Invoice of Utility Product." << endl;
					cout << "\t\t\t\t\t\t\t\t\t Enter [2] to Searching a Invoice of Home Appliance." << endl;
					cout << "\t\t\t\t\t\t\t\t\t Enter [3] to Searching a Invoice of Clothing." << endl;
					cout << "\t\t\t\t\t\t\t\t\t Enter [4] to Move to Invoice Menu." << endl;
					cout << "\n\t\t\t\t\t\t\t\t\t Enter Choice : ";
					cin >> ch1;
					while (ch1 > 4 || ch1 < 1)
					{
						cout << "\n\t\t\t\t\t\t\t\t\t Please Enter Valid Choice : ";
						cin >> ch1;
					}
					if (ch1 == 1)
					{
						system("cls");
						inv = new Invoice;
						int id;
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t--------------------------------------" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t SEARCHING INVOICE OF UTILITY PRODUCT" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t--------------------------------------" << endl;
						cout << "\n\n\n";

						cout << "\n\t\t\t\t\t\t\t\t\t Enter Invoice ID : ";
						cin >> id;

						if (inv->searchInvoiceofUtlityProduct(id) == false)
						{
							cout << "\n\t\t\t\t\t\t\t\t\t No DATA Found." << endl;
							cout << "\n\t\t\t\t\t\t\t\t\t      :(" << endl;
						}
						system("pause");
						delete inv;
						inv = NULL;
						goto SEARCH;
					}
					else if (ch1 == 2)
					{
						inv = new Invoice;
						system("cls");
						int id;
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t-------------------------------------" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t SEARCHING INVOICE OF HOME APPLIANCE" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t-------------------------------------" << endl;
						cout << "\n\n\n";

						cout << "\n\t\t\t\t\t\t\t\t\t Enter Invoice ID : ";
						cin >> id;

						if (inv->searchInvoiceofHomeAppliances(id) == false)
						{
							cout << "\n\t\t\t\t\t\t\t\t\t No DATA Found." << endl;
							cout << "\n\t\t\t\t\t\t\t\t\t      :(" << endl;
						}
						system("pause");
						delete inv;
						inv = NULL;
						goto SEARCH;
					}
					else if (ch1 == 3)
					{
						inv = new Invoice;
						system("cls");
						int id;
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t-------------------------------" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t  SEARCHING INVOICE OF CLOTHING" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t-------------------------------" << endl;
						cout << "\n\n\n";

						cout << "\n\t\t\t\t\t\t\t\t\t Enter Invoice ID : ";
						cin >> id;

						if (inv->searchInvoiceforClothing(id) == false)
						{
							cout << "\n\t\t\t\t\t\t\t\t\t No DATA Found." << endl;
							cout << "\n\t\t\t\t\t\t\t\t\t      :(" << endl;
						}
						system("pause");
						delete inv;
						inv = NULL;
						goto SEARCH;

					}
					else if (ch1 == 4)
					{
						goto INVOICE;
					}
				}
				else if (ch == 3)
				{
				DELETI:


					system("cls");
					cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t-----------------------------" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t      DELETING INVOICE" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t-----------------------------" << endl;
					cout << "\n\n\n";

					cout << "\t\t\t\t\t\t\t\t\t Enter [1] to Deleting a Invoice of Utility Product." << endl;
					cout << "\t\t\t\t\t\t\t\t\t Enter [2] to Deleting a Invoice of Home Appliance." << endl;
					cout << "\t\t\t\t\t\t\t\t\t Enter [3] to Deleting a Invoice of Clothing." << endl;
					cout << "\t\t\t\t\t\t\t\t\t Enter [4] to Move to Invoice Menu." << endl;
					cout << "\n\t\t\t\t\t\t\t\t\t Enter Choice : ";
					cin >> ch1;
					while (ch1 > 4 || ch1 < 1)
					{
						cout << "\n\t\t\t\t\t\t\t\t\t Please Enter Valid Choice : ";
						cin >> ch1;
					}
					if (ch1 == 1)
					{
						inv = new Invoice;
						system("cls");
						int id;
						char c;
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t-------------------------------------" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t Deleting INVOICE OF UTILITY PRODUCT" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t-------------------------------------" << endl;
						cout << "\n\n\n";

						cout << "\n\t\t\t\t\t\t\t\t\t Enter Invoice ID : ";
						cin >> id;
						cout << "\n\t\t\t\t\t\t\t\t\t Are you sure to Delete (y/n) : ";
						cin >> c;
						while (c != 'y' && c != 'n' && c != 'Y' && c != 'N')
						{
							cout << "\t\t\t\t\t\t\t\t\t\t\t Enter Correct Choice (y/n) : ";
							cin >> c;
						}
						if (c == 'y' || c == 'Y')
						{
							if (inv->deleteInvoiceFromUtlityProduct(id) == true)
							{
								cout << "\n\t\t\t\t\t\t\t\t\t Invoice Deleted Successfully." << endl;
								cout << "\n\t\t\t\t\t\t\t\t\t      :)" << endl;
							}
							else {
								cout << "\n\t\t\t\t\t\t\t\t\t Invoice Not Deleted." << endl;
								cout << "\n\t\t\t\t\t\t\t\t\t Invoice ID not Found." << endl;
								cout << "\n\t\t\t\t\t\t\t\t\t      :(" << endl;
							}
							system("pause");
							delete inv;
							inv = NULL;
							goto DELETI;
						}
						else
						{
							delete inv;
							inv = NULL;
							system("pause");
							goto DELETI;
						}


					}
					else if (ch1 == 2)
					{
						inv = new Invoice;
						system("cls");
						int id;
						char c;
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t------------------------------------" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t DELETING INVOICE OF HOME APPLIANCE" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t------------------------------------" << endl;
						cout << "\n\n\n";

						cout << "\n\t\t\t\t\t\t\t\t\t Enter Invoice ID : ";
						cin >> id;

						cout << "\n\t\t\t\t\t\t\t\t\t Are you sure to Delete (y/n) : ";
						cin >> c;
						while (c != 'y' && c != 'n' && c != 'Y' && c != 'N')
						{
							cout << "\t\t\t\t\t\t\t\t\t\t\t Enter Correct Choice (y/n) : ";
							cin >> c;
						}
						if (c == 'y' || c == 'Y')
						{
							if (inv->deleteInvoiceFromHomeAppliances(id) == true)
							{
								cout << "\n\t\t\t\t\t\t\t\t\t Invoice Deleted Successfully." << endl;
								cout << "\n\t\t\t\t\t\t\t\t\t      :)" << endl;
							}
							else {
								cout << "\n\t\t\t\t\t\t\t\t\t Invoice Not Deleted." << endl;
								cout << "\n\t\t\t\t\t\t\t\t\t Invoice ID not Found." << endl;
								cout << "\n\t\t\t\t\t\t\t\t\t      :(" << endl;
							}
							system("pause");
							delete inv;
							inv = NULL;
							goto DELETI;
						}
						else
						{
							system("pause");
							delete inv;
							inv = NULL;
							goto DELETI;
						}
					}
					else if (ch1 == 3)
					{
						inv = new Invoice;
						system("cls");
						int id;
						char c;
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t--------------------------------" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t  DELETING INVOICE OF CLOTHING" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t--------------------------------" << endl;
						cout << "\n\n\n";

						cout << "\n\t\t\t\t\t\t\t\t\t Enter Invoice ID : ";
						cin >> id;

						cout << "\n\t\t\t\t\t\t\t\t\t Are you sure to Delete (y/n) : ";
						cin >> c;
						while (c != 'y' && c != 'n' && c != 'Y' && c != 'N')
						{
							cout << "\t\t\t\t\t\t\t\t\t\t\t Enter Correct Choice (y/n) : ";
							cin >> c;
						}
						if (c == 'y' || c == 'Y')
						{
							if (inv->deleteInvoiceFromClothing(id) == true)
							{
								cout << "\n\t\t\t\t\t\t\t\t\t Invoice Deleted Successfully." << endl;
								cout << "\n\t\t\t\t\t\t\t\t\t      :)" << endl;
							}
							else {
								cout << "\n\t\t\t\t\t\t\t\t\t Invoice Not Deleted." << endl;
								cout << "\n\t\t\t\t\t\t\t\t\t Invoice ID not Found." << endl;
								cout << "\n\t\t\t\t\t\t\t\t\t      :(" << endl;
							}
							system("pause");
							delete inv;
							inv = NULL;
							goto DELETI;
						}
						else
						{
							system("pause");
							delete inv;
							inv = NULL;
							goto DELETI;
						}
					}
					else if (ch1 == 4)
					{
						goto INVOICE;
					}

				}
				else if (ch == 4)
				{
				DISPLAY:


					system("cls");
					cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t      DISPLAYING INVOICE" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t------------------------------" << endl;
					cout << "\n\n\n";

					cout << "\t\t\t\t\t\t\t\t\t Enter [1] to Display all Invoices of Utility Product." << endl;
					cout << "\t\t\t\t\t\t\t\t\t Enter [2] to Display all Invoices of Home Appliance." << endl;
					cout << "\t\t\t\t\t\t\t\t\t Enter [3] to Display all Invoices of Clothing." << endl;
					cout << "\t\t\t\t\t\t\t\t\t Enter [4] to Move to Invoice Menu." << endl;
					cout << "\n\t\t\t\t\t\t\t\t\t Enter Choice : ";
					cin >> ch1;
					while (ch1 > 4 || ch1 < 1)
					{
						cout << "\n\t\t\t\t\t\t\t\t\t Please Enter Valid Choice : ";
						cin >> ch1;
					}
					if (ch1 == 1)
					{
						inv = new Invoice;
						system("cls");
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t---------------------------------------" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t DISPLAYING INVOICE OF UTILITY PRODUCT" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t---------------------------------------" << endl;
						cout << "\n\n\n";

						inv->showALLInvoiceofUtlityProduct();
						system("pause");
						delete inv;
						inv = NULL;
						goto DISPLAY;

					}
					else if (ch1 == 2)
					{
						inv = new Invoice;
						system("cls");
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t--------------------------------------" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t DISPLAYING INVOICE OF HOME APPLIANCE" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t--------------------------------------" << endl;
						cout << "\n\n\n";

						inv->showALLInvoiceofHomeAppliances();

						system("pause");
						delete inv;
						inv = NULL;
						goto DISPLAY;
					}
					else if (ch1 == 3)
					{
						inv = new Invoice;
						system("cls");
						cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t--------------------------------" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t  DISPLAYING INVOICE OF CLOTHING" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\t--------------------------------" << endl;
						cout << "\n\n\n";

						inv->showALLInvoiceofClothing();

						system("pause");
						delete inv;
						inv = NULL;
						goto DISPLAY;
					}
					else if (ch1 == 4)
					{
						goto INVOICE;
					}
				}
				else if (ch == 5)
				{
					system("cls");
					cin.ignore();
					goto MENU;
				}
			}
			else if (ch1 == 4)
			{
				system("cls");
				cin.ignore();
				goto LOGIN;
			}
			else if (ch1 == 5)
			{
				system("cls");
				cout << "\n\n\n\t\t\t\t Happy Ending" << endl;
				cout << "\n\n\n\t\t\t\t      :)" << endl;
				PlaySound("1_second", NULL, SND_SYNC);

				exit(0);
			}
		} while (ch1 != 5);
	}
}

Management::~Management()
{
	if (p != NULL)
	{
		delete p;
		p = NULL;
	}
	if (inv != NULL)
	{
		delete inv;
		inv = NULL;
	}
}
