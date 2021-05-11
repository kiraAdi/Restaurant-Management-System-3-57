#include "deal.h"

Deal::Deal()
{

}

Deal::Deal(string n, int p):name(n),price(p){}

Deal::Deal(const Deal& obj)
{
	name=obj.name;
	price=obj.price;
	item_with_amount=obj.item_with_amount;
}

void Deal::addItemWithAmount(const ItemWithAmount& obj)
{
	item_with_amount.emplace_back(obj);
}

bool Deal::operator==(const Deal& obj)
{
	return (name==obj.name);
}

Deal& Deal::operator=(const Deal& obj)
{
	name=obj.name;
	price=obj.price;
	item_with_amount=obj.item_with_amount;
	return *this;
}

string Deal::getItemNames()
{
	string items="";
	int size=item_with_amount.size();
	for(int i=0;i<size;++i)
	{
		items.append(item_with_amount[i].getFoodItem()->getName());
		if(i<size-1)
			items.append(", ");
	}
	return items;
}
