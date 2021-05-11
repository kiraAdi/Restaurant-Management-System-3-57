#ifndef ORDER_H
#define ORDER_H
#include "employee.h"

class Order
{
    vector<ItemWithAmount> items;
	vector<Deal> dealOrdered;
public:
    Order();
    int calculateBill();
    void addItemWithAmount(const ItemWithAmount&);
	void addDeal(const Deal&);
	//------------------------------------------------//
	Order(const Order&);
	void setItemsRating(vector<int>);
    Order& operator=( const Order&);
	vector<Deal> getDealsOrdered();
	vector<ItemWithAmount> getItemList();
};

#endif // ORDER_H
