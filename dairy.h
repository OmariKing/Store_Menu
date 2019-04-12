#pragma once
#include <iostream>
#include "inventory.h"

using namespace std;

class dairy : public Inventory
{
private:
	int size;
public:
	int getSize()const;
	void setSize(int size); 
	dairy();
	dairy(string name, string category, float price, int quantity, int Oz);
	void print();
};