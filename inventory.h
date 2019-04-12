#pragma once
#include <iostream>

using namespace std;

class Inventory
{
private:
	string name;
	string category;
	float price;
	int quantity;

public:
	Inventory();
	Inventory(string n, string cat, float pri, int quan);
	void setName(string n);
	void setCategory(string cat);
	void setPrice(float pri);
	void setQuantity(int quan);
	void makeSale();
	void makeReturn();
	string getName();
	string getCategory();
	float getPrice();
	int getQuantity();
	virtual void print();
};

