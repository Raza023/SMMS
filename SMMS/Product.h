#pragma once
#ifndef PRODUCT_H
#define PROFUCT_H
#include<iostream>
#include <string>
#include<iomanip>
#include<fstream>
#include<stdio.h>
using namespace std;
class Product
{
protected:

	string pro_id;
	string pro_name;
	double pro_unitprice;
	float pro_stock;
public:
	Product();
	bool setPro_id(string);
	bool setPro_name(string);
	bool setPro_unitprice(double);
	bool setPro_stock(float);
	string  getPro_id();
	string  getPro_name();
	double getPro_unitprice();
	float getPro_stock();
	virtual void displayPro() = 0;
	virtual bool getProductinfo() = 0;
	virtual bool additem() = 0;
	virtual bool search_id(string) = 0;
	virtual bool search_Product(string) = 0;
	virtual bool update_Product(string) = 0;
	virtual bool show_limited_stock(float s) = 0;
	virtual bool delete_item(string) = 0;
	virtual bool show_all_items() = 0;
	virtual bool updateStock(string id, float s) = 0;
	virtual ~Product();
};

#endif // !PRODUCT_H
