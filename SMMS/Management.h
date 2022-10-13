#pragma once
#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include <iostream>
#include <string>
#include "Product.h"
#include "Admin.h"
#include <Windows.h>
#include "Invoice.h"
#include <stdlib.h>

using namespace std;

class Management
{
private:
	Product *p;
	Admin ad;
	Invoice *inv;
public:
	Management();
	void Interface();
	~Management();
};

#endif // !MANAGEMENT_H

