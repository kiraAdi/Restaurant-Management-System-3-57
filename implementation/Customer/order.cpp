#include "order.h"
Order::Order()
{
}

Order::Order(const Order& obj)
{
	items=obj.items;
	dealOrdered=obj.dealOrdered;
}

int Order::calculateBill()
{
	int bill=0;
	int count=items.size();
	for(int i=0;i<count;++i)
		bill+=items[i].getPrice();
	return bill;
}

void Order::setItemsRating(vector<int> rate)
{
    int count=items.size();
    for(int i=1;i<count;++i)
       items[i-1].getFoodItem()->rateCook(rate[i-1]);

}

Order& Order::operator=(const Order& myOrder)
{
    items.clear();
    dealOrdered.clear();
   dealOrdered=myOrder.dealOrdered;
    items=myOrder.items;
	return *this;
}

void Order::addItemWithAmount(const ItemWithAmount& obj)
{
    this->items.emplace_back(obj);

}

void Order::addDeal(const Deal& obj)
{
    dealOrdered.emplace_back(obj);
}

vector<ItemWithAmount> Order::getItemList()
{
	return this->items;
}

vector<Deal> Order::getDealsOrdered()
{
	return dealOrdered;
}
