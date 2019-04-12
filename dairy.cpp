#include <iostream>
#include "inventory.h"
#include "dairy.h"

using namespace std;

dairy::dairy()
{
	size = 0;
}

dairy::dairy(string name, string category, float price, int quantity, int Oz)
	:Inventory(name, category, price, quantity)
{
	setSize(Oz);
}

int dairy::getSize() const
{
	return size;
}

void dairy::setSize(int Oz)
{
	size = Oz;
}

void dairy::print()
{
	Inventory::print();
	cout << "Size: " << size << endl;
}