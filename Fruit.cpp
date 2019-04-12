#pragma once
#include <iostream>
#include <string>
#include "inventory.h"
#include "Fruit.h"

using namespace std;


Fruit::Fruit()
{
	color = "Fruit Unknown";
}

Fruit::Fruit(string name, string category, float price, int quantity, string Co)
	:Inventory(name, category, price, quantity)
{
	setColor(Co);
}

void Fruit::setColor(string Co)
{
	color = Co;
}

string Fruit::getColor()
{
	return color;
}

void Fruit::print()
{
	Inventory::print();
	cout << "Fruit: " << color << endl;
}
