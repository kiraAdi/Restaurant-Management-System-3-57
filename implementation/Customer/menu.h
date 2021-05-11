
#ifndef MENU_H
#define MENU_H
#include "fooditem.h"
#include <vector>
#include <customer.h>
using namespace std;
class Menu
{
	vector<Deal>  dealList;
    vector<FoodItem*> item;
public:
    Menu();
   // void displayMenu();
	vector<FoodItem*>& displayMenu();
	vector<Deal>& getDealList();
};


#endif // MENU_H
