#pragma once
#include <iostream>
#include "inventory.h"

using namespace std;

class Fruit : public Inventory 
{
private:
	string color;
public:
	void setColor(string Co);
	string getColor();
	Fruit();
	Fruit(string name, string category, float price, int quantity, string Co);
	void print();
};