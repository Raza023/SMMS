#pragma once
#ifndef EATABLE_H
#define EATABLE_H
#include"Product.h"
using namespace std;
class UtilityProducts :public Product
{
private:
	string mfg_date;
	string expiry_date;
public:
	UtilityProducts();
	bool set_mfg_date(string mfg);
	bool set_expiry_date(string exp);
	string get_mfg_date();
	string get_expiry_date();
	void displayPro();
	bool getProductinfo();
	bool additem();
	UtilityProducts getProduct(string);
	bool updateStock(string id, float s);
	bool search_id(string);
	bool search_Product(string search);
	bool update_Product(string id);
	bool delete_item(string id);
	bool show_limited_stock(float s);
	bool show_all_items();
	~UtilityProducts();
};

#endif // !EATABLE_H
