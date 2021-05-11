
#include "itemwithamount.h"

ItemWithAmount::ItemWithAmount(FoodItem* _item,int amount)
{
	this->item=_item;
	quantity=amount;
}

ItemWithAmount::ItemWithAmount(const ItemWithAmount& obj)
{
	item=obj.item;
	quantity=obj.quantity;
}

int ItemWithAmount::getPrice()
{
	return item->getPrice()*quantity;
}

FoodItem* ItemWithAmount::getFoodItem()
{
	return item;
}

ItemWithAmount& ItemWithAmount::operator=(const ItemWithAmount& obj)
{
	item=obj.item;
	quantity=obj.quantity;
	return *this;
}
