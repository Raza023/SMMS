#pragma once
#ifndef HOMEAPPLIANCES_H
#define HOMEAPPLIANCE_H
#include <iostream>
#include <string>
#include"Product.h"

using namespace std;

class HomeAppliances :public Product
{
protected:
	string manufacturer;
	string manufacture_date;
	string warrenty;
public:
	HomeAppliances();
	bool setManufacturer(string);
	bool setManufacture_date(string);
	bool setWarrenty(string);
	string getManufacturer();
	string getManufacture_date();
	string getWarrenty();
	void displayPro();
	bool getProductinfo();

	bool additem();
	bool search_id(string);
	bool search_Product(string);
	bool update_Product(string);
	bool delete_item(string);
	bool show_limited_stock(float s);
	bool show_all_items();
	bool updateStock(string id, float s);
	HomeAppliances getProduct(string);
	~HomeAppliances();
};

#endif // !HOMEAPPLIANCES_H
