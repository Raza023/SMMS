#include "Product.h"
#include"HomeAppliances.h"
#include"UtilityProduct.h"
#include"Clothing.h"
#include <iostream>
#include <string>
using namespace std;
Product::Product()
{
	pro_id = "";
	pro_stock = 0.0;
	pro_name = "";
	pro_unitprice = 0.0;
}
bool Product::setPro_id(string  id)
{
	if (id == "")
	{
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

		pro_id = id;
		return true;
	}
}
bool Product::setPro_name(string n)
{
	if (n == "")
	{
		return false;
	}
	else {
		for (int i = 0; i < n.length(); i++)
		{
			if (n[i] >= 97 && n[i] <= 122)
			{
				n[i] -= 32;
			}
		}

		pro_name = n;
		return true;
	}
}
bool Product::setPro_unitprice(double p)
{
	if (p < 0)
	{
		pro_unitprice = 0;
		return false;
	}
	else
	{
		pro_unitprice = p;
		return true;
	}

}
bool Product::setPro_stock(float s)
{
	if (s < 0) 
	{
		pro_stock = 0;
		return false;
	}
	else 
	{
		pro_stock = s;
		return true;
	}
}
string Product::getPro_id()
{
	return pro_id;
}
string Product::getPro_name()
{
	return pro_name;
}
double Product::getPro_unitprice()
{
	return pro_unitprice;
}
float Product::getPro_stock()
{
	return pro_stock;
}

Product::~Product()
{
	pro_id = "";
	pro_name = "";
	pro_unitprice = 0;
	pro_stock = 0;
}
