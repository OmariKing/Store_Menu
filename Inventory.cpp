#include <iostream>
#include <vector>
#include <string>
#include "inventory.h"

using namespace std;


Inventory::Inventory()
{
	name = "Product Not found";
	category = "Category not listed";
	price = 0.00;
	quantity = 0;
}

Inventory::Inventory(string n, string cat, float pri, int quan)
{
	setName(n);
	setCategory(cat);
	setPrice(pri);
	setQuantity(quan);
}

void Inventory::setName(string n)
{
	name = n;
}

void Inventory::setCategory(string cat)
{
	category = cat;
}

void Inventory::setPrice(float pri)
{
	price = pri;
}

void Inventory::setQuantity(int quan)
{
	if (quan < 0)
	{
		return;
		//cout << "Sorry, we no longer have this product in stock! '\n'";
	}
	quantity = quan;
	
}

void Inventory::makeSale()
{
	if (quantity > 0)
	{
		quantity--;
	}
	else
		cout << "There are no longer any of these items in stock!";
	
}

void Inventory::makeReturn()
{
	quantity++;
}

string Inventory::getName()
{
	return name;
}

string Inventory::getCategory()
{
	return category;
}

float Inventory::getPrice()
{
	return price;
}

int Inventory::getQuantity()
{
	return quantity;
}

void Inventory::print()
{
	cout << "Name: " << name << endl;
	cout << "Price: " << price << endl;
	cout << "Category: " << category << endl;
	cout << "Quantity: " << quantity << endl;
}
