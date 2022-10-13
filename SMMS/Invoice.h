#pragma once
#include"Product.h"
#include"HomeAppliances.h"
#include"Clothing.h"
#include"UtilityProduct.h"
#include"Customer.h"
#include<ctime>
class Invoice
{
private:
	float P_Quantity[20];
	float p_disc[20];
	string p_id[20];
	float p_totalPrice[20];
	int invoiceid;
	string date_time;
	float totalBill;
	HomeAppliances* h;
	Clothing* c;
	UtilityProducts* e;
	Customer C;
public:
	Invoice();
	bool deleteInvoiceFromHomeAppliances(int id);
	void InvoiceforHomeAppliances();
	bool searchInvoiceofHomeAppliances(int id);
	void showALLInvoiceofHomeAppliances();
	
	bool deleteInvoiceFromClothing(int id);
	void InvoiceforClothing();
	bool searchInvoiceforClothing(int id);
	void showALLInvoiceofClothing();
	
	bool deleteInvoiceFromUtlityProduct(int id);
	void InvoiceforUtlityProduct();
	bool searchInvoiceofUtlityProduct(int id);
	void showALLInvoiceofUtlityProduct();
	~Invoice();
};
