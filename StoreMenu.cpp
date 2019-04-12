#include <iostream>
#include <string>
#include <vector>
#include "inventory.h"
#include "Fruit.h"
#include "dairy.h"

using namespace std;
////////////////////////////////////////////////////
//This program is meant to act as a menu for the 
//employee to use for the store using different 
//functions to manage items 
////////////////////////////////////////////////////
Inventory In;
Fruit Fr;
dairy da;

//Function to load the Inventory vector using the classes as well
void Load(vector<Inventory*> &I)
{
	//Hard coded products to start off with
	I.push_back(new Fruit("strawberry", "fruit", static_cast<float>(2.99), 6, "Red"));
	I.push_back(new Fruit("apple", "fruit", static_cast<float>(4.99), 6, "Red"));
	I.push_back(new dairy("milk", "dairy", static_cast<float>(4.99), 4, 6));
	I.push_back(new dairy("cheese", "dairy", static_cast<float>(3.99), 4, 16));
}

//Void function to print out search itme in the
void search(vector<Inventory*> &I, string itm)
{
	//Vector iterator to search through vector array
	vector<Inventory*>::iterator it; 
	//Searches through the vecor with the iterator to find the item being passed into the function
	for (it = I.begin(); it < I.end(); it++)
	{
		if ((*it)->getName() == itm)//If found prints information about item 
		{
			(*it)->print();
			cout << endl;
			return;
		}
	}
}

//Void function to print out search itme in the
void searchCategory(vector<Inventory*> &I, string itm)
{
	//Vector iterator to search through vector array
	vector<Inventory*>::iterator it;
	//Searches through the vecor with the iterator to find the item being passed into the function
	for (it = I.begin(); it < I.end(); it++)
	{
		if ((*it)->getCategory() == itm)//If found prints information about item 
		{
			(*it)->print();
			cout << endl;
		}
	}

}

void sell(vector<Inventory*> &I, string itm)
{
	vector<Inventory*>::iterator it;
	for (it = I.begin(); it < I.end(); it++)
	{
		if ((*it)->getName() == itm)//Decrements value of the items stock by 1
		{
			(*it)->makeSale();
			cout << endl;
		}
	}
}

void returnProduct(vector<Inventory*> &I, string itm)
{
	vector<Inventory*>::iterator it;
	for (it = I.begin(); it < I.end(); it++)
	{
		if ((*it)->getName() == itm)//Increments value of item in stock if it is present
		{
			(*it)->makeReturn();
			cout << endl;
		}
	}
	
}

void addItem(vector<Inventory*> &I, string itm, string cat, float pri, int q)
{
	I.push_back(new Inventory(itm, cat, static_cast<float>(pri), q));//adds item to vector
}

void updateItem(vector<Inventory*> &I, string itm)
{
	//gives user abilit to reassign details about the item
	string updatedName, updatedColor, trash;
	int updatedQuantity, updatedSize;
	float updatedPrice;
	vector<Inventory*>::iterator it;
	for (it = I.begin(); it < I.end(); it++)
	{
		if ((*it)->getName() == itm)
		{
			// ask for the updated price and store it in a variable
			cout << "Please enter an updated price: ";
			cin >> updatedPrice;
			cout << "Please enter updated Quantity: ";
			cin >> updatedQuantity;
			getline(cin, trash);
			cout << "Please update name: ";
			getline(cin, updatedName);
			
			//uses variables specific to fruit class
			if ((*it)->getCategory() == "fruit") {
				cout << "Please enter the updated color: ";
				cin >> updatedColor;
				delete (*it);
				(*it) = new Fruit(updatedName, "fruit", static_cast<float>(updatedPrice), updatedQuantity, updatedColor);
			}

			//uses variables specific to dairy class
			if ((*it)->getCategory() == "dairy") {
				cout << "Please enter the updated size: ";
				cin >> updatedSize;
				delete (*it);
				(*it) = new dairy(updatedName, "dairy", static_cast<float>(updatedPrice), updatedQuantity, updatedSize);
			}
		}
	}
}

int main()
{
	int choice;
	string item, trash;

	string category;
	float price;
	int quantity;
	vector<Inventory*> Items;
	Load(Items);//loads items hard coded into the vector to be used

	do
	{
		try
		{
			//menu for store
			cout << "*******Welcome to the Fruit and Dairy Shop!*******" << endl;
			cout << "1.Search Items" << endl;
			cout << "2.Sell Items" << endl;
			cout << "3.Return Items" << endl;
			cout << "4.Update Items" << endl;
			cout << "5.Add New Items" << endl;
			cout << "6.Exit" << endl;
			cout << "**************************************************" << endl;

			cin >> choice;

			if (!cin)
				throw logic_error("bad input. reqired a number.");

			switch (choice)
			{
			case 1:
				//Binary search Function
				//Binary Search + String search?
				//LINEAR SEARCH
				cout << "Would you like to search by 1) name or 2) category?" << endl;
				cin >> choice;

				if (!cin)
					throw logic_error("error on input trying to enter a category");

				if (choice == 1)
				{
					//searches by name
					getline(cin, trash);//accounts for switch from int/float to string 
					cout << "Please enter the product you wish to search for: ";		
					getline(cin, item);
					cout << endl;
					search(Items, item);
					cout << endl;
				}

				if (choice == 2)
				{
					//searches by category
					getline(cin, trash);
					cout << "What category would you like to search in?" << endl;
					getline(cin, item);
					cout << endl;
					searchCategory(Items, item);
					cout << endl;
				}
				break;

			case 2:
				//Take away items from hard coded items
				getline(cin, trash);
				cout << "What would you like to sell? ";
				getline(cin, item);
				sell(Items, item);
				
				break;

			case 3:
				//Add amount of items to hard coded items or newly added items
				getline(cin, trash);
				cout << "What would you like to return? ";
				getline(cin, item);
				returnProduct(Items, item);
				break;

			case 4:
				//Update item in inventory using copy constructor
				getline(cin, trash);
				cout << "What would you like to update? ";
				getline(cin, item);
				updateItem(Items, item);
				cout << endl;

				break;

			case 5:
				//Add new Item to the inventory
				getline(cin, trash);
				cout << "What is the name of the item? ";
				getline(cin, item);
				cout << "What is the category of the item? ";
				getline(cin, category);
				cout << "What is the price of the item? ";
				cin >> price;
				cout << "What is the quantity of the item? ";
				cin >> quantity;
				addItem(Items, item, category, price, quantity);
				break;

			case 6:
				//Exists out of the program
				return 0;

				//makes sure number input is between 1-6
			default:
				cout << "Please choose a number between 1-6." << endl;
				break;
			}
		}

		//catches string to properly input
		catch (logic_error le)
		{
			string trash;
			cout << le.what() << endl;
			getline(cin, trash);
			cin.clear();
		}
	} 
	while (choice != 6);
}