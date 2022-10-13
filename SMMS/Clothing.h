#pragma once
#ifndef CLOTHING_H
#define CLOTHING_H
#include "Product.h"
using namespace std;

class Clothing : public Product
{
private:
	string brand;
	string cloth_size;
	string color;
	string cloth_type;
public:
	Clothing();
	bool setBrand(string);
	bool setSize(string);
	bool setColor(string);
	bool setCloth_type(string);
	string getBrand();
	string getSize();
	string getColor();
	string getCloth_type();
	bool getProductinfo();
	void displayPro();

	bool additem();
	bool search_id(string);
	bool search_Product(string);
	bool update_Product(string);
	bool delete_item(string);
	bool show_limited_stock(float);
	bool show_all_items();
	Clothing getProduct(string id);
	bool updateStock(string id, float s);
	~Clothing();
};
#endif // !CLOTHING_H
