#ifndef ITEMWITHAMOUNT_H
#define ITEMWITHAMOUNT_H
#include"fooditem.h"
#include <vector>

using namespace std;
class ItemWithAmount
{
private:
   FoodItem* item;//we need only one food item for every instance of ItemWithAmount
    int quantity;
public:

    ItemWithAmount(FoodItem* _item,int amount);
	//-----------------------------------------------//
    ItemWithAmount(const ItemWithAmount&);
	int getPrice();
	FoodItem* getFoodItem();
    ItemWithAmount& operator = (const ItemWithAmount&);
	int getQuantity()
	{
		return quantity;
	}
};

#endif // ITEMWITHAMOUNT_H
