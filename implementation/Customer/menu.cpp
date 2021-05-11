#include "menu.h"

Menu::Menu()
{

}

vector<FoodItem*>& Menu::displayMenu()
{
	return this->item;
}

vector<Deal>& Menu::getDealList()
{
	return dealList;
}
